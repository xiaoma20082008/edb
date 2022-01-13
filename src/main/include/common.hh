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
// Created by chunxiao ma on 2022/1/12.
//

#ifndef EDB_COMMON_HH
#define EDB_COMMON_HH
namespace edb {

#define __no_copy__(clazz)                                                                                                     \
public:                                                                                                                        \
  clazz(const clazz &) = delete;                                                                                               \
  clazz &operator=(const clazz &) = delete;

#define __no_move__(clazz)                                                                                                     \
public:                                                                                                                        \
  clazz(clazz &&) = delete;                                                                                                    \
  clazz &operator=(clazz &&) = delete;

static constexpr int EDB_OK = 0;
static constexpr int EDB_IO = -1;
static constexpr int EDB_ILLEGAL_ARGS = -2;
static constexpr int EDB_PERM = -3;
static constexpr int EDB_OOM = -4;
static constexpr int EDB_SYS = -5;
static constexpr int EDB_PMD_HELP_ONLY = -6;
static constexpr int EDB_PMD_FORCE_SYSTEM_EDU = -7;
static constexpr int EDB_TIMEOUT = -8;
static constexpr int EDB_QUIESCED = -9;
static constexpr int EDB_ILLEGAL_STATUS = -10;
static constexpr int EDB_NETWORK = -11;
static constexpr int EDB_NETWORK_CLOSE = -12;
static constexpr int EDB_APP_FORCED = -13;
static constexpr int EDB_IDX_ID_EXIST = -14;
static constexpr int EDB_HEADER_INVALID = -15;
static constexpr int EDB_IDX_ID_NOT_EXIST = -16;
static constexpr int EDB_NO_ID = -17;

} // namespace edb
#endif // EDB_COMMON_HH
