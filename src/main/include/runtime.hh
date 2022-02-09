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

#ifndef EDB_RUNTIME_HH
#define EDB_RUNTIME_HH
namespace edb {
class IndexManager;
class DmsFile;
class Runtime {
public:
  static Runtime *GetInstance();

  int Init();
  int Insert(const void *&in);
  int Find(const void *&in, void *&out);
  int Remove(const void *&in);

private:
  Runtime();
  ~Runtime() noexcept;

private:
  IndexManager *_index_manager{};
  DmsFile *_dms_file{};
};
} // namespace edb
#endif // EDB_RUNTIME_HH
