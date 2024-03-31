// CEF C API example
// Project website: https://github.com/cztomczak/cefcapi

#pragma once

#include "cef_base.h"
#include "include/capi/cef_app_capi.h"

// ----------------------------------------------------------------------------
// cef_app_t
// ----------------------------------------------------------------------------

///
// Implement this structure to provide handler implementations. Methods will be
// called by the process and/or thread indicated.
///

void initialize_cef_app(cef_app_t* app) {
    printf("initialize_cef_app\n");
    app->base.size = sizeof(cef_app_t);
    initialize_cef_base_ref_counted((cef_base_ref_counted_t*)app);

    // callbacks (nothing to do)
}
