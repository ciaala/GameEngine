cmake_minimum_required(VERSION 3.7)
project(GameEngine)

set(CMAKE_CXX_STANDARD 14)
#set(V8_LIBRARIES
#        /opt/v8/out.gn/x64.release/libv8.so
#        /opt/v8/out.gn/x64.release/libicuuc.so
#        /opt/v8/out.gn/x64.release/libicui18n.so
#        /opt/v8/out.gn/x64.release/libv8_libbase.so
#        /opt/v8/out.gn/x64.release/libv8_libplatform.so)
set(NODEJS_LIBRARIES
        PUBLIC /opt/node-v7.8.0/out/Release/lib/libnode.so.51
        )
find_package (Threads)

set(VULKAN_LIBRARIES
        PUBLIC /opt/VulkanSDK/1.0.42.2/x86_64/lib/libvulkan.so.1.0.42
        PUBLIC /opt/VulkanSDK/1.0.42.2/samples/build/API-Samples/utils/libvsamputils.a
        PUBLIC /opt/VulkanSDK/1.0.42.2/x86_64/lib/glslang/libglslang.a
        )
set(LIBRARIES ${VULKAN_LIBRARIES} ${V8_LIBRARIES} ${NODEJS_LIBRARIES})


set(SOURCE_FILES
        src/main.cpp
        src/engine/render.cpp
        src/engine/render.h
        #src/script/js.cpp
        #src/script/js.h

        src/script/njs.cpp src/script/njs.h)


add_executable(GameEngine ${SOURCE_FILES})

target_include_directories(GameEngine
        PUBLIC /opt/node-v7.8.0/deps/v8/include
        PUBLIC /opt/node-v7.8.0/src
        PUBLIC /opt/VulkanSDK/1.0.42.2/x86_64/include
        PUBLIC /opt/VulkanSDK/1.0.42.2/samples/API-Samples/utils

)
        #PUBLIC /opt/v8/include
target_link_libraries(GameEngine
        PUBLIC ${CMAKE_THREAD_LIBS_INIT}

        PUBLIC ${CMAKE_DL_LIBS}
        ${LIBRARIES}

        )
