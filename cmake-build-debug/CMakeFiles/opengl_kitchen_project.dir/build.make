# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /snap/clion/163/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/163/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/scar/Documents/PJ/UFAL/CG/opengl-kitchen-project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/scar/Documents/PJ/UFAL/CG/opengl-kitchen-project/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/opengl_kitchen_project.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/opengl_kitchen_project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/opengl_kitchen_project.dir/flags.make

CMakeFiles/opengl_kitchen_project.dir/main.cpp.o: CMakeFiles/opengl_kitchen_project.dir/flags.make
CMakeFiles/opengl_kitchen_project.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scar/Documents/PJ/UFAL/CG/opengl-kitchen-project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/opengl_kitchen_project.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opengl_kitchen_project.dir/main.cpp.o -c /home/scar/Documents/PJ/UFAL/CG/opengl-kitchen-project/main.cpp

CMakeFiles/opengl_kitchen_project.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opengl_kitchen_project.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scar/Documents/PJ/UFAL/CG/opengl-kitchen-project/main.cpp > CMakeFiles/opengl_kitchen_project.dir/main.cpp.i

CMakeFiles/opengl_kitchen_project.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opengl_kitchen_project.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scar/Documents/PJ/UFAL/CG/opengl-kitchen-project/main.cpp -o CMakeFiles/opengl_kitchen_project.dir/main.cpp.s

CMakeFiles/opengl_kitchen_project.dir/lib/Camera.cpp.o: CMakeFiles/opengl_kitchen_project.dir/flags.make
CMakeFiles/opengl_kitchen_project.dir/lib/Camera.cpp.o: ../lib/Camera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/scar/Documents/PJ/UFAL/CG/opengl-kitchen-project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/opengl_kitchen_project.dir/lib/Camera.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opengl_kitchen_project.dir/lib/Camera.cpp.o -c /home/scar/Documents/PJ/UFAL/CG/opengl-kitchen-project/lib/Camera.cpp

CMakeFiles/opengl_kitchen_project.dir/lib/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opengl_kitchen_project.dir/lib/Camera.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/scar/Documents/PJ/UFAL/CG/opengl-kitchen-project/lib/Camera.cpp > CMakeFiles/opengl_kitchen_project.dir/lib/Camera.cpp.i

CMakeFiles/opengl_kitchen_project.dir/lib/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opengl_kitchen_project.dir/lib/Camera.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/scar/Documents/PJ/UFAL/CG/opengl-kitchen-project/lib/Camera.cpp -o CMakeFiles/opengl_kitchen_project.dir/lib/Camera.cpp.s

# Object files for target opengl_kitchen_project
opengl_kitchen_project_OBJECTS = \
"CMakeFiles/opengl_kitchen_project.dir/main.cpp.o" \
"CMakeFiles/opengl_kitchen_project.dir/lib/Camera.cpp.o"

# External object files for target opengl_kitchen_project
opengl_kitchen_project_EXTERNAL_OBJECTS =

opengl_kitchen_project: CMakeFiles/opengl_kitchen_project.dir/main.cpp.o
opengl_kitchen_project: CMakeFiles/opengl_kitchen_project.dir/lib/Camera.cpp.o
opengl_kitchen_project: CMakeFiles/opengl_kitchen_project.dir/build.make
opengl_kitchen_project: CMakeFiles/opengl_kitchen_project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/scar/Documents/PJ/UFAL/CG/opengl-kitchen-project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable opengl_kitchen_project"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/opengl_kitchen_project.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/opengl_kitchen_project.dir/build: opengl_kitchen_project
.PHONY : CMakeFiles/opengl_kitchen_project.dir/build

CMakeFiles/opengl_kitchen_project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/opengl_kitchen_project.dir/cmake_clean.cmake
.PHONY : CMakeFiles/opengl_kitchen_project.dir/clean

CMakeFiles/opengl_kitchen_project.dir/depend:
	cd /home/scar/Documents/PJ/UFAL/CG/opengl-kitchen-project/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/scar/Documents/PJ/UFAL/CG/opengl-kitchen-project /home/scar/Documents/PJ/UFAL/CG/opengl-kitchen-project /home/scar/Documents/PJ/UFAL/CG/opengl-kitchen-project/cmake-build-debug /home/scar/Documents/PJ/UFAL/CG/opengl-kitchen-project/cmake-build-debug /home/scar/Documents/PJ/UFAL/CG/opengl-kitchen-project/cmake-build-debug/CMakeFiles/opengl_kitchen_project.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/opengl_kitchen_project.dir/depend
