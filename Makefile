# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_SOURCE_DIR = /home/ldeletang/Année2/SDLInterface

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ldeletang/Année2/SDLInterface

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/ldeletang/Année2/SDLInterface/CMakeFiles /home/ldeletang/Année2/SDLInterface//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/ldeletang/Année2/SDLInterface/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named doc

# Build rule for target.
doc: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 doc
.PHONY : doc

# fast build rule for target.
doc/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/doc.dir/build.make CMakeFiles/doc.dir/build
.PHONY : doc/fast

#=============================================================================
# Target rules for targets named SDLInterface

# Build rule for target.
SDLInterface: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 SDLInterface
.PHONY : SDLInterface

# fast build rule for target.
SDLInterface/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/SDLInterface.dir/build.make CMakeFiles/SDLInterface.dir/build
.PHONY : SDLInterface/fast

src/Button.o: src/Button.cpp.o
.PHONY : src/Button.o

# target to build an object file
src/Button.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/SDLInterface.dir/build.make CMakeFiles/SDLInterface.dir/src/Button.cpp.o
.PHONY : src/Button.cpp.o

src/Button.i: src/Button.cpp.i
.PHONY : src/Button.i

# target to preprocess a source file
src/Button.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/SDLInterface.dir/build.make CMakeFiles/SDLInterface.dir/src/Button.cpp.i
.PHONY : src/Button.cpp.i

src/Button.s: src/Button.cpp.s
.PHONY : src/Button.s

# target to generate assembly for a file
src/Button.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/SDLInterface.dir/build.make CMakeFiles/SDLInterface.dir/src/Button.cpp.s
.PHONY : src/Button.cpp.s

src/MyComponent.o: src/MyComponent.cpp.o
.PHONY : src/MyComponent.o

# target to build an object file
src/MyComponent.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/SDLInterface.dir/build.make CMakeFiles/SDLInterface.dir/src/MyComponent.cpp.o
.PHONY : src/MyComponent.cpp.o

src/MyComponent.i: src/MyComponent.cpp.i
.PHONY : src/MyComponent.i

# target to preprocess a source file
src/MyComponent.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/SDLInterface.dir/build.make CMakeFiles/SDLInterface.dir/src/MyComponent.cpp.i
.PHONY : src/MyComponent.cpp.i

src/MyComponent.s: src/MyComponent.cpp.s
.PHONY : src/MyComponent.s

# target to generate assembly for a file
src/MyComponent.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/SDLInterface.dir/build.make CMakeFiles/SDLInterface.dir/src/MyComponent.cpp.s
.PHONY : src/MyComponent.cpp.s

src/MyComponent2.o: src/MyComponent2.cpp.o
.PHONY : src/MyComponent2.o

# target to build an object file
src/MyComponent2.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/SDLInterface.dir/build.make CMakeFiles/SDLInterface.dir/src/MyComponent2.cpp.o
.PHONY : src/MyComponent2.cpp.o

src/MyComponent2.i: src/MyComponent2.cpp.i
.PHONY : src/MyComponent2.i

# target to preprocess a source file
src/MyComponent2.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/SDLInterface.dir/build.make CMakeFiles/SDLInterface.dir/src/MyComponent2.cpp.i
.PHONY : src/MyComponent2.cpp.i

src/MyComponent2.s: src/MyComponent2.cpp.s
.PHONY : src/MyComponent2.s

# target to generate assembly for a file
src/MyComponent2.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/SDLInterface.dir/build.make CMakeFiles/SDLInterface.dir/src/MyComponent2.cpp.s
.PHONY : src/MyComponent2.cpp.s

src/SDLApp.o: src/SDLApp.cpp.o
.PHONY : src/SDLApp.o

# target to build an object file
src/SDLApp.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/SDLInterface.dir/build.make CMakeFiles/SDLInterface.dir/src/SDLApp.cpp.o
.PHONY : src/SDLApp.cpp.o

src/SDLApp.i: src/SDLApp.cpp.i
.PHONY : src/SDLApp.i

# target to preprocess a source file
src/SDLApp.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/SDLInterface.dir/build.make CMakeFiles/SDLInterface.dir/src/SDLApp.cpp.i
.PHONY : src/SDLApp.cpp.i

src/SDLApp.s: src/SDLApp.cpp.s
.PHONY : src/SDLApp.s

# target to generate assembly for a file
src/SDLApp.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/SDLInterface.dir/build.make CMakeFiles/SDLInterface.dir/src/SDLApp.cpp.s
.PHONY : src/SDLApp.cpp.s

src/SDLComponent.o: src/SDLComponent.cpp.o
.PHONY : src/SDLComponent.o

# target to build an object file
src/SDLComponent.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/SDLInterface.dir/build.make CMakeFiles/SDLInterface.dir/src/SDLComponent.cpp.o
.PHONY : src/SDLComponent.cpp.o

src/SDLComponent.i: src/SDLComponent.cpp.i
.PHONY : src/SDLComponent.i

# target to preprocess a source file
src/SDLComponent.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/SDLInterface.dir/build.make CMakeFiles/SDLInterface.dir/src/SDLComponent.cpp.i
.PHONY : src/SDLComponent.cpp.i

src/SDLComponent.s: src/SDLComponent.cpp.s
.PHONY : src/SDLComponent.s

# target to generate assembly for a file
src/SDLComponent.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/SDLInterface.dir/build.make CMakeFiles/SDLInterface.dir/src/SDLComponent.cpp.s
.PHONY : src/SDLComponent.cpp.s

src/TextureManager.o: src/TextureManager.cpp.o
.PHONY : src/TextureManager.o

# target to build an object file
src/TextureManager.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/SDLInterface.dir/build.make CMakeFiles/SDLInterface.dir/src/TextureManager.cpp.o
.PHONY : src/TextureManager.cpp.o

src/TextureManager.i: src/TextureManager.cpp.i
.PHONY : src/TextureManager.i

# target to preprocess a source file
src/TextureManager.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/SDLInterface.dir/build.make CMakeFiles/SDLInterface.dir/src/TextureManager.cpp.i
.PHONY : src/TextureManager.cpp.i

src/TextureManager.s: src/TextureManager.cpp.s
.PHONY : src/TextureManager.s

# target to generate assembly for a file
src/TextureManager.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/SDLInterface.dir/build.make CMakeFiles/SDLInterface.dir/src/TextureManager.cpp.s
.PHONY : src/TextureManager.cpp.s

src/Widget.o: src/Widget.cpp.o
.PHONY : src/Widget.o

# target to build an object file
src/Widget.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/SDLInterface.dir/build.make CMakeFiles/SDLInterface.dir/src/Widget.cpp.o
.PHONY : src/Widget.cpp.o

src/Widget.i: src/Widget.cpp.i
.PHONY : src/Widget.i

# target to preprocess a source file
src/Widget.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/SDLInterface.dir/build.make CMakeFiles/SDLInterface.dir/src/Widget.cpp.i
.PHONY : src/Widget.cpp.i

src/Widget.s: src/Widget.cpp.s
.PHONY : src/Widget.s

# target to generate assembly for a file
src/Widget.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/SDLInterface.dir/build.make CMakeFiles/SDLInterface.dir/src/Widget.cpp.s
.PHONY : src/Widget.cpp.s

src/WidgetManager.o: src/WidgetManager.cpp.o
.PHONY : src/WidgetManager.o

# target to build an object file
src/WidgetManager.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/SDLInterface.dir/build.make CMakeFiles/SDLInterface.dir/src/WidgetManager.cpp.o
.PHONY : src/WidgetManager.cpp.o

src/WidgetManager.i: src/WidgetManager.cpp.i
.PHONY : src/WidgetManager.i

# target to preprocess a source file
src/WidgetManager.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/SDLInterface.dir/build.make CMakeFiles/SDLInterface.dir/src/WidgetManager.cpp.i
.PHONY : src/WidgetManager.cpp.i

src/WidgetManager.s: src/WidgetManager.cpp.s
.PHONY : src/WidgetManager.s

# target to generate assembly for a file
src/WidgetManager.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/SDLInterface.dir/build.make CMakeFiles/SDLInterface.dir/src/WidgetManager.cpp.s
.PHONY : src/WidgetManager.cpp.s

src/main.o: src/main.cpp.o
.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/SDLInterface.dir/build.make CMakeFiles/SDLInterface.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/SDLInterface.dir/build.make CMakeFiles/SDLInterface.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/SDLInterface.dir/build.make CMakeFiles/SDLInterface.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... doc"
	@echo "... SDLInterface"
	@echo "... src/Button.o"
	@echo "... src/Button.i"
	@echo "... src/Button.s"
	@echo "... src/MyComponent.o"
	@echo "... src/MyComponent.i"
	@echo "... src/MyComponent.s"
	@echo "... src/MyComponent2.o"
	@echo "... src/MyComponent2.i"
	@echo "... src/MyComponent2.s"
	@echo "... src/SDLApp.o"
	@echo "... src/SDLApp.i"
	@echo "... src/SDLApp.s"
	@echo "... src/SDLComponent.o"
	@echo "... src/SDLComponent.i"
	@echo "... src/SDLComponent.s"
	@echo "... src/TextureManager.o"
	@echo "... src/TextureManager.i"
	@echo "... src/TextureManager.s"
	@echo "... src/Widget.o"
	@echo "... src/Widget.i"
	@echo "... src/Widget.s"
	@echo "... src/WidgetManager.o"
	@echo "... src/WidgetManager.i"
	@echo "... src/WidgetManager.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

