cmake_minimum_required(VERSION 3.7)
project(TTT)

set(CMAKE_CXX_STANDARD 14)
set(V8_LIBRARIES
        /opt/v8/out.gn/x64.release/libv8.so
        /opt/v8/out.gn/x64.release/libicuuc.so
        /opt/v8/out.gn/x64.release/libicui18n.so
        /opt/v8/out.gn/x64.release/libv8_libbase.so
        /opt/v8/out.gn/x64.release/libv8_libplatform.so)
set(VULKAN_LIBRARIES
        /opt/VulkanSDK/1.0.42.2/x86_64/lib/libvulkan.so.1.0.42
        /opt/VulkanSDK/1.0.42.2/samples/build/API-Samples/utils/libvsamputils.a
        /opt/VulkanSDK/1.0.42.2/x86_64/lib/glslang/libglslang.a
        )
set(LIBRARIES ${VULKAN_LIBRARIES} ${V8_LIBRARIES})


set(SOURCE_FILES
        src/main.cpp
        src/engine/render.cpp
        src/engine/render.h
        src/script/js.cpp
        src/script/js.h

        )


add_executable(TTT ${SOURCE_FILES})
target_include_directories(TTT
        PUBLIC /opt/v8/include
        PUBLIC /opt/VulkanSDK/1.0.42.2/x86_64/include
        PUBLIC /opt/VulkanSDK/1.0.42.2/samples/API-Samples/utils)
target_link_libraries(TTT PUBLIC ${LIBRARIES})
