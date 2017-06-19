cmake_minimum_required(VERSION 3.7)
project(ogre21test)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(ogre21test ${SOURCE_FILES})

# troonie: the following sample is taken from OGRE tutorial
if(WIN32)
    set(CMAKE_MODULE_PATH "$ENV{OGRE_HOME}/CMake/;${CMAKE_MODULE_PATH}")
endif(WIN32)
if(UNIX)
    if(EXISTS "/usr/local/lib/OGRE/cmake")
        set(CMAKE_MODULE_PATH "/usr/local/lib/OGRE/cmake/;${CMAKE_MODULE_PATH}")
    elseif(EXISTS "/usr/lib/OGRE/cmake")
        set(CMAKE_MODULE_PATH "/usr/lib/OGRE/cmake/;${CMAKE_MODULE_PATH}")
    else ()
        message(SEND_ERROR "Failed to find module path.")
    endif(EXISTS "/usr/local/lib/OGRE")
endif(UNIX)

include(FindOGRE)

include_directories(
	${OGRE_INCLUDE_DIRS}
)
target_link_libraries(ogre21test ${OGRE_LIBRARIES})
