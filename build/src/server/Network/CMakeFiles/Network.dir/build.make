# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/Maskat/delivery/Tek03/B-CPP-500-NAN-5-1-rtype-noa.leclaire

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/Maskat/delivery/Tek03/B-CPP-500-NAN-5-1-rtype-noa.leclaire/build

# Include any dependencies generated for this target.
include src/server/Network/CMakeFiles/Network.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/server/Network/CMakeFiles/Network.dir/compiler_depend.make

# Include the progress variables for this target.
include src/server/Network/CMakeFiles/Network.dir/progress.make

# Include the compile flags for this target's objects.
include src/server/Network/CMakeFiles/Network.dir/flags.make

src/server/Network/CMakeFiles/Network.dir/network.cpp.o: src/server/Network/CMakeFiles/Network.dir/flags.make
src/server/Network/CMakeFiles/Network.dir/network.cpp.o: ../src/server/Network/network.cpp
src/server/Network/CMakeFiles/Network.dir/network.cpp.o: src/server/Network/CMakeFiles/Network.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/Maskat/delivery/Tek03/B-CPP-500-NAN-5-1-rtype-noa.leclaire/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/server/Network/CMakeFiles/Network.dir/network.cpp.o"
	cd /home/Maskat/delivery/Tek03/B-CPP-500-NAN-5-1-rtype-noa.leclaire/build/src/server/Network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/server/Network/CMakeFiles/Network.dir/network.cpp.o -MF CMakeFiles/Network.dir/network.cpp.o.d -o CMakeFiles/Network.dir/network.cpp.o -c /home/Maskat/delivery/Tek03/B-CPP-500-NAN-5-1-rtype-noa.leclaire/src/server/Network/network.cpp

src/server/Network/CMakeFiles/Network.dir/network.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Network.dir/network.cpp.i"
	cd /home/Maskat/delivery/Tek03/B-CPP-500-NAN-5-1-rtype-noa.leclaire/build/src/server/Network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/Maskat/delivery/Tek03/B-CPP-500-NAN-5-1-rtype-noa.leclaire/src/server/Network/network.cpp > CMakeFiles/Network.dir/network.cpp.i

src/server/Network/CMakeFiles/Network.dir/network.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Network.dir/network.cpp.s"
	cd /home/Maskat/delivery/Tek03/B-CPP-500-NAN-5-1-rtype-noa.leclaire/build/src/server/Network && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/Maskat/delivery/Tek03/B-CPP-500-NAN-5-1-rtype-noa.leclaire/src/server/Network/network.cpp -o CMakeFiles/Network.dir/network.cpp.s

# Object files for target Network
Network_OBJECTS = \
"CMakeFiles/Network.dir/network.cpp.o"

# External object files for target Network
Network_EXTERNAL_OBJECTS =

src/server/Network/libNetwork.a: src/server/Network/CMakeFiles/Network.dir/network.cpp.o
src/server/Network/libNetwork.a: src/server/Network/CMakeFiles/Network.dir/build.make
src/server/Network/libNetwork.a: src/server/Network/CMakeFiles/Network.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/Maskat/delivery/Tek03/B-CPP-500-NAN-5-1-rtype-noa.leclaire/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libNetwork.a"
	cd /home/Maskat/delivery/Tek03/B-CPP-500-NAN-5-1-rtype-noa.leclaire/build/src/server/Network && $(CMAKE_COMMAND) -P CMakeFiles/Network.dir/cmake_clean_target.cmake
	cd /home/Maskat/delivery/Tek03/B-CPP-500-NAN-5-1-rtype-noa.leclaire/build/src/server/Network && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Network.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/server/Network/CMakeFiles/Network.dir/build: src/server/Network/libNetwork.a
.PHONY : src/server/Network/CMakeFiles/Network.dir/build

src/server/Network/CMakeFiles/Network.dir/clean:
	cd /home/Maskat/delivery/Tek03/B-CPP-500-NAN-5-1-rtype-noa.leclaire/build/src/server/Network && $(CMAKE_COMMAND) -P CMakeFiles/Network.dir/cmake_clean.cmake
.PHONY : src/server/Network/CMakeFiles/Network.dir/clean

src/server/Network/CMakeFiles/Network.dir/depend:
	cd /home/Maskat/delivery/Tek03/B-CPP-500-NAN-5-1-rtype-noa.leclaire/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/Maskat/delivery/Tek03/B-CPP-500-NAN-5-1-rtype-noa.leclaire /home/Maskat/delivery/Tek03/B-CPP-500-NAN-5-1-rtype-noa.leclaire/src/server/Network /home/Maskat/delivery/Tek03/B-CPP-500-NAN-5-1-rtype-noa.leclaire/build /home/Maskat/delivery/Tek03/B-CPP-500-NAN-5-1-rtype-noa.leclaire/build/src/server/Network /home/Maskat/delivery/Tek03/B-CPP-500-NAN-5-1-rtype-noa.leclaire/build/src/server/Network/CMakeFiles/Network.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/server/Network/CMakeFiles/Network.dir/depend

