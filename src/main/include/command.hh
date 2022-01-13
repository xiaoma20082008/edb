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

#ifndef EDB_COMMAND_HH
#define EDB_COMMAND_HH
namespace edb {
class Command {
public:
  virtual ~Command() = default;

  virtual int Execute();

protected:
  char snd_buf_[10];
  char rcv_buf_[10];
};
class CommandFactory {};
} // namespace edb
#endif // EDB_COMMAND_HH
