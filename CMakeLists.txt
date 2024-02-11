cmake_minimum_required(VERSION 3.26)
project(VulkanTomfoolery)

set(CMAKE_CXX_STANDARD 20)

include_directories(
        ~/VulkanSDK/1.3.261.1/macOS/include
        
)
link_directories(
        ~/VulkanSDK/1.3.261.1/macOS/lib
)

add_executable(
        VulkanTomfoolery
        main.cpp
        VulkanRenderer.cpp
        VulkanRenderer.hpp
)

find_package(glfw3 3.3.8 REQUIRED)
find_package(glm REQUIRED)
find_package(Vulkan REQUIRED)

target_link_libraries(VulkanTomfoolery Vulkan glfw glm::glm)

set (source "${CMAKE_SOURCE_DIR}/resources")
set (destination "${CMAKE_CURRENT_BINARY_DIR}/resources")
add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E create_symlink ${source} ${destination}
        DEPENDS ${destination}
        COMMENT "symbolic link resources folder from ${source} => ${destination}")
