# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\libsString

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\libsString\cmake-build-debug

# Include any dependencies generated for this target.
include string/CMakeFiles/string.dir/depend.make
# Include the progress variables for this target.
include string/CMakeFiles/string.dir/progress.make

# Include the compile flags for this target's objects.
include string/CMakeFiles/string.dir/flags.make

string/CMakeFiles/string.dir/tasks/string_.c.obj: string/CMakeFiles/string.dir/flags.make
string/CMakeFiles/string.dir/tasks/string_.c.obj: ../string/tasks/string_.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\libsString\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object string/CMakeFiles/string.dir/tasks/string_.c.obj"
	cd /d D:\libsString\cmake-build-debug\string && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\string.dir\tasks\string_.c.obj -c D:\libsString\string\tasks\string_.c

string/CMakeFiles/string.dir/tasks/string_.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/string.dir/tasks/string_.c.i"
	cd /d D:\libsString\cmake-build-debug\string && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\libsString\string\tasks\string_.c > CMakeFiles\string.dir\tasks\string_.c.i

string/CMakeFiles/string.dir/tasks/string_.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/string.dir/tasks/string_.c.s"
	cd /d D:\libsString\cmake-build-debug\string && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\libsString\string\tasks\string_.c -o CMakeFiles\string.dir\tasks\string_.c.s

# Object files for target string
string_OBJECTS = \
"CMakeFiles/string.dir/tasks/string_.c.obj"

# External object files for target string
string_EXTERNAL_OBJECTS =

string/libstring.a: string/CMakeFiles/string.dir/tasks/string_.c.obj
string/libstring.a: string/CMakeFiles/string.dir/build.make
string/libstring.a: string/CMakeFiles/string.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\libsString\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libstring.a"
	cd /d D:\libsString\cmake-build-debug\string && $(CMAKE_COMMAND) -P CMakeFiles\string.dir\cmake_clean_target.cmake
	cd /d D:\libsString\cmake-build-debug\string && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\string.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
string/CMakeFiles/string.dir/build: string/libstring.a
.PHONY : string/CMakeFiles/string.dir/build

string/CMakeFiles/string.dir/clean:
	cd /d D:\libsString\cmake-build-debug\string && $(CMAKE_COMMAND) -P CMakeFiles\string.dir\cmake_clean.cmake
.PHONY : string/CMakeFiles/string.dir/clean

string/CMakeFiles/string.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\libsString D:\libsString\string D:\libsString\cmake-build-debug D:\libsString\cmake-build-debug\string D:\libsString\cmake-build-debug\string\CMakeFiles\string.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : string/CMakeFiles/string.dir/depend
