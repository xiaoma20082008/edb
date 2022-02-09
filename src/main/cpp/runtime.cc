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
// Created by chunxiao ma on 2022/2/8.
//

#include "runtime.hh"
#include "common.hh"
#include "dms.hh"
#include "ims.hh"
namespace edb {
Runtime::Runtime() {}
Runtime::~Runtime() noexcept {
  delete _index_manager;
  delete _dms_file;
}
Runtime *Runtime::GetInstance() {
  static Runtime rtn{};
  return &rtn;
}
int Runtime::Init() {
  int ret = EDB_OK;
  do {
    _index_manager = new (std::nothrow) IndexManager();
    if (_index_manager == nullptr) {
      ret = EDB_OOM;
      break;
    }
    _index_manager->Initialize();

    _dms_file = new (std::nothrow) DmsFile(_index_manager);
    if (_dms_file == nullptr) {
      ret = EDB_OOM;
      break;
    }
    _dms_file->Initialize();

  } while (false);
  return ret;
}
int Runtime::Insert(const void *&in) { return EDB_OK; }
int Runtime::Find(const void *&in, void *&out) { return EDB_OK; }
int Runtime::Remove(const void *&in) { return EDB_OK; }
} // namespace edb