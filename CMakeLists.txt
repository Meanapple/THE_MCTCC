project(MCTCC)

# States that CMake required version must be greater than 2.8
cmake_minimum_required(VERSION 2.8)

# Currently we are only using c++11 features.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(CMAKE_CXX_FLAGS_DEBUG "-Wall -g")


# Setup sources
set(MCTCC_SOURCES
        src/Management/Gamemanager.cpp)


# Appends the cmake/modules path inside the MAKE_MODULE_PATH variable which stores the
# directories of additional CMake modules (ie. MacroOutOfSourceBuild.cmake):
set(CMAKE_MODULE_PATH ${MCTCC_SOURCE_DIR}/cmake/ ${CMAKE_MODULE_PATH})

# Find SDL2 libraries using the custom made module in
# the cmake/ path
find_package(SDL2 REQUIRED)
find_package(SDL2_IMAGE REQUIRED)
find_package(SDL2_TTF REQUIRED)
find_package(SDL2_MIXER REQUIRED)

# Find required boost libraries
find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

# Add SDL2 include directory to search path
include_directories(${SDL2_INCLUDE_DIR})
include_directories(${SDL2_IMG_INCLUDE_DIR})
include_directories(${SDL2_TTF_INCLUDE_DIR})
include_directories(${SDL2_MIXER_INCLUDE_DIR})

#Add Box2D
find_package(BOX2D REQUIRED)
include_directories(${BOX2D_INCLUDE_DIR})

# Build executable
add_executable(mctcc src/Management/main.cpp ${MGTGG_SOURCES} src/Management/Gamemanager.cpp src/Management/Gamemanager.hpp src/Objects/Entity.cpp src/Objects/Entity.hpp src/Objects/Scene.cpp src/Objects/Scene.hpp src/Management/Config.cpp src/Management/Config.hpp src/Management/Util.cpp src/Management/Util.hpp src/Objects/Sprite.cpp src/Objects/Sprite.hpp src/Management/LayerManager.cpp src/Management/LayerManager.hpp src/Management/EntityManager.cpp src/Management/EntityManager.hpp src/Management/TileMap.cpp src/Management/TileMap.hpp)
target_link_libraries(mctcc ${SDL2_LIBRARY} ${SDL2_IMG_LIBRARY} ${SDL2_TTF_LIBRARY} ${SDL2_MIXER_LIBRARY})
target_link_libraries(mctcc ${BOX2D_LIBRARY})
target_link_libraries(mctcc m)

#Copy Resources
add_custom_command(
        TARGET mctcc POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/res
        ${CMAKE_CURRENT_BINARY_DIR}/res)