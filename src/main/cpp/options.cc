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
#include "common.hh"

namespace edb {
EdbOptions::EdbOptions() {}
EdbOptions::~EdbOptions() {}
int EdbOptions::Parse(int argc, char **argv) {
  int ret = EDB_OK;
  // --base-dir=
  // --data-dir=
  // --port=
  // --pool-size=
  return ret;
}

// region getter

int EdbOptions::GetPort() { return port_; }
int EdbOptions::GetPoolSize() { return pool_size_; }
const char *EdbOptions::GetName() { return name_; }
const char *EdbOptions::GetBaseDir() { return base_dir_; }
const char *EdbOptions::GetDataDir() { return data_dir_; }

// endregion getter

} // namespace edb