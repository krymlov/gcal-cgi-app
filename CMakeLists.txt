cmake_minimum_required(VERSION 3.17)

project(gcal-cgi)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static -Wall")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -ffunction-sections -fdata-sections -Wl,--gc-sections")

# src/ mirrors gcal-jni-lib/jni, so gcal.cpp includes the JNI header gcal.h (jni.h).
# Only the headers are needed: the exported JNI function is compiled but never called,
# and nothing links against the JVM. main() is in src/cgi_main.cpp.
if(NOT DEFINED ENV{JAVA_HOME})
    message(FATAL_ERROR "JAVA_HOME is not set - gcal.cpp needs jni.h")
endif()
file(TO_CMAKE_PATH "$ENV{JAVA_HOME}" JDK_DIR)
include_directories("${JDK_DIR}/include" "${JDK_DIR}/include/win32")

add_executable(gcal-cgi src/cgi_main.cpp src/apc.cpp src/astro.cpp src/astro_arr.cpp src/astro_base.cpp src/astro_cr.cpp src/astro_moon.cpp src/astro_ms.cpp src/astro_res.cpp src/astro_sun.cpp src/astro_w.cpp src/avc.cpp src/gcal.cpp src/gc_fb.cpp src/gc_gstr.cpp src/gc_ui.cpp src/gmath.cpp src/tfile.cpp src/tstring.cpp src/ttimezone.cpp)
