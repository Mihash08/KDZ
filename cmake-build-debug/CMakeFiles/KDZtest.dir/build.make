# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\mihsa\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\212.5284.51\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\mihsa\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\212.5284.51\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\mihsa\CLionProjects\KDZtest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\mihsa\CLionProjects\KDZtest\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\KDZtest.dir\depend.make
# Include the progress variables for this target.
include CMakeFiles\KDZtest.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\KDZtest.dir\flags.make

CMakeFiles\KDZtest.dir\main.cpp.obj: CMakeFiles\KDZtest.dir\flags.make
CMakeFiles\KDZtest.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mihsa\CLionProjects\KDZtest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/KDZtest.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\KDZtest.dir\main.cpp.obj /FdCMakeFiles\KDZtest.dir\ /FS -c C:\Users\mihsa\CLionProjects\KDZtest\main.cpp
<<

CMakeFiles\KDZtest.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/KDZtest.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe > CMakeFiles\KDZtest.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mihsa\CLionProjects\KDZtest\main.cpp
<<

CMakeFiles\KDZtest.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/KDZtest.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\KDZtest.dir\main.cpp.s /c C:\Users\mihsa\CLionProjects\KDZtest\main.cpp
<<

CMakeFiles\KDZtest.dir\sortAlg.cpp.obj: CMakeFiles\KDZtest.dir\flags.make
CMakeFiles\KDZtest.dir\sortAlg.cpp.obj: ..\sortAlg.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\mihsa\CLionProjects\KDZtest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/KDZtest.dir/sortAlg.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\KDZtest.dir\sortAlg.cpp.obj /FdCMakeFiles\KDZtest.dir\ /FS -c C:\Users\mihsa\CLionProjects\KDZtest\sortAlg.cpp
<<

CMakeFiles\KDZtest.dir\sortAlg.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/KDZtest.dir/sortAlg.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe > CMakeFiles\KDZtest.dir\sortAlg.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\mihsa\CLionProjects\KDZtest\sortAlg.cpp
<<

CMakeFiles\KDZtest.dir\sortAlg.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/KDZtest.dir/sortAlg.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\KDZtest.dir\sortAlg.cpp.s /c C:\Users\mihsa\CLionProjects\KDZtest\sortAlg.cpp
<<

# Object files for target KDZtest
KDZtest_OBJECTS = \
"CMakeFiles\KDZtest.dir\main.cpp.obj" \
"CMakeFiles\KDZtest.dir\sortAlg.cpp.obj"

# External object files for target KDZtest
KDZtest_EXTERNAL_OBJECTS =

KDZtest.exe: CMakeFiles\KDZtest.dir\main.cpp.obj
KDZtest.exe: CMakeFiles\KDZtest.dir\sortAlg.cpp.obj
KDZtest.exe: CMakeFiles\KDZtest.dir\build.make
KDZtest.exe: CMakeFiles\KDZtest.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\mihsa\CLionProjects\KDZtest\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable KDZtest.exe"
	C:\Users\mihsa\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\212.5284.51\bin\cmake\win\bin\cmake.exe -E vs_link_exe --intdir=CMakeFiles\KDZtest.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\KDZtest.dir\objects1.rsp @<<
 /out:KDZtest.exe /implib:KDZtest.lib /pdb:C:\Users\mihsa\CLionProjects\KDZtest\cmake-build-debug\KDZtest.pdb /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\KDZtest.dir\build: KDZtest.exe
.PHONY : CMakeFiles\KDZtest.dir\build

CMakeFiles\KDZtest.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\KDZtest.dir\cmake_clean.cmake
.PHONY : CMakeFiles\KDZtest.dir\clean

CMakeFiles\KDZtest.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\mihsa\CLionProjects\KDZtest C:\Users\mihsa\CLionProjects\KDZtest C:\Users\mihsa\CLionProjects\KDZtest\cmake-build-debug C:\Users\mihsa\CLionProjects\KDZtest\cmake-build-debug C:\Users\mihsa\CLionProjects\KDZtest\cmake-build-debug\CMakeFiles\KDZtest.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\KDZtest.dir\depend

