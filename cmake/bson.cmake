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
#ExternalProject_Add(
#        mongo-c-driver
#        GIT_REPOSITORY      https://github.com/mongodb/mongo-c-driver.git
#        GIT_TAG             1.20.1
#        PREFIX              ${EXTERNAL_PROJECT_DIR}
#        TIMEOUT             100
#        CMAKE_CACHE_ARGS    ""
#        CONFIGURE_COMMAND   ""
#        BUILD_COMMAND       ""
#        INSTALL_COMMAND     ""
#        UPDATE_COMMAND      ""
#)
#ExternalProject_Add(
#        mongo-cxx-driver
#        GIT_REPOSITORY      https://github.com/mongodb/mongo-cxx-driver.git
#        GIT_TAG             r3.6.6
#        PREFIX              ${EXTERNAL_PROJECT_DIR}
#        TIMEOUT             100
#        CMAKE_CACHE_ARGS    ""
#        CONFIGURE_COMMAND   ""
#        BUILD_COMMAND       ""
#        INSTALL_COMMAND     ""
#        UPDATE_COMMAND      ""
#        DEPENDS             mongo-c-driver
#)
FetchContent_Declare(
        mongo-c-driver
        GIT_REPOSITORY https://github.com/mongodb/mongo-c-driver.git
        GIT_TAG        1.20.1
)
FetchContent_GetProperties(mongo-c-driver)
if(NOT mongo-c-driver_POPULATED)
    FetchContent_Populate(mongo-c-driver)
endif()
#message("mongo-c-driver-source-dir:${mongo-c-driver_SOURCE_DIR}")
#message("mongo-c-driver-binary-dir:${mongo-c-driver_BINARY_DIR}")
#FetchContent_MakeAvailable(mongo-c-driver)
#add_subdirectory(${mongo-c-driver_SOURCE_DIR})

FetchContent_Declare(
        mongo-cxx-driver
        GIT_REPOSITORY https://github.com/mongodb/mongo-cxx-driver.git
        GIT_TAG        r3.6.6
)
FetchContent_GetProperties(mongo-cxx-driver)
if(NOT mongo-cxx-driver_POPULATED)
    FetchContent_Populate(mongo-cxx-driver)
endif()
#message("mongo-cxx-driver-source-dir:${mongo-cxx-driver_SOURCE_DIR}")
#message("mongo-cxx-driver-binary-dir:${mongo-cxx-driver_BINARY_DIR}")
#FetchContent_MakeAvailable(mongo-cxx-driver)
#add_subdirectory(${mongo-cxx-driver_SOURCE_DIR})