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
add_subdirectory(main)

#set(EDB_SOURCES
#        dms/dms.cpp
#        ixm/ixmBucket.cpp
#        msg/msg.cpp
#        oss/ossHash.cpp oss/ossMmapFile.cpp oss/ossPrimitiveFileOp.cpp oss/ossSocket.cpp
#        pd/pd.cpp
#        rtn/rtn.cpp
#        )
#add_library(edb SHARED ${EDB_SOURCES})
#target_include_directories(edb PRIVATE include)
#target_link_directories(edb PRIVATE include)
#
#set(CLIENT_SOURCES client/edb.cpp client/command.cpp client/commandFactory.cpp)
#set(SERVER_SOURCES pmd/pmdMain.cpp pmd/pmd.cpp pmd/pmdAgent.cpp pmd/pmdEDU.cpp pmd/pmdEDUMgr.cpp pmd/pmdOptions.cpp pmd/pmdTcpListener.cpp)
#
#add_executable(client ${CLIENT_SOURCES})
#add_executable(server ${SERVER_SOURCES})
#
#target_link_libraries(client edb)
#target_include_directories(client PRIVATE include)
#target_link_directories(client PRIVATE include)
#
#target_link_libraries(server edb)
#target_include_directories(server PRIVATE include)
#target_link_directories(server PRIVATE include)

if(BUILD_TESTING)
    add_subdirectory(test)
endif()
