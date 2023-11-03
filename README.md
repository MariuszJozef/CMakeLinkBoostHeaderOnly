# CMakeLists.txt demo of how to link Boost header-only libraries

The purpose of this project is to demonstrate how to write a CMakeLists.txt script to link Boost header-only libraries. Boost needs to be preinstalled on the user's computer and a path to BoostConfig.cmake provided either in 
[./CMakeUtils/FindOrFetch/FindDoNotFetchBoost.cmake](./CMakeUtils/FindOrFetch/FindDoNotFetchBoost.cmake)
(adjust it there if necessary), 
or passed in at the CMake configure step via the flag `-D Boost_DIR=/path/to/BoostConfig.cmake/`. 

The program uses 
```
#include <boost/rational.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
```
to verify that the linked libraries work. While Boost Rational is a header-only library, Boost DateTime can be either a header-only or a static/shared library. Here we link against the header-only library.

## Commands to build and run the program

```
git clone --depth 1 https://github.com/MariuszJozef/CMakeLinkBoostHeaderOnly.git
cd CMakeLinkBoostHeaderOnly
```

### Windows, MSVC compiler

Run in *Developer Command Prompt for VS*

```
cmake --preset NinjaMC-Msvc -D Boost_DIR=/path/to/BoostConfig.cmake/
cmake --build --preset NinjaMC-Msvc --config Debug --target run
cmake --build --preset NinjaMC-Msvc --config Release --target run
cmake --build --preset NinjaMC-Msvc --config RelWithDebInfo --target run
```

### Linux/Mac GNU compiler

```
cmake --preset NinjaMC-Gnu -D Boost_DIR=/path/to/BoostConfig.cmake/
cmake --build --preset NinjaMC-Gnu --config Debug --target run
cmake --build --preset NinjaMC-Gnu --config Release --target run
cmake --build --preset NinjaMC-Gnu --config RelWithDebInfo --target run
```

### Linux/Mac Clang compiler

```
cmake --preset NinjaMC-Clang -D Boost_DIR=/path/to/BoostConfig.cmake/
cmake --build --preset NinjaMC-Clang --config Debug --target run
cmake --build --preset NinjaMC-Clang --config Release --target run
cmake --build --preset NinjaMC-Clang --config RelWithDebInfo --target run
```

Run `cmake --list-presets all` to see a full list of available presets on your platform, they are named according to the forms
- for single-config generators: *generator-compiler-buildType*
- for multi-config generators: *generator-compiler*.


For an example of how in CMakeLists.txt to link static and shared libraries, please see: 
[CMakeLinkBoostStaticShared](https://github.com/MariuszJozef/CMakeLinkBoostStaticShared.git).
