cmake_minimum_required(VERSION 3.8)
project(search_engine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} "-static")
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(MY_INCLUDE_DIR
    ${CMAKE_SOURCE_DIR}/include
)
set(MY_SOURCE_DIR
    ${CMAKE_SOURCE_DIR}/resources
)
set(MY_SRC_DIR ${CMAKE_SOURCE_DIR}/src)

set(gtest_disable_pthreads on)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)


include(FetchContent)

FetchContent_Declare(
	json URL
    https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(json)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)


include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


add_subdirectory(src)
add_subdirectory(tests)

