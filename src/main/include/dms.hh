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

#ifndef EDB_DMS_HH
#define EDB_DMS_HH
#include "common.hh"
#include "os_mmap_file.hh"
namespace edb {
struct Rid {
  unsigned long _page_id{};
  unsigned long _slot_id{};
};
struct Record {};
struct Header {};
struct PageHeader {};
class IndexManager;
class DmsFile : public MMapFile {
public:
  DmsFile(IndexManager *index_manager);
  ~DmsFile();

public:
  int Initialize();

private:
  const IndexManager *_index_manager{};
};
} // namespace edb
#endif // EDB_DMS_HH
