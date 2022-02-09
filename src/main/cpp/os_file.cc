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

#include "os_file.hh"
#include <cstdio>
#include <cstring>
#include <fcntl.h>
#include <unistd.h>
namespace edb {
File::File() {}
File::~File() { Close(); }
int File::Open(const char *filename, int options) {
  int ret = 0;
  int mode = O_RDWR;
  if ((options & O_RDONLY) > 0) {
  } else if ((mode & O_WRONLY) > 0) {
  } else if ((mode & O_RDWR) > 0) {
  }
  _fd = open(filename, mode);
  if (_fd <= 0) {
    ret = -1;
  }
  return ret;
}
int File::Read(void *buf, size_t size, int *const len) {
  ssize_t s = read(_fd, buf, size);
  if (len != nullptr) {
    *len = s;
  }
  return s;
}
int File::Write(const void *buf, size_t len) {
  if (len <= 0) {
    len = strlen(static_cast<const char *>(buf));
  }
  ssize_t s = write(_fd, buf, len);
  return s;
}
void File::Seek(unsigned long offset) { lseek(_fd, offset, SEEK_CUR); }
bool File::IsValid() { return _fd >= 0; }
void File::Fsync() { fsync(_fd); }
int File::Close() {
  int ret = 0;
  if (_fd > 0) {
    ret = close(_fd);
    _fd = 0;
  }
  return ret;
}

} // namespace edb