if(EXISTS "C:/develop/search_engine/build/Desktop_Qt_6_4_3_MinGW_64_bit-Debug/search_engine[2]_tests.cmake")
  include("C:/develop/search_engine/build/Desktop_Qt_6_4_3_MinGW_64_bit-Debug/search_engine[2]_tests.cmake")
else()
  add_test(search_engine_NOT_BUILT search_engine_NOT_BUILT)
endif()
