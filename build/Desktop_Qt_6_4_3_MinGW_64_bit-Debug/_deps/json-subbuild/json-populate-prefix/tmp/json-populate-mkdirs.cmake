# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/develop/search_engine/build/Desktop_Qt_6_4_3_MinGW_64_bit-Debug/_deps/json-src"
  "C:/develop/search_engine/build/Desktop_Qt_6_4_3_MinGW_64_bit-Debug/_deps/json-build"
  "C:/develop/search_engine/build/Desktop_Qt_6_4_3_MinGW_64_bit-Debug/_deps/json-subbuild/json-populate-prefix"
  "C:/develop/search_engine/build/Desktop_Qt_6_4_3_MinGW_64_bit-Debug/_deps/json-subbuild/json-populate-prefix/tmp"
  "C:/develop/search_engine/build/Desktop_Qt_6_4_3_MinGW_64_bit-Debug/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp"
  "C:/develop/search_engine/build/Desktop_Qt_6_4_3_MinGW_64_bit-Debug/_deps/json-subbuild/json-populate-prefix/src"
  "C:/develop/search_engine/build/Desktop_Qt_6_4_3_MinGW_64_bit-Debug/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/develop/search_engine/build/Desktop_Qt_6_4_3_MinGW_64_bit-Debug/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/develop/search_engine/build/Desktop_Qt_6_4_3_MinGW_64_bit-Debug/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
