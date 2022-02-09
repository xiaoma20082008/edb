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
// Created by chunxiao ma on 2022/1/20.
//

#include "dms.hh"
namespace edb {
DmsFile::DmsFile(IndexManager *index_manager) : _index_manager(index_manager) {}
DmsFile::~DmsFile() {}

int DmsFile::Initialize() {
  if (_index_manager != nullptr) {
  }
  return EDB_OK;
}

} // namespace edb
