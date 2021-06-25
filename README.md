# SoftLK-tools

This repo hosts the source code for different (currently two) tools that were made to be used with SoftLK-lib.

## SLK_img2pixel (v1.1)

A tool for transforming images into pixel art.

![SLK_img2pixel_preview](screenshots/SLK_img2pixel.png)
![anim](screenshots/crate.gif)

## SLK_make (WIP)

A build system based on the one used by golgotha (which was cancelled and released into the public domain).
Warning: SLK_make is still very much experimental, it will not work for any operating system except linux.

# Building from source

* First, clone this repository: ``https://github.com/Captain4LK/SoftLK-tools.git``

## Dependencies

In general, I try to keep the amount of external dependencies as low as possible, but some are still needed, as listed below.

* SLK_img2pixel:
   * on Linux ONE of the following is needed for creating file dialogs: zenity, matedialog, qarma, kdialog, Xdialog, python2/tkinter or dialog
   * libSLK.a, as explained below 

* SLK_make
   * None

### SoftLK-lib

Most of the tools in this repository need SoftLK-lib. Since SoftLK-lib is a separate project the source has not been included in this repository. Separate install instructions can be found in its directory: [SoftLK-lib](https://github.com/Captain4LK/SoftLK-lib). All of the makefiles assume it to be installed globally, so I recommend running ``sudo make install`` for installing it on your system.

Here is a list of all makefile targets for building SoftLK-lib:

* libSLK.a (``make backend_sdl2`` or ``make backend_sdl2_gl``)
* global install (``sudo make install``, Unix only)

## Using makefiles

* cd into the directory of the tool you want to build
* cd into its bin/unix directory
* ...and build it: ``make``
* The binary can be found at the top level of the repo in the bin directory

## Using SLK_make

* build SLK_make (a shell fill can be found in the SLK_make/bin/unix directory)
* cd into the bin directory 
* run ``./SLK_make -v opt -no_syms -compiler gcc -extension .c [NAME OF TOOL]``

# Download 

* SLK_img2pixel: [itch.io](https://captain4lk.itch.io/slk-img2pixel)

# License

All code in this repository (except the 'external' directory containing source code not by me) is released into the public domain (CC0), see COPYING for more info.

# Planned tools / ideas

* tile map editor
* pixel art editor

# Third party libraries

* [tinyfiledialogs](https://sourceforge.net/projects/tinyfiledialogs/), zlib
* [cute_files](https://github.com/RandyGaul/cute_headers), zlib/unlicense
* [cute_path](https://github.com/RandyGaul/cute_headers), zlib/unlicense
* [stb_image](https://github.com/nothings/stb), mit/unlicense
* [gifenc](https://github.com/lecram/gifenc), public domain
* [gifdec](https://github.com/lecram/gifdec), public domain
* [fopen_utf8](https://github.com/Photosounder/fopen_utf8/), only for windows builds, public domain
