cmake_minimum_required(VERSION 3.24)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(ANDROID_STL gnustl_static)
set(ANDROID_ABI armeabi)

project(template)

add_library(template SHARED src/main.cpp)

set(DOBBY_DEBUG OFF CACHE INTERNAL "" FORCE)
set(DOBBY_GENERATE_SHARED OFF CACHE INTERNAL "" FORCE)
add_subdirectory(third_party/Dobby) # 16b99a55dc219114832c33f3258f48ca2958ed70
target_link_libraries(template dobby)

target_include_directories(template PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/third_party/cocos2d/cocos2dx
	${CMAKE_CURRENT_SOURCE_DIR}/third_party/cocos2d/cocos2dx/include
	${CMAKE_CURRENT_SOURCE_DIR}/third_party/cocos2d/cocos2dx/kazmath/include
	${CMAKE_CURRENT_SOURCE_DIR}/third_party/cocos2d/cocos2dx/platform/android

	${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(template ${CMAKE_CURRENT_SOURCE_DIR}/libgame.so)
