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

#ifndef EDB_INDEX_HH
#define EDB_INDEX_HH
#include "row.hh"
#include <vector>
namespace edb {

struct IndexData {
  const char *data_{};
  Row rid_{};
};

class IndexManager {
public:
  IndexManager();
  ~IndexManager();

public:
  int IdExists(void *record);
  int FindIndex(void *record, Row *rid);
  int CreateIndex(void *record, Row *rid);
  int DropIndex(void *record, Row *rid);

private:
  struct Index;
  std::vector<Index *> indexes_{};
};

} // namespace edb
#endif // EDB_INDEX_HH
