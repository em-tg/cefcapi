#ifndef REFERENCE_COUNTING_H
#define REFERENCE_COUNTING_H
    struct reference_counter {
        _Atomic int count;
    };
#endif

#if defined(T) && defined(ID)

    T *ID(create_and_initialize_reference_counting)(void);

    #ifdef REFERENCE_COUNTING_IMPLEMENTATION
        #ifndef BASE_NAME
        #define BASE_NAME base.base
        #endif

        #ifndef RC_NAME
        #define RC_NAME rc
        #endif

        #ifndef ON_DESTROY
        #define ON_DESTROY(...) ((void)0)
        #endif

        static void CEF_CALLBACK ID(add_ref)(cef_base_ref_counted_t *self_in){
            if(DEBUG_REFERENCE_COUNTING) printf("%p +\n", (void *)self_in);
            struct reference_counter *rc = &container_of(self_in, T, BASE_NAME)->RC_NAME;
            rc->count++;
        }

        static int CEF_CALLBACK ID(release)(cef_base_ref_counted_t *self_in){
            if(DEBUG_REFERENCE_COUNTING) printf("%p -\n", (void *)self_in);
            T *self = container_of(self_in, T, BASE_NAME);
            int new_value = --self->RC_NAME.count;
            if(new_value == 0){
                ON_DESTROY(self);
                free(self);
            }
            return new_value == 0;
        }

        static int CEF_CALLBACK ID(has_one_ref)(cef_base_ref_counted_t *self_in){
            struct reference_counter *rc = &container_of(self_in, T, BASE_NAME)->RC_NAME;
            return rc->count == 1;
        }

        static int CEF_CALLBACK ID(has_at_least_one_ref)(cef_base_ref_counted_t *self_in){
            struct reference_counter *rc = &container_of(self_in, T, BASE_NAME)->RC_NAME;
            return rc->count >= 1;
        }

        T *ID(create_and_initialize_reference_counting)(void){
            T *self = malloc(sizeof *self);
            if(self){
                *self = (T){
                    .BASE_NAME = {
                        .size = sizeof *self,
                        .add_ref = &ID(add_ref),
                        .release = &ID(release),
                        .has_one_ref = &ID(has_one_ref),
                        .has_at_least_one_ref = &ID(has_at_least_one_ref)
                    },
                    .RC_NAME = {
                        .count = 1
                    }
                };
            }
            return self;
        }
        #undef BASE_NAME
        #undef RC_NAME
        #undef ON_DESTROY
    #endif
    #undef T
    #undef ID
#endif
