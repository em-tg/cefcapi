// CEF C API example
// Project website: https://github.com/cztomczak/cefcapi

#pragma once

#include "cef_base.h"
#include "cef_life_span_handler.h"
#include "include/capi/cef_client_capi.h"

// ----------------------------------------------------------------------------
// struct cef_client_t
// ----------------------------------------------------------------------------

///
// Implement this structure to provide handler implementations.
///

struct my_client {
    cef_client_t base;
    cef_life_span_handler_t life_span_handler;
};


///
// Return the handler for browser life span events.
///
struct _cef_life_span_handler_t* CEF_CALLBACK get_life_span_handler(
        struct _cef_client_t* self) {
    DEBUG_CALLBACK("get_life_span_handler\n");
    // Implemented!
    return &container_of(self, struct my_client, base)->life_span_handler;
}

void initialize_cef_client(struct my_client *client) {
    DEBUG_CALLBACK("initialize_client_handler\n");
    client->base.base.size = sizeof *client;
    initialize_cef_base_ref_counted(&client->base.base);

    initialize_cef_life_span_handler(&client->life_span_handler);

    // callbacks
    client->base.get_life_span_handler = get_life_span_handler;  // Implemented!
}
