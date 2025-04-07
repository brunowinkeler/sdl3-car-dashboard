cmake_minimum_required(VERSION 3.16)
project(SDL3CarDashboard)

# This makes sure that the dynamic library goes into the build directory automatically.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

# Option to enable or disable building example applications
option(BUILD_EXAMPLES "Build the examples" ON)

# This assumes the SDL source is available in vendored/SDL
add_subdirectory(external/SDL3 EXCLUDE_FROM_ALL)
add_subdirectory(external/SDL3_image EXCLUDE_FROM_ALL)
add_subdirectory(external/SDL3_ttf EXCLUDE_FROM_ALL)
# add_subdirectory(src)

# Add the examples directory only if BUILD_EXAMPLES is ON
if(BUILD_EXAMPLES)
    message(STATUS "Building examples.")
    add_subdirectory(examples)
else()
    message(STATUS "Skipping examples.")
endif()