// CEF C API example
// Project website: https://github.com/cztomczak/cefcapi

#pragma once

#include "cef_base.h"
#include "cef_life_span_handler.h"
#include "include/capi/cef_client_capi.h"

extern cef_life_span_handler_t g_life_span_handler;


// ----------------------------------------------------------------------------
// struct cef_client_t
// ----------------------------------------------------------------------------

///
// Implement this structure to provide handler implementations.
///

///
// Return the handler for browser life span events.
///
struct _cef_life_span_handler_t* CEF_CALLBACK get_life_span_handler(
        struct _cef_client_t* self) {
    DEBUG_CALLBACK("get_life_span_handler\n");
    // Implemented!
    return &g_life_span_handler;
}

void initialize_cef_client(cef_client_t* client) {
    DEBUG_CALLBACK("initialize_client_handler\n");
    client->base.size = sizeof *client;
    initialize_cef_base_ref_counted(&client->base);
    // callbacks
    client->get_life_span_handler = get_life_span_handler;  // Implemented!
}
