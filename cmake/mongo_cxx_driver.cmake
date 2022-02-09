#
# Licensed to the Apache Software Foundation (ASF) under one or more
# contributor license agreements.  See the NOTICE file distributed with
# this work for additional information regarding copyright ownership.
# The ASF licenses this file to You under the Apache License, Version 2.0
# (the "License"); you may not use this file except in compliance with
# the License.  You may obtain a copy of the License at
#
#       http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

# mongo-c-driver
set(MONGO_C_DRIVER_SOURCE_DIR "${EXTERNAL_PROJECT_BASE_DIR}/mongo-c-driver-src")
set(MONGO_C_DRIVER_BINARY_DIR "${EXTERNAL_PROJECT_BASE_DIR}/mongo-c-driver-build")
set(MONGO_C_DRIVER_INSTALL_DIR "${EXTERNAL_PROJECT_BASE_DIR}/mongo-c-driver-install")
set(MONGO_C_DRIVER_CMAKE_CACHE_ARGS
        "-DCMAKE_BUILD_TYPE:STRING=Release"
        "-DCMAKE_INSTALL_PREFIX:PATH=${MONGO_C_DRIVER_INSTALL_DIR}"
        "-DENABLE_TESTS:BOOL=OFF"
        "-DENABLE_STATIC:BOOL=OFF"
        "-DENABLE_EXAMPLES:BOOL=OFF"
        "-DENABLE_EXTRA_ALIGNMENT:BOOL=OFF")

# mongo-cxx-driver
set(MONGO_CXX_DRIVER_SOURCE_DIR "${EXTERNAL_PROJECT_BASE_DIR}/mongo-cxx-driver-src")
set(MONGO_CXX_DRIVER_BINARY_DIR "${EXTERNAL_PROJECT_BASE_DIR}/mongo-cxx-driver-build")
set(MONGO_CXX_DRIVER_INSTALL_DIR "${EXTERNAL_PROJECT_BASE_DIR}/mongo-cxx-driver-install")
set(MONGO_CXX_DRIVER_CMAKE_CACHE_ARGS
        "-DCMAKE_BUILD_TYPE:STRING=Release"
        "-DCMAKE_INSTALL_PREFIX:PATH=${MONGO_CXX_DRIVER_INSTALL_DIR}"
        "-DBUILD_SHARED_LIBS:BOOL=ON"
        "-DENABLE_TESTS:BOOL=OFF"
        "-DENABLE_EXAMPLES:BOOL=OFF"
        "-DBSONCXX_POLY_USE_MNMLSTC:BOOL=OFF"
        "-Dlibmongoc-1.0_DIR:PATH=${MONGO_C_DRIVER_INSTALL_DIR}/lib/cmake/libmongoc-1.0"
        "-Dlibbson-1.0_DIR:PATH=${MONGO_C_DRIVER_INSTALL_DIR}/lib/cmake/libbson-1.0"
        )
#
ExternalProject_Add(
        mongo_c_driver
        GIT_REPOSITORY      https://github.com/mongodb/mongo-c-driver.git
        GIT_TAG             1.20.1
        PREFIX              "${EXTERNAL_PROJECT_BASE_DIR}"
        SOURCE_DIR          "${MONGO_C_DRIVER_SOURCE_DIR}"
        BINARY_DIR          "${MONGO_C_DRIVER_BINARY_DIR}"
        TIMEOUT             100
        BUILD_ALWAYS        TRUE
        CMAKE_CACHE_ARGS    "${MONGO_C_DRIVER_CMAKE_CACHE_ARGS}"
#        CONFIGURE_COMMAND   ""
#        BUILD_COMMAND       ""
        INSTALL_COMMAND     ""
        UPDATE_COMMAND      ""
)

ExternalProject_Add(
        mongo_cxx_driver
        GIT_REPOSITORY      https://github.com/mongodb/mongo-cxx-driver.git
        GIT_TAG             r3.6.6
        PREFIX              "${EXTERNAL_PROJECT_BASE_DIR}"
        SOURCE_DIR          "${MONGO_CXX_DRIVER_SOURCE_DIR}"
        BINARY_DIR          "${MONGO_CXX_DRIVER_BINARY_DIR}"
        TIMEOUT             100
        BUILD_ALWAYS        TRUE
        CMAKE_CACHE_ARGS    "${MONGO_CXX_DRIVER_CMAKE_CACHE_ARGS}"
#        CONFIGURE_COMMAND   ""
#        BUILD_COMMAND       ""
        INSTALL_COMMAND     ""
        UPDATE_COMMAND      ""
        DEPENDS             mongo_c_driver
)

#FetchContent_Declare(
#        mongo-c-driver
#        GIT_REPOSITORY https://github.com/mongodb/mongo-c-driver.git
#        GIT_TAG        1.20.1
#)
#FetchContent_GetProperties(mongo-c-driver)
#if(NOT mongo-c-driver_POPULATED)
#    FetchContent_Populate(mongo-c-driver)
#endif()
#FetchContent_MakeAvailable(mongo-c-driver)
#add_subdirectory(${mongo-c-driver_SOURCE_DIR})

#FetchContent_Declare(
#        mongo-cxx-driver
#        GIT_REPOSITORY https://github.com/mongodb/mongo-cxx-driver.git
#        GIT_TAG        r3.6.6
#)
#FetchContent_GetProperties(mongo-cxx-driver)
#if(NOT mongo-cxx-driver_POPULATED)
#    FetchContent_Populate(mongo-cxx-driver)
#endif()
#FetchContent_MakeAvailable(mongo-cxx-driver)
#add_subdirectory(${mongo-cxx-driver_SOURCE_DIR})