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

#ifndef EDB_MSG_HH
#define EDB_MSG_HH
#include "common.hh"

namespace edb {

struct MsgHeader {
  int length_{};
  int code_{};
};
struct MsgInsert : public MsgHeader {};
struct MsgDelete : public MsgHeader {};
struct MsgUpdate : public MsgHeader {};
struct MsgSelect : public MsgHeader {};

class MsgFactory {
public:
  __no_copy__(MsgFactory);
  __no_move__(MsgFactory);

public:
  static MsgFactory *GetInstance();

  int CreateInsertMsg(char *buf, int *num, const char **obj);
  int CreateDeleteMsg(char *buf, int *num, const char **obj);
  int CreateUpdateMsg(char *buf, int *num, const char **obj);
  int CreateSelectMsg(char *buf, int *num, const char **obj);
};
} // namespace edb
#endif // EDB_MSG_HH
