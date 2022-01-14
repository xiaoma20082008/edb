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
#        mongo-cxx-driver
#        GIT_REPOSITORY      https://github.com/mongodb/mongo-cxx-driver.git
#        GIT_TAG             r3.6.6
#        PREFIX              ${CMAKE_HOME_DIRECTORY}/external/vendor
#        TIMEOUT             100
#        CMAKE_ARGS          "-DCMAKE_BUILD_TYPE=Release"
#        CONFIGURE_COMMAND   ""
#        BUILD_COMMAND       ""
#        INSTALL_COMMAND     ""
#        UPDATE_COMMAND      ""
#)
FetchContent_Declare(
        mongo-cxx-driver
        GIT_REPOSITORY https://github.com/mongodb/mongo-cxx-driver.git
        GIT_TAG        r3.6.6
        GIT_SHALLOW    TRUE
)
FetchContent_GetProperties(mongo-cxx-driver)
if(NOT mongo-cxx-driver_POPULATED)
    FetchContent_Populate(mongo-cxx-driver)
endif()
#add_subdirectory(${mongo-cxx-driver_SOURCE_DIR})
FetchContent_MakeAvailable(mongo-cxx-driver)