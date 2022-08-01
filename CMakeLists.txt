cmake_minimum_required(VERSION 3.17)

project(gcal-cgi)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static -Wall")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -ffunction-sections -fdata-sections -Wl,--gc-sections")


add_executable(gcal-cgi src/apc.cpp src/astro.cpp src/astro_arr.cpp src/astro_base.cpp src/astro_cr.cpp src/astro_moon.cpp src/astro_ms.cpp src/astro_res.cpp src/astro_sun.cpp src/astro_w.cpp src/avc.cpp src/gcal.cpp src/gc_fb.cpp src/gc_gstr.cpp src/gc_ui.cpp src/gmath.cpp src/tfile.cpp src/tstring.cpp src/ttimezone.cpp)