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

#include "ims.hh"
#include "dms.hh"
#include "os_latch.hh"
#include <map>
namespace edb {

struct IndexHash {
  const char *_data;
  Rid _rid;
};

struct IndexManager::Bucket {
private:
  std::multimap<unsigned int, IndexHash> _buckets;
  SLatch _mutex;

public:
  // get the record whether exist
  int IsIdExist(unsigned int hashNum, IndexHash &eleHash) { return EDB_OK; }
  int CreateIndex(unsigned int hashNum, IndexHash &eleHash) { return EDB_OK; }
  int FindIndex(unsigned int hashNum, IndexHash &eleHash) { return EDB_OK; }
  int RemoveIndex(unsigned int hashNum, IndexHash &eleHash) { return EDB_OK; }
};

IndexManager::IndexManager() {}
IndexManager::~IndexManager() {
  for (int i = 0; i < INDEX_HASH_MAP_SIZE; ++i) {
    IndexManager::Bucket *bucket = _buckets[i];
    delete bucket;
  }
}

int IndexManager::Initialize() {
  IndexManager::Bucket *bucket{};
  for (int i = 0; i < INDEX_HASH_MAP_SIZE; ++i) {
    bucket = new (std::nothrow) IndexManager::Bucket{};
    _buckets.push_back(bucket);
    bucket = nullptr;
  }
  return EDB_OK;
}
int IndexManager::CreateIndex(JsonObject *doc, Rid *record) { return EDB_OK; }
int IndexManager::DropIndex(JsonObject *doc, Rid *record) { return EDB_OK; }
int IndexManager::FindIndex(JsonObject *doc, Rid *record) { return EDB_OK; }
int IndexManager::Exists(JsonObject *doc) { return EDB_OK; }
int IndexManager::Process() { return EDB_OK; }
} // namespace edb