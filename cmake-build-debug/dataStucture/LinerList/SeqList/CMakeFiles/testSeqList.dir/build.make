# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\S\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\192.7142.39\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\S\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\192.7142.39\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\S\CLionProjects\someDeomsForInterView

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\S\CLionProjects\someDeomsForInterView\cmake-build-debug

# Include any dependencies generated for this target.
include dataStucture/LinerList/SeqList/CMakeFiles/testSeqList.dir/depend.make

# Include the progress variables for this target.
include dataStucture/LinerList/SeqList/CMakeFiles/testSeqList.dir/progress.make

# Include the compile flags for this target's objects.
include dataStucture/LinerList/SeqList/CMakeFiles/testSeqList.dir/flags.make

dataStucture/LinerList/SeqList/CMakeFiles/testSeqList.dir/testSeqList.cpp.obj: dataStucture/LinerList/SeqList/CMakeFiles/testSeqList.dir/flags.make
dataStucture/LinerList/SeqList/CMakeFiles/testSeqList.dir/testSeqList.cpp.obj: ../dataStucture/LinerList/SeqList/testSeqList.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\S\CLionProjects\someDeomsForInterView\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object dataStucture/LinerList/SeqList/CMakeFiles/testSeqList.dir/testSeqList.cpp.obj"
	cd /d C:\Users\S\CLionProjects\someDeomsForInterView\cmake-build-debug\dataStucture\LinerList\SeqList && C:\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\testSeqList.dir\testSeqList.cpp.obj -c C:\Users\S\CLionProjects\someDeomsForInterView\dataStucture\LinerList\SeqList\testSeqList.cpp

dataStucture/LinerList/SeqList/CMakeFiles/testSeqList.dir/testSeqList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testSeqList.dir/testSeqList.cpp.i"
	cd /d C:\Users\S\CLionProjects\someDeomsForInterView\cmake-build-debug\dataStucture\LinerList\SeqList && C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\S\CLionProjects\someDeomsForInterView\dataStucture\LinerList\SeqList\testSeqList.cpp > CMakeFiles\testSeqList.dir\testSeqList.cpp.i

dataStucture/LinerList/SeqList/CMakeFiles/testSeqList.dir/testSeqList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testSeqList.dir/testSeqList.cpp.s"
	cd /d C:\Users\S\CLionProjects\someDeomsForInterView\cmake-build-debug\dataStucture\LinerList\SeqList && C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\S\CLionProjects\someDeomsForInterView\dataStucture\LinerList\SeqList\testSeqList.cpp -o CMakeFiles\testSeqList.dir\testSeqList.cpp.s

# Object files for target testSeqList
testSeqList_OBJECTS = \
"CMakeFiles/testSeqList.dir/testSeqList.cpp.obj"

# External object files for target testSeqList
testSeqList_EXTERNAL_OBJECTS =

dataStucture/LinerList/SeqList/testSeqList.exe: dataStucture/LinerList/SeqList/CMakeFiles/testSeqList.dir/testSeqList.cpp.obj
dataStucture/LinerList/SeqList/testSeqList.exe: dataStucture/LinerList/SeqList/CMakeFiles/testSeqList.dir/build.make
dataStucture/LinerList/SeqList/testSeqList.exe: dataStucture/LinerList/SeqList/CMakeFiles/testSeqList.dir/linklibs.rsp
dataStucture/LinerList/SeqList/testSeqList.exe: dataStucture/LinerList/SeqList/CMakeFiles/testSeqList.dir/objects1.rsp
dataStucture/LinerList/SeqList/testSeqList.exe: dataStucture/LinerList/SeqList/CMakeFiles/testSeqList.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\S\CLionProjects\someDeomsForInterView\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable testSeqList.exe"
	cd /d C:\Users\S\CLionProjects\someDeomsForInterView\cmake-build-debug\dataStucture\LinerList\SeqList && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\testSeqList.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
dataStucture/LinerList/SeqList/CMakeFiles/testSeqList.dir/build: dataStucture/LinerList/SeqList/testSeqList.exe

.PHONY : dataStucture/LinerList/SeqList/CMakeFiles/testSeqList.dir/build

dataStucture/LinerList/SeqList/CMakeFiles/testSeqList.dir/clean:
	cd /d C:\Users\S\CLionProjects\someDeomsForInterView\cmake-build-debug\dataStucture\LinerList\SeqList && $(CMAKE_COMMAND) -P CMakeFiles\testSeqList.dir\cmake_clean.cmake
.PHONY : dataStucture/LinerList/SeqList/CMakeFiles/testSeqList.dir/clean

dataStucture/LinerList/SeqList/CMakeFiles/testSeqList.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\S\CLionProjects\someDeomsForInterView C:\Users\S\CLionProjects\someDeomsForInterView\dataStucture\LinerList\SeqList C:\Users\S\CLionProjects\someDeomsForInterView\cmake-build-debug C:\Users\S\CLionProjects\someDeomsForInterView\cmake-build-debug\dataStucture\LinerList\SeqList C:\Users\S\CLionProjects\someDeomsForInterView\cmake-build-debug\dataStucture\LinerList\SeqList\CMakeFiles\testSeqList.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : dataStucture/LinerList/SeqList/CMakeFiles/testSeqList.dir/depend

