# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\develop\search_engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\develop\search_engine\build\Desktop_Qt_6_4_3_MinGW_64_bit-Debug

# Include any dependencies generated for this target.
include src/CMakeFiles/search_engine.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/search_engine.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/search_engine.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/search_engine.dir/flags.make

src/CMakeFiles/search_engine.dir/main.cpp.obj: src/CMakeFiles/search_engine.dir/flags.make
src/CMakeFiles/search_engine.dir/main.cpp.obj: src/CMakeFiles/search_engine.dir/includes_CXX.rsp
src/CMakeFiles/search_engine.dir/main.cpp.obj: C:/develop/search_engine/src/main.cpp
src/CMakeFiles/search_engine.dir/main.cpp.obj: src/CMakeFiles/search_engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\develop\search_engine\build\Desktop_Qt_6_4_3_MinGW_64_bit-Debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/search_engine.dir/main.cpp.obj"
	cd /d C:\develop\search_engine\build\Desktop_Qt_6_4_3_MinGW_64_bit-Debug\src && C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/search_engine.dir/main.cpp.obj -MF CMakeFiles\search_engine.dir\main.cpp.obj.d -o CMakeFiles\search_engine.dir\main.cpp.obj -c C:\develop\search_engine\src\main.cpp

src/CMakeFiles/search_engine.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/search_engine.dir/main.cpp.i"
	cd /d C:\develop\search_engine\build\Desktop_Qt_6_4_3_MinGW_64_bit-Debug\src && C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\develop\search_engine\src\main.cpp > CMakeFiles\search_engine.dir\main.cpp.i

src/CMakeFiles/search_engine.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/search_engine.dir/main.cpp.s"
	cd /d C:\develop\search_engine\build\Desktop_Qt_6_4_3_MinGW_64_bit-Debug\src && C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\develop\search_engine\src\main.cpp -o CMakeFiles\search_engine.dir\main.cpp.s

src/CMakeFiles/search_engine.dir/converterjson.cpp.obj: src/CMakeFiles/search_engine.dir/flags.make
src/CMakeFiles/search_engine.dir/converterjson.cpp.obj: src/CMakeFiles/search_engine.dir/includes_CXX.rsp
src/CMakeFiles/search_engine.dir/converterjson.cpp.obj: C:/develop/search_engine/src/converterjson.cpp
src/CMakeFiles/search_engine.dir/converterjson.cpp.obj: src/CMakeFiles/search_engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\develop\search_engine\build\Desktop_Qt_6_4_3_MinGW_64_bit-Debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/search_engine.dir/converterjson.cpp.obj"
	cd /d C:\develop\search_engine\build\Desktop_Qt_6_4_3_MinGW_64_bit-Debug\src && C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/search_engine.dir/converterjson.cpp.obj -MF CMakeFiles\search_engine.dir\converterjson.cpp.obj.d -o CMakeFiles\search_engine.dir\converterjson.cpp.obj -c C:\develop\search_engine\src\converterjson.cpp

src/CMakeFiles/search_engine.dir/converterjson.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/search_engine.dir/converterjson.cpp.i"
	cd /d C:\develop\search_engine\build\Desktop_Qt_6_4_3_MinGW_64_bit-Debug\src && C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\develop\search_engine\src\converterjson.cpp > CMakeFiles\search_engine.dir\converterjson.cpp.i

src/CMakeFiles/search_engine.dir/converterjson.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/search_engine.dir/converterjson.cpp.s"
	cd /d C:\develop\search_engine\build\Desktop_Qt_6_4_3_MinGW_64_bit-Debug\src && C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\develop\search_engine\src\converterjson.cpp -o CMakeFiles\search_engine.dir\converterjson.cpp.s

src/CMakeFiles/search_engine.dir/invertedindex.cpp.obj: src/CMakeFiles/search_engine.dir/flags.make
src/CMakeFiles/search_engine.dir/invertedindex.cpp.obj: src/CMakeFiles/search_engine.dir/includes_CXX.rsp
src/CMakeFiles/search_engine.dir/invertedindex.cpp.obj: C:/develop/search_engine/src/invertedindex.cpp
src/CMakeFiles/search_engine.dir/invertedindex.cpp.obj: src/CMakeFiles/search_engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\develop\search_engine\build\Desktop_Qt_6_4_3_MinGW_64_bit-Debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/search_engine.dir/invertedindex.cpp.obj"
	cd /d C:\develop\search_engine\build\Desktop_Qt_6_4_3_MinGW_64_bit-Debug\src && C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/search_engine.dir/invertedindex.cpp.obj -MF CMakeFiles\search_engine.dir\invertedindex.cpp.obj.d -o CMakeFiles\search_engine.dir\invertedindex.cpp.obj -c C:\develop\search_engine\src\invertedindex.cpp

src/CMakeFiles/search_engine.dir/invertedindex.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/search_engine.dir/invertedindex.cpp.i"
	cd /d C:\develop\search_engine\build\Desktop_Qt_6_4_3_MinGW_64_bit-Debug\src && C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\develop\search_engine\src\invertedindex.cpp > CMakeFiles\search_engine.dir\invertedindex.cpp.i

src/CMakeFiles/search_engine.dir/invertedindex.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/search_engine.dir/invertedindex.cpp.s"
	cd /d C:\develop\search_engine\build\Desktop_Qt_6_4_3_MinGW_64_bit-Debug\src && C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\develop\search_engine\src\invertedindex.cpp -o CMakeFiles\search_engine.dir\invertedindex.cpp.s

src/CMakeFiles/search_engine.dir/invertedIndexTest.cpp.obj: src/CMakeFiles/search_engine.dir/flags.make
src/CMakeFiles/search_engine.dir/invertedIndexTest.cpp.obj: src/CMakeFiles/search_engine.dir/includes_CXX.rsp
src/CMakeFiles/search_engine.dir/invertedIndexTest.cpp.obj: C:/develop/search_engine/src/invertedIndexTest.cpp
src/CMakeFiles/search_engine.dir/invertedIndexTest.cpp.obj: src/CMakeFiles/search_engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\develop\search_engine\build\Desktop_Qt_6_4_3_MinGW_64_bit-Debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/search_engine.dir/invertedIndexTest.cpp.obj"
	cd /d C:\develop\search_engine\build\Desktop_Qt_6_4_3_MinGW_64_bit-Debug\src && C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/search_engine.dir/invertedIndexTest.cpp.obj -MF CMakeFiles\search_engine.dir\invertedIndexTest.cpp.obj.d -o CMakeFiles\search_engine.dir\invertedIndexTest.cpp.obj -c C:\develop\search_engine\src\invertedIndexTest.cpp

src/CMakeFiles/search_engine.dir/invertedIndexTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/search_engine.dir/invertedIndexTest.cpp.i"
	cd /d C:\develop\search_engine\build\Desktop_Qt_6_4_3_MinGW_64_bit-Debug\src && C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\develop\search_engine\src\invertedIndexTest.cpp > CMakeFiles\search_engine.dir\invertedIndexTest.cpp.i

src/CMakeFiles/search_engine.dir/invertedIndexTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/search_engine.dir/invertedIndexTest.cpp.s"
	cd /d C:\develop\search_engine\build\Desktop_Qt_6_4_3_MinGW_64_bit-Debug\src && C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\develop\search_engine\src\invertedIndexTest.cpp -o CMakeFiles\search_engine.dir\invertedIndexTest.cpp.s

src/CMakeFiles/search_engine.dir/searchserver.cpp.obj: src/CMakeFiles/search_engine.dir/flags.make
src/CMakeFiles/search_engine.dir/searchserver.cpp.obj: src/CMakeFiles/search_engine.dir/includes_CXX.rsp
src/CMakeFiles/search_engine.dir/searchserver.cpp.obj: C:/develop/search_engine/src/searchserver.cpp
src/CMakeFiles/search_engine.dir/searchserver.cpp.obj: src/CMakeFiles/search_engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\develop\search_engine\build\Desktop_Qt_6_4_3_MinGW_64_bit-Debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/search_engine.dir/searchserver.cpp.obj"
	cd /d C:\develop\search_engine\build\Desktop_Qt_6_4_3_MinGW_64_bit-Debug\src && C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/search_engine.dir/searchserver.cpp.obj -MF CMakeFiles\search_engine.dir\searchserver.cpp.obj.d -o CMakeFiles\search_engine.dir\searchserver.cpp.obj -c C:\develop\search_engine\src\searchserver.cpp

src/CMakeFiles/search_engine.dir/searchserver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/search_engine.dir/searchserver.cpp.i"
	cd /d C:\develop\search_engine\build\Desktop_Qt_6_4_3_MinGW_64_bit-Debug\src && C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\develop\search_engine\src\searchserver.cpp > CMakeFiles\search_engine.dir\searchserver.cpp.i

src/CMakeFiles/search_engine.dir/searchserver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/search_engine.dir/searchserver.cpp.s"
	cd /d C:\develop\search_engine\build\Desktop_Qt_6_4_3_MinGW_64_bit-Debug\src && C:\Qt\Tools\mingw1120_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\develop\search_engine\src\searchserver.cpp -o CMakeFiles\search_engine.dir\searchserver.cpp.s

# Object files for target search_engine
search_engine_OBJECTS = \
"CMakeFiles/search_engine.dir/main.cpp.obj" \
"CMakeFiles/search_engine.dir/converterjson.cpp.obj" \
"CMakeFiles/search_engine.dir/invertedindex.cpp.obj" \
"CMakeFiles/search_engine.dir/invertedIndexTest.cpp.obj" \
"CMakeFiles/search_engine.dir/searchserver.cpp.obj"

# External object files for target search_engine
search_engine_EXTERNAL_OBJECTS =

src/search_engine.exe: src/CMakeFiles/search_engine.dir/main.cpp.obj
src/search_engine.exe: src/CMakeFiles/search_engine.dir/converterjson.cpp.obj
src/search_engine.exe: src/CMakeFiles/search_engine.dir/invertedindex.cpp.obj
src/search_engine.exe: src/CMakeFiles/search_engine.dir/invertedIndexTest.cpp.obj
src/search_engine.exe: src/CMakeFiles/search_engine.dir/searchserver.cpp.obj
src/search_engine.exe: src/CMakeFiles/search_engine.dir/build.make
src/search_engine.exe: lib/libgtest_main.a
src/search_engine.exe: lib/libgtest.a
src/search_engine.exe: src/CMakeFiles/search_engine.dir/linkLibs.rsp
src/search_engine.exe: src/CMakeFiles/search_engine.dir/objects1.rsp
src/search_engine.exe: src/CMakeFiles/search_engine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\develop\search_engine\build\Desktop_Qt_6_4_3_MinGW_64_bit-Debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable search_engine.exe"
	cd /d C:\develop\search_engine\build\Desktop_Qt_6_4_3_MinGW_64_bit-Debug\src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\search_engine.dir\link.txt --verbose=$(VERBOSE)
	cd /d C:\develop\search_engine\build\Desktop_Qt_6_4_3_MinGW_64_bit-Debug\src && "C:\Program Files\CMake\bin\cmake.exe" -D TEST_TARGET=search_engine -D TEST_EXECUTABLE=C:/develop/search_engine/build/Desktop_Qt_6_4_3_MinGW_64_bit-Debug/src/search_engine.exe -D TEST_EXECUTOR= -D TEST_WORKING_DIR=C:/develop/search_engine/build/Desktop_Qt_6_4_3_MinGW_64_bit-Debug/src -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_FILTER= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=search_engine_TESTS -D CTEST_FILE=C:/develop/search_engine/build/Desktop_Qt_6_4_3_MinGW_64_bit-Debug/src/search_engine[1]_tests.cmake -D TEST_DISCOVERY_TIMEOUT=5 -D TEST_XML_OUTPUT_DIR= -P "C:/Program Files/CMake/share/cmake-3.28/Modules/GoogleTestAddTests.cmake"

# Rule to build all files generated by this target.
src/CMakeFiles/search_engine.dir/build: src/search_engine.exe
.PHONY : src/CMakeFiles/search_engine.dir/build

src/CMakeFiles/search_engine.dir/clean:
	cd /d C:\develop\search_engine\build\Desktop_Qt_6_4_3_MinGW_64_bit-Debug\src && $(CMAKE_COMMAND) -P CMakeFiles\search_engine.dir\cmake_clean.cmake
.PHONY : src/CMakeFiles/search_engine.dir/clean

src/CMakeFiles/search_engine.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\develop\search_engine C:\develop\search_engine\src C:\develop\search_engine\build\Desktop_Qt_6_4_3_MinGW_64_bit-Debug C:\develop\search_engine\build\Desktop_Qt_6_4_3_MinGW_64_bit-Debug\src C:\develop\search_engine\build\Desktop_Qt_6_4_3_MinGW_64_bit-Debug\src\CMakeFiles\search_engine.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/CMakeFiles/search_engine.dir/depend

