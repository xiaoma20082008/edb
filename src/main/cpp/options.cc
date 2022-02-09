// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

//
// Created by chunxiao ma on 2022/1/13.
//

#include "options.hh"
#include <string>
#include <unordered_map>
namespace edb {
using namespace std;

EdbOptions::EdbOptions() {}
EdbOptions::~EdbOptions() {}
int EdbOptions::Parse(int argc, char **argv) {
  // --base-dir=
  // --data-dir=
  // --name=
  // --port=
  // --pool-size=
  for (int i = 1; i < argc; ++i) {
  }
  int ret = EDB_OK;
  _name = "EdbServer";
  _port = 9099;
  _pool_size = 64;
  _base_dir = "/var/tmp/edb";
  _data_dir = "/var/tmp/edb/data";
  return ret;
}

// region getter

int EdbOptions::GetPort() const { return _port; }
int EdbOptions::GetPoolSize() const { return _pool_size; }
const char *EdbOptions::GetSrvName() const { return _name; }
const char *EdbOptions::GetBaseDir() const { return _base_dir; }
const char *EdbOptions::GetDataDir() const { return _data_dir; }

// endregion getter

} // namespace edb