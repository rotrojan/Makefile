# Makefile
A cool and transposable Makefile for C++ projects.
![](https://github.com/rotrojan/Makefile/blob/main/demo.gif)
## Features
- Cool and colorfull display.
- A fancy progress bar with the (up to date) number of files left to compile.
- The possibility to add debug flags (`-g3` and/or `-fsanitize=adress`) by setting the variables `DEBUG` and `SANITIZE` to 1.
- The debug flags persist untill `DEBUG` and/or `SANITIZE` are set back to 0 (handy when muscle memory makes you type `make` while focused on debugging).

### To do:
- A C-ish version.
- Support for static libraries.

Any suggestions and PR will be welcome.

A special thank to [@riblanc](http://www.gitlab.com/riblanc) for the idea (and implementation) of the debug variables and to [@tmatis](https://www.github.com/tmatis) for his inspiring 42Make. 😉 
