cmake_minimum_required(VERSION 2.8.3)
project(send_velocity)


find_package(catkin REQUIRED
	    roscpp
            rospy
            geometry_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES motion_planner
#  CATKIN_DEPENDS other_catkin_pkg
#  DEPENDS system_lib
)

#INCLUDE(${QT_USE_FILE})
include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(cmd main.cpp  )
target_link_libraries(cmd ${catkin_LIBRARIES}   ${QT_LIBRARIES})
