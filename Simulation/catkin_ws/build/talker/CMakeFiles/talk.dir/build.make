# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/hossein/catkin_ws/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hossein/catkin_ws/build

# Include any dependencies generated for this target.
include talker/CMakeFiles/talk.dir/depend.make

# Include the progress variables for this target.
include talker/CMakeFiles/talk.dir/progress.make

# Include the compile flags for this target's objects.
include talker/CMakeFiles/talk.dir/flags.make

talker/CMakeFiles/talk.dir/main.cpp.o: talker/CMakeFiles/talk.dir/flags.make
talker/CMakeFiles/talk.dir/main.cpp.o: /home/hossein/catkin_ws/src/talker/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hossein/catkin_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object talker/CMakeFiles/talk.dir/main.cpp.o"
	cd /home/hossein/catkin_ws/build/talker && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/talk.dir/main.cpp.o -c /home/hossein/catkin_ws/src/talker/main.cpp

talker/CMakeFiles/talk.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/talk.dir/main.cpp.i"
	cd /home/hossein/catkin_ws/build/talker && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hossein/catkin_ws/src/talker/main.cpp > CMakeFiles/talk.dir/main.cpp.i

talker/CMakeFiles/talk.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/talk.dir/main.cpp.s"
	cd /home/hossein/catkin_ws/build/talker && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hossein/catkin_ws/src/talker/main.cpp -o CMakeFiles/talk.dir/main.cpp.s

talker/CMakeFiles/talk.dir/main.cpp.o.requires:

.PHONY : talker/CMakeFiles/talk.dir/main.cpp.o.requires

talker/CMakeFiles/talk.dir/main.cpp.o.provides: talker/CMakeFiles/talk.dir/main.cpp.o.requires
	$(MAKE) -f talker/CMakeFiles/talk.dir/build.make talker/CMakeFiles/talk.dir/main.cpp.o.provides.build
.PHONY : talker/CMakeFiles/talk.dir/main.cpp.o.provides

talker/CMakeFiles/talk.dir/main.cpp.o.provides.build: talker/CMakeFiles/talk.dir/main.cpp.o


# Object files for target talk
talk_OBJECTS = \
"CMakeFiles/talk.dir/main.cpp.o"

# External object files for target talk
talk_EXTERNAL_OBJECTS =

/home/hossein/catkin_ws/devel/lib/talker/talk: talker/CMakeFiles/talk.dir/main.cpp.o
/home/hossein/catkin_ws/devel/lib/talker/talk: talker/CMakeFiles/talk.dir/build.make
/home/hossein/catkin_ws/devel/lib/talker/talk: /opt/ros/kinetic/lib/libroscpp.so
/home/hossein/catkin_ws/devel/lib/talker/talk: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/hossein/catkin_ws/devel/lib/talker/talk: /usr/lib/x86_64-linux-gnu/libboost_signals.so
/home/hossein/catkin_ws/devel/lib/talker/talk: /opt/ros/kinetic/lib/librosconsole.so
/home/hossein/catkin_ws/devel/lib/talker/talk: /opt/ros/kinetic/lib/librosconsole_log4cxx.so
/home/hossein/catkin_ws/devel/lib/talker/talk: /opt/ros/kinetic/lib/librosconsole_backend_interface.so
/home/hossein/catkin_ws/devel/lib/talker/talk: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/hossein/catkin_ws/devel/lib/talker/talk: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/hossein/catkin_ws/devel/lib/talker/talk: /opt/ros/kinetic/lib/libroscpp_serialization.so
/home/hossein/catkin_ws/devel/lib/talker/talk: /opt/ros/kinetic/lib/libxmlrpcpp.so
/home/hossein/catkin_ws/devel/lib/talker/talk: /opt/ros/kinetic/lib/librostime.so
/home/hossein/catkin_ws/devel/lib/talker/talk: /opt/ros/kinetic/lib/libcpp_common.so
/home/hossein/catkin_ws/devel/lib/talker/talk: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/hossein/catkin_ws/devel/lib/talker/talk: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/hossein/catkin_ws/devel/lib/talker/talk: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
/home/hossein/catkin_ws/devel/lib/talker/talk: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/hossein/catkin_ws/devel/lib/talker/talk: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
/home/hossein/catkin_ws/devel/lib/talker/talk: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/hossein/catkin_ws/devel/lib/talker/talk: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so
/home/hossein/catkin_ws/devel/lib/talker/talk: talker/CMakeFiles/talk.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hossein/catkin_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/hossein/catkin_ws/devel/lib/talker/talk"
	cd /home/hossein/catkin_ws/build/talker && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/talk.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
talker/CMakeFiles/talk.dir/build: /home/hossein/catkin_ws/devel/lib/talker/talk

.PHONY : talker/CMakeFiles/talk.dir/build

talker/CMakeFiles/talk.dir/requires: talker/CMakeFiles/talk.dir/main.cpp.o.requires

.PHONY : talker/CMakeFiles/talk.dir/requires

talker/CMakeFiles/talk.dir/clean:
	cd /home/hossein/catkin_ws/build/talker && $(CMAKE_COMMAND) -P CMakeFiles/talk.dir/cmake_clean.cmake
.PHONY : talker/CMakeFiles/talk.dir/clean

talker/CMakeFiles/talk.dir/depend:
	cd /home/hossein/catkin_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hossein/catkin_ws/src /home/hossein/catkin_ws/src/talker /home/hossein/catkin_ws/build /home/hossein/catkin_ws/build/talker /home/hossein/catkin_ws/build/talker/CMakeFiles/talk.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : talker/CMakeFiles/talk.dir/depend

