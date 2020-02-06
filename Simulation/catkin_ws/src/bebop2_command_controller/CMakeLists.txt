cmake_minimum_required(VERSION 2.8.3)
project(bebop2_command_controller)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
set (CMAKE_INCLUDE_CURRENT_DIR ON)
set (CMAKE_AUTOMOC ON)

find_package(Qt4 COMPONENTS QtCore QtGui)
INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})


set(qt_srcs
       src/ihm.cpp src/main.cpp)
set(qt_hdrs
       include/ihm.h include/main.h)

qt4_automoc(${qt_srcs})
QT4_WRAP_CPP(qt_moc_srcs ${qt_hdrs})


find_package(catkin REQUIRED COMPONENTS
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


add_compile_options(-std=c++11)



include_directories(/home/hossein/bebopSDK/out/arsdk-native/staging/usr/include)
link_directories(/home/hossein/bebopSDK/out/arsdk-native/staging/usr/lib)


catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES observation_model_node
#  CATKIN_DEPENDS other_catkin_pkg
#  DEPENDS system_lib
)


#INCLUDE(${QT_USE_FILE})
include_directories(
  ${catkin_INCLUDE_DIRS}
${OpenCV_INCLUDE_DIRS}
)

include_directories(include ${catkin_INCLUDE_DIRS} ${qt_hdrs} )
add_library(includesss11 ${qt_hdrs})


add_executable(bebop_controller src/main.cpp ${qt_srcs} ${qt_moc_srcs} )
target_link_libraries(bebop_controller ${catkin_LIBRARIES} ${OpenCV_LIBRARIES} ${QT_LIBRARIES} avutil-ffmpeg avformat avcodec swscale
 ardiscovery arsal arnetworkal pomp json mux arcontroller arcommands arstream arstream2 armedia arnetwork curses)


