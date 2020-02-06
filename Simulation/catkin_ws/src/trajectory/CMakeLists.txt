cmake_minimum_required(VERSION 2.8.3)
project(trajectory)

set (CMAKE_INCLUDE_CURRENT_DIR ON)
set (CMAKE_AUTOMOC ON)

find_package(Qt4 COMPONENTS QtCore QtGui)
INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})


set(qt_srcs
       src/trajectory.cpp src/main.cpp)
set(qt_hdrs
       include/trajectory.h)

qt4_automoc(${qt_srcs})
QT4_WRAP_CPP(qt_moc_srcs ${qt_hdrs})

find_package(catkin REQUIRED
	    roscpp
            rospy
            sensor_msgs
            genmsg
            tf2_msgs
            std_msgs
            geometry_msgs
)

catkin_package(
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
add_library(includesss1 ${qt_hdrs})


add_executable(trajectory src/main.cpp  ${qt_srcs} ${qt_moc_srcs})
target_link_libraries(trajectory ${catkin_LIBRARIES}   ${QT_LIBRARIES})

