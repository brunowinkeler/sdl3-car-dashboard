file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS
    ${CMAKE_SOURCE_DIR}/include/*.hpp
)

add_executable(SDL3CarDashboard
    ${SOURCES}
    ${HEADERS}
)

target_include_directories(SDL3CarDashboard
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(SDL3CarDashboard
    SDL3_image::SDL3_image	
    SDL3::SDL3
    SDL3_ttf::SDL3_ttf
)
