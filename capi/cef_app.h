// CEF C API example
// Project website: https://github.com/cztomczak/cefcapi

#pragma once

#include "cef_base.h"
#include "include/capi/cef_app_capi.h"
#include "include/capi/cef_browser_process_handler_capi.h"

// ----------------------------------------------------------------------------
// cef_app_t
// ----------------------------------------------------------------------------

struct my_cef_app {
    cef_app_t base;
    cef_browser_process_handler_t process_handler;
};

///
// Implement this structure to provide handler implementations. Methods will be
// called by the process and/or thread indicated.
///

///
/// Return the handler for functionality specific to the browser process. This
/// function is called on multiple threads in the browser process.
///
struct _cef_browser_process_handler_t *CEF_CALLBACK get_browser_process_handler(struct _cef_app_t* self_in){
    return &container_of(self_in, struct my_cef_app, base)->process_handler;
}

///
/// Implement this function to provide app-specific behavior when an already
/// running app is relaunched with the same CefSettings.root_cache_path value.
/// For example, activate an existing app window or create a new app window.
/// |command_line| will be read-only. Do not keep a reference to
/// |command_line| outside of this function. Return true (1) if the relaunch
/// is handled or false (0) for default relaunch behavior. Default behavior
/// will create a new default styled Chrome window.
///
/// To avoid cache corruption only a single app instance is allowed to run for
/// a given CefSettings.root_cache_path value. On relaunch the app checks a
/// process singleton lock and then forwards the new launch arguments to the
/// already running app process before exiting early. Client apps should
/// therefore check the cef_initialize() return value for early exit before
/// proceeding.
///
/// This function will be called on the browser process UI thread.
///
int CEF_CALLBACK on_already_running_app_relaunch(
    struct _cef_browser_process_handler_t* self,
    struct _cef_command_line_t* command_line,
    const cef_string_t* current_directory
){
    printf("TODO: implement on_already_running_app_relaunch\n");
    command_line->base.release(&command_line->base);
    return 1;
}

///
/// Provides an opportunity to view and/or modify command-line arguments
/// before processing by CEF and Chromium. The |process_type| value will be
/// NULL for the browser process. Do not keep a reference to the
/// cef_command_line_t object passed to this function. The
/// cef_settings_t.command_line_args_disabled value can be used to start with
/// an NULL command-line object. Any values specified in CefSettings that
/// equate to command-line arguments will be set before this function is
/// called. Be cautious when using this function to modify command-line
/// arguments for non-browser processes as this may result in undefined
/// behavior including crashes.
///
void CEF_CALLBACK on_before_command_line_processing(
    struct _cef_app_t* self,
    const cef_string_t* process_type,
    struct _cef_command_line_t* command_line
){
    // Workaround for the GPU process crashing on windows for some
    // reason.  Doesn't happen with MinGW either, which is strange.
    // https://github.com/chromiumembedded/cef/issues/3765
    cef_string_t arg = cef_string_literal("use-angle");
    command_line->append_switch(command_line, &arg);
    command_line->base.release(&command_line->base);
}

void initialize_cef_app(struct my_cef_app* app) {
    printf("initialize_cef_app\n");
    app->base.base.size = sizeof *app;
    initialize_fake_reference_counting(&app->base.base);

    app->process_handler.base.size = sizeof app->process_handler;
    initialize_fake_reference_counting(&app->process_handler.base);

    // callbacks

    app->base.get_browser_process_handler = &get_browser_process_handler;
    app->base.on_before_command_line_processing = &on_before_command_line_processing;
    app->process_handler.on_already_running_app_relaunch = &on_already_running_app_relaunch;
}
