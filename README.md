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
    - Binary: `cef_binary_123.0.7+g6a21509+chromium-123.0.6312.46_windows64_beta.tar.bz2`
    - Compilers: mingw-w64 gcc 11.2.0 and Visual Studio 2022 on Windows 10 64-bit
- Linux:
    - Binary: `cef_binary_123.0.7+g6a21509+chromium-123.0.6312.46_linux64_beta.tar.bz2`
    - Compiler: Linux: gcc 9.4.0 on Ubuntu 20.04 64-bit

## Getting started

1. Download "Standard Distribution" binaries from Spotify
   Automated Builds for the supported CEF version mentioned
   in the Compatibility section above:
   https://cef-builds.spotifycdn.com/index.html
2. Put the cef*.tar.bz file into third_party
3. On Linux run "make run" (example uses GTK+ 3)
4. On Windows run "build_msvc.bat" or "build_gcc.bat" to build with MSVC or MinGW, respectively
    - 7zip will need to be installed, or you will need to extract cef manually

## Support development

If you would like to support general CEF C API development efforts
by making a donation please click the Paypal Donate button:

<a href='https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=YHSHWR5JM4FN4'>
<img src='https://raw.githubusercontent.com/wiki/cztomczak/cefpython/images/donate.gif' />
</a><br><br>

