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

#ifndef EDB_IMS_HH
#define EDB_IMS_HH
#include "json.hh"
#include <vector>
namespace edb {
constexpr int INDEX_HASH_MAP_SIZE = 1024;
struct Rid;

class IndexManager {
public:
  IndexManager();
  ~IndexManager();

public:
  int Initialize();
  int CreateIndex(JsonObject *doc, Rid *record);
  int FindIndex(JsonObject *doc, Rid *record);
  int DropIndex(JsonObject *doc, Rid *record);
  int Exists(JsonObject *doc);

private:
  int Process();

private:
  struct Bucket;
  std::vector<Bucket *> _buckets;
};

} // namespace edb
#endif // EDB_IMS_HH
