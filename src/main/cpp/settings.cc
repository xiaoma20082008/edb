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
// Created by chunxiao ma on 2022/2/7.
//

#include "settings.hh"
#include <cstdlib>
#include <cstring>
namespace edb {
static constexpr int TRUE_SIZE = 7;
static constexpr const char *TRUE_VALUES[TRUE_SIZE] = {"y", "Y", "yes", "YES", "on", "ON", "1"};
static constexpr const char *FALSE_VALUES[TRUE_SIZE] = {"n", "N", "no", "NO", "off", "OFF", "0"};

Settings::Settings(int argc, char **argv) { ParseArgs(argc, argv); }
long Settings::GetLong(const char *key) const {
  long ret = 0L;
  const char *val = GetString(key);
  if (val != nullptr) {
    ret = atol(val);
  }
  return ret;
}
int Settings::GetInt(const char *key) const {
  int ret = 0L;
  const char *val = GetString(key);
  if (val != nullptr) {
    ret = atoi(val);
  }
  return ret;
}
bool Settings::GetBool(const char *key) const {
  bool ret{false};
  const char *val = GetString(key);
  if (val != nullptr) {
    for (int i = 0; i < TRUE_SIZE; ++i) {
      bool should_break = false;
      if (strcmp(val, TRUE_VALUES[i]) == 0) {
        ret = true;
        should_break = true;
      } else if (strcmp(val, FALSE_VALUES[i]) == 0) {
        ret = false;
        should_break = true;
      }
      if (should_break) {
        break;
      }
    }
  }
  return ret;
}
const char *Settings::GetString(const char *key) const {
  const char *ret{nullptr};
  auto it = _data.find(key);
  if (it == _data.end()) {
    ret = it->second;
  }
  return ret;
}
void Settings::ParseArgs(int argc, char **argv) {
  for (int i = 0; i < argc; i += 2) {
    // --key val
    char *key = argv[i];
    char *val = argv[i + 1];
    _data.insert({key, val});
  }
}
void Settings::ParseFile(const char *file) {}
} // namespace edb