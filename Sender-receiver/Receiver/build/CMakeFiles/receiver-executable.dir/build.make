# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ricardo/bosch/Sender-receiver/Receiver

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ricardo/bosch/Sender-receiver/Receiver/build

# Include any dependencies generated for this target.
include CMakeFiles/receiver-executable.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/receiver-executable.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/receiver-executable.dir/flags.make

CMakeFiles/receiver-executable.dir/src/main.c.o: CMakeFiles/receiver-executable.dir/flags.make
CMakeFiles/receiver-executable.dir/src/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ricardo/bosch/Sender-receiver/Receiver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/receiver-executable.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/receiver-executable.dir/src/main.c.o   -c /home/ricardo/bosch/Sender-receiver/Receiver/src/main.c

CMakeFiles/receiver-executable.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/receiver-executable.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ricardo/bosch/Sender-receiver/Receiver/src/main.c > CMakeFiles/receiver-executable.dir/src/main.c.i

CMakeFiles/receiver-executable.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/receiver-executable.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ricardo/bosch/Sender-receiver/Receiver/src/main.c -o CMakeFiles/receiver-executable.dir/src/main.c.s

CMakeFiles/receiver-executable.dir/src/receiver.c.o: CMakeFiles/receiver-executable.dir/flags.make
CMakeFiles/receiver-executable.dir/src/receiver.c.o: ../src/receiver.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ricardo/bosch/Sender-receiver/Receiver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/receiver-executable.dir/src/receiver.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/receiver-executable.dir/src/receiver.c.o   -c /home/ricardo/bosch/Sender-receiver/Receiver/src/receiver.c

CMakeFiles/receiver-executable.dir/src/receiver.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/receiver-executable.dir/src/receiver.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ricardo/bosch/Sender-receiver/Receiver/src/receiver.c > CMakeFiles/receiver-executable.dir/src/receiver.c.i

CMakeFiles/receiver-executable.dir/src/receiver.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/receiver-executable.dir/src/receiver.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ricardo/bosch/Sender-receiver/Receiver/src/receiver.c -o CMakeFiles/receiver-executable.dir/src/receiver.c.s

# Object files for target receiver-executable
receiver__executable_OBJECTS = \
"CMakeFiles/receiver-executable.dir/src/main.c.o" \
"CMakeFiles/receiver-executable.dir/src/receiver.c.o"

# External object files for target receiver-executable
receiver__executable_EXTERNAL_OBJECTS =

receiver-executable: CMakeFiles/receiver-executable.dir/src/main.c.o
receiver-executable: CMakeFiles/receiver-executable.dir/src/receiver.c.o
receiver-executable: CMakeFiles/receiver-executable.dir/build.make
receiver-executable: CMakeFiles/receiver-executable.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ricardo/bosch/Sender-receiver/Receiver/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable receiver-executable"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/receiver-executable.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/receiver-executable.dir/build: receiver-executable

.PHONY : CMakeFiles/receiver-executable.dir/build

CMakeFiles/receiver-executable.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/receiver-executable.dir/cmake_clean.cmake
.PHONY : CMakeFiles/receiver-executable.dir/clean

CMakeFiles/receiver-executable.dir/depend:
	cd /home/ricardo/bosch/Sender-receiver/Receiver/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ricardo/bosch/Sender-receiver/Receiver /home/ricardo/bosch/Sender-receiver/Receiver /home/ricardo/bosch/Sender-receiver/Receiver/build /home/ricardo/bosch/Sender-receiver/Receiver/build /home/ricardo/bosch/Sender-receiver/Receiver/build/CMakeFiles/receiver-executable.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/receiver-executable.dir/depend

