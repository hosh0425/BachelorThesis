cmake_minimum_required(VERSION 2.8.3)
project(aruco_generator)

## Add support for C++11, supported in ROS Kinetic and newer
# add_definitions(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED
	roscpp
            rospy
 	    image_transport
            sensor_msgs
  	    genmsg
  	    tf2_msgs
  	    cv_bridge
            std_msgs
            geometry_msgs
)




find_package(OpenCV REQUIRED)


###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if you package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES image_listener
#  CATKIN_DEPENDS other_catkin_pkg
#  DEPENDS system_lib
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)
include_directories(include ${catkin_INCLUDE_DIRS} ${qt_hdrs})
#add_library(include1 ${qt_hdrs})


add_executable(generate main.cpp)
target_link_libraries(generate ${catkin_LIBRARIES}  ${OpenCV_LIBS} ${QT_LIBRARIES})
