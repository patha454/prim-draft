# prim

[![Build Status](https://dev.azure.com/patha454/Prim/_apis/build/status/patha454.prim?branchName=master)](https://dev.azure.com/patha454/Prim/_build/latest?definitionId=1&branchName=master)

Loader and process imager.

Nothing to see here, yet.

## Building Prim

Prim, or what little scraps of Prim are ready, can be built with CMake.

1. To prepare project files for your build system (MSVC, GNU Make, XCode...) use the following commands or their equivalent on your platform to prepare project files in a folder called `build`, replacing `$PRIM` with the location of Prim's source tree.

```
$ mkdir build
$ cd build
$ cmake $PRIM
```

2. The final command to build the project will depend on which build system you use, and your use case. Typical examples are included below, assuming the active directory contains the project files generated in the previous step.

GNU Make
```
$ make
```

MS Visual Studio
```
$ msbuild Prim.sln [\m]
```
