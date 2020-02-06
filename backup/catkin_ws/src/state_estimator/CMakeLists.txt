cmake_minimum_required(VERSION 2.8.3)
project(state_estimator)

## Add support for C++11, supported in ROS Kinetic and newer
# add_definitions(-std=c++11)
set (CMAKE_INCLUDE_CURRENT_DIR ON)
set (CMAKE_AUTOMOC ON)

find_package(Qt4 COMPONENTS QtCore QtGui QtNetWork)
INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})

find_package(OpenCV REQUIRED)
find_package (X11 REQUIRED)

set(qt_srcs
       src/state_estimator.cpp src/main.cpp)
set(qt_hdrs
       include/state_estimator.h)

qt4_automoc(${qt_srcs})
QT4_WRAP_CPP(qt_moc_srcs ${qt_hdrs})
#QT4_WRAP_UI(UIS_HDRS ui_form/mainwindow.ui)
## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED
	    roscpp
            rospy
            sensor_msgs
            genmsg
            tf2_msgs
            std_msgs
            geometry_msgs
            message_generation
)

add_message_files(
  FILES
  Ardrone3PilotingStateSpeedChanged.msg
  Ardrone3PilotingStateAttitudeChanged.msg
)
generate_messages(
  DEPENDENCIES
  std_msgs 
  geometry_msgs
)

catkin_package(
CATKIN_DEPENDS message_runtime 
#  INCLUDE_DIRS include
#  LIBRARIES observation_model_node
#  CATKIN_DEPENDS other_catkin_pkg
#  DEPENDS system_lib
)





#INCLUDE(${QT_USE_FILE})
include_directories(
  ${catkin_INCLUDE_DIRS}
)
include_directories(include ${catkin_INCLUDE_DIRS} ${qt_hdrs})
add_library(include11 ${qt_hdrs})


add_executable(ekf src/main.cpp  ${qt_srcs} ${qt_moc_srcs})
target_link_libraries(ekf ${catkin_LIBRARIES}   ${QT_LIBRARIES})

