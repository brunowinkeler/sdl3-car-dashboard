# Create your game executable target as usual
add_executable(helloLoop helloLoop.cpp)
add_executable(helloCallback helloCallback.cpp)
add_executable(helloImage helloImage.cpp)

# Link to the actual SDL3 library.
target_link_libraries(helloLoop PRIVATE 
                SDL3_image::SDL3_image	
                SDL3::SDL3 )
target_link_libraries(helloCallback PRIVATE SDL3::SDL3)
target_link_libraries(helloImage PRIVATE 
                SDL3_image::SDL3_image	
                SDL3::SDL3 )