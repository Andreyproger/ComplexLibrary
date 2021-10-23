cmake_minimum_required(VERSION 3.0)

project(Compllib)

set(CMAKE_AUTO_MOC ON)
set(CMAKE_AUTO_RCC ON)
set(CMAKE_AUTO_UIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()
 
set(AUTOGEN_BUILD_DIR build)
set(AUTOGEN_TARGETS_FOLDER build)

enable_testing()

find_package(Boost COMPONENTS system filesystem unit_test_framework REQUIRED)

include_directories(src)
include_directories(tests)

file(GLOB_RECURSE _sources FOLLOW_SYMLINKS "src/*.c*")
file(GLOB_RECURSE _headers FOLLOW_SYMLINKS "src/*.h*")
file(GLOB_RECURSE _tests FOLLOW_SYMLINKS "tests/*.c*")

add_executable(${PROJECT_NAME} 
				main.cpp
				${_headers}
				${_sources}
				${_tests}
				)

#add_executable(${PROJECT_NAME} 
#				main.cpp
#				${_headers}
#				${_sources}
#				)

target_link_libraries(${PROJECT_NAME} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})