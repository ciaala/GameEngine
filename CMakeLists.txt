cmake_minimum_required(VERSION 3.7)
project(GameEngine)

#SET (CMAKE_C_COMPILER             "/usr/lib/llvm/4/bin/clang")
#SET (CMAKE_CXX_COMPILER             "/usr/lib/llvm/4/bin/clang++")
if(MSVC)
    # Force to always compile with W4
    if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    # Update if necessary
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic")
endif()
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
        src/engine/render/Render.cpp
        src/engine/render/Render.h
        #src/script/js.cpp
        #src/script/js.h

        src/engine/script/njs.cpp src/engine/script/njs.h src/engine/engine.cpp src/engine/engine.h src/engine/render/DriverInfo.cpp src/engine/render/DriverInfo.h src/engine/presenter/Presenter.cpp src/engine/presenter/Presenter.h src/engine/memory/MemoryManager.cpp src/engine/memory/MemoryManager.h src/engine/presenter/Window.cpp src/engine/presenter/Window.h)


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
