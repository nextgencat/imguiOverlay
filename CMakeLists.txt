cmake_minimum_required(VERSION 3.20)
project(imguioverlay)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(IMGUI_DIR imgui)

add_executable(imguioverlay
    src/main.cpp
    #RENDER
    src/render/render.h
    src/render/render.cpp

    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/imgui_demo.cpp

    ${IMGUI_DIR}/backends/imgui_impl_win32.cpp
    ${IMGUI_DIR}/backends/imgui_impl_dx11.cpp
)

target_include_directories(imguioverlay PRIVATE
    src
    ${IMGUI_DIR}
    ${IMGUI_DIR}/backends
)

target_link_libraries(imguioverlay PRIVATE
    d3d11
    d3dcompiler
    dwmapi
)

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_options(imguioverlay PRIVATE -O2 -DNDEBUG)
    target_link_options(imguioverlay PRIVATE -s -static -static-libgcc -static-libstdc++)
endif()
