R-Type Game              {#mainpage}
====

R-Type is a horizontally scrolling shooter arcade video game developed and released by Irem in 1987 and the first game in the R-Type series. The player controls a star ship, the R-9 "Arrowhead", in its efforts to destroy the Bydo, a powerful alien race bent on wiping out all of mankind.

![image](https://user-images.githubusercontent.com/72009611/196052229-109475d4-6290-4686-a0b1-7ecf660cd6e1.png)


## Building

### Command Line (via CMake)

Confirmation badge for Build and Test:

[![CMake](https://github.com/EpitechPromo2025/B-CPP-500-NAN-5-1-rtype-noa.leclaire/actions/workflows/build_and_test.yaml/badge.svg)](https://github.com/EpitechPromo2025/B-CPP-500-NAN-5-1-rtype-noa.leclaire/actions/workflows/build_and_test.yaml)

Required tools:
- CMake 3.17 (minimum)

on Linux:
```sh
# Create the build directory and install all tools
./setup_conan.sh


# Configure the project
cmake .. -G 'Unix Makefiles' -DCMAKE_BUILD_TYPE=Release

# Build the executable and libraries
cmake --build .

# Return to previous directory
cd -
```

on Windows:
```sh
# Create the build directory
mkdir build && cd build

# Configure the project
cmake .. -G 'Visual Studio 17 2022' -DCMAKE_BUILD_TYPE=Release

# Build the executable and libraries
cmake --build .

# Return to previous directory
cd -
```


====

## Professional Documentation

Required tools:
- Doxygen 1.9.5 (minimum)

```sh
#build the documentation
doxygen doxyfile

#open the documentation
cd docs/html/index.html
```
