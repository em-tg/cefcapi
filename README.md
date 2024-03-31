# CEF C API (cefcapi)

A simple example on how to use the C API in [Chromium Embedded
Framework](https://bitbucket.org/chromiumembedded/cef) created by
[Czarek Tomczak](https://www.linkedin.com/in/czarektomczak/).
Example creates a window, embeds a browser inside that window
and loads Google website. Shows how to implement dummy reference
counting and CEF structures with callbacks to implement CEF handlers
like `cef_app_t`, `cef_client_t` and `cef_life_span_handler_t`.
To understand and implement real reference counting see the
[UsingTheCAPI](https://bitbucket.org/chromiumembedded/cef/wiki/UsingTheCAPI.md)
wiki page in upstream CEF project.

Table of contents:
* [Examples](#examples)
* [Compatibility](#compatibility)
* [Getting started](#getting-started)
* [Support development](#support-development)
* [Updating CEF version](#updating-cef-version)


## Examples

- Windows: see [main_win.c](examples/main_win.c)
- Linux: see [main_linux.c](examples/main_linux.c)
- Mac: not available yet ([Issue #15](../../issues/15))

## Compatibility

Tested configurations:
- Windows:
    - Binary: `cef_binary_3.3202.1692.g18a939d_windows32.tar.bz2`
    - Compilers: mingw-gcc 5.3.0 and TDM-gcc 5.1.0 on Windows 7 64-bit
- Linux:
    - Binary: `cef_binary_123.0.7+g6a21509+chromium-123.0.6312.46_linux64_beta.tar.bz2`
    - Compiler: Linux: gcc 9.4.0 on Ubuntu 20.04 64-bit

## Getting started

1. Download "Standard Distribution" binaries from Spotify
   Automated Builds for the supported CEF version mentioned
   in the Compatibility section above:
   http://opensource.spotify.com/cefbuilds/index.html
2. Put the cef*.tar.bz file into third_party
3. On Linux run "make run" (example using GTK+ 3)
4. On Windows run "win_deps.bat" followed by "build.bat"
    - win_deps.bat requires 7zip

## Support development

If you would like to support general CEF C API development efforts
by making a donation please click the Paypal Donate button:

<a href='https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=YHSHWR5JM4FN4'>
<img src='https://raw.githubusercontent.com/wiki/cztomczak/cefpython/images/donate.gif' />
</a><br><br>

