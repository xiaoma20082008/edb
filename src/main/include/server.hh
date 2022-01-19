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

#ifndef EDB_SERVER_HH
#define EDB_SERVER_HH
#include "options.hh"
#include <memory>
namespace edb {
class EdbServer {
private:
  EdbServer() noexcept;
  ~EdbServer() noexcept;

  __no_copy__(EdbServer);
  __no_move__(EdbServer);

public:
  static EdbServer *GetInstance() noexcept;

  int Init(int argc, char **argv) noexcept;

  int Start() noexcept;

  int Await() noexcept;

  void Close() noexcept;

private:
  struct Impl;
  std::shared_ptr<Impl> impl_{};
};
} // namespace edb
#endif // EDB_SERVER_HH
