

add_executable(search_engine
    main.cpp
    converterjson.cpp
    invertedindex.cpp
    invertedIndexTest.cpp
    searchserver.cpp
)

enable_testing()

target_link_libraries(search_engine nlohmann_json::nlohmann_json)
target_include_directories(search_engine PUBLIC ${MY_INCLUDE_DIR})

target_link_libraries(search_engine gtest_main)
include(GoogleTest)
gtest_discover_tests(search_engine)
