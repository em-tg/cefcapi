#pragma once

#include "cef_base.h"
#include "include/capi/cef_load_handler_capi.h"

struct my_load_handler {
    cef_load_handler_t base;
    struct reference_counter rc;
};

// Full reference counting isn't needed here, since my_load_handler
// could simply have the same lifetime as the other handlers, but
// this is just to demonstrate how you might implement reference counting
// if it were needed

#define REFERENCE_COUNTING_IMPLEMENTATION
#define T struct my_load_handler
#define ID(n) load_handler_ ## n
#include "reference_counting.h"

void CEF_CALLBACK on_load_error(
    cef_load_handler_t *self_in,
    cef_browser_t *browser,
    cef_frame_t *frame,
    cef_errorcode_t errorCode,
    cef_string_t const *errorText,
    cef_string_t const *failedUrl
){
    DEBUG_CALLBACK;
    printf("Failed to load page: %d\n", errorCode);

    cef_string_t fail_url = cef_string_literal("data:text/plain;charset=utf-8,Failed to Load Page");
    frame->load_url(frame, &fail_url);

    browser->base.release(&browser->base);
    frame->base.release(&frame->base);
}

struct my_load_handler *new_load_handler(void){
    struct my_load_handler *ret = load_handler_create_and_initialize_reference_counting();
    if(ret){
        ret->base.on_load_error = &on_load_error;
    }
    return ret;
}

