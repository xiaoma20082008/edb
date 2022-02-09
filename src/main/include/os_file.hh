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

#ifndef EDB_OS_FILE_HH
#define EDB_OS_FILE_HH
#include "common.hh"
#include <cstddef>
namespace edb {
class File {
public:
  File();
  ~File();

  __no_move__(File);
  __no_copy__(File);

public:
  int Open(const char *filename, int options = 0);
  int Read(void *buf, size_t size, int *const len);
  int Write(const void *buf, size_t len);
  int Close();
  bool IsValid();
  void Seek(unsigned long offset);
  void Fsync();

private:
  int _fd{0};
};
} // namespace edb
#endif // EDB_OS_FILE_HH
