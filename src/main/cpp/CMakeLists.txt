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
add_library(edb2)
target_sources(
        edb2 PRIVATE
        # Process Model
        command.cc
        msg.cc
        options.cc
        session.cc
        # Runtime
        runtime.cc
        # Index Management System
        ims.cc
        # JSON
        json.cc
        # Logging
        log.cc
        # Data Management System
        dms.cc
        # Operating System
        os_file.cc os_hash.cc os_latch.cc os_socket.cc os_mmap_file.cc
        # Others
        settings.cc
)

target_link_libraries(edb2 PRIVATE asio spdlog jsoncpp_lib)

add_executable(cli main_cli.cc)
add_executable(srv main_srv.cc server.cc)

target_link_libraries(srv PRIVATE asio edb2 spdlog jsoncpp_lib)
target_link_libraries(cli PRIVATE asio edb2 spdlog jsoncpp_lib)