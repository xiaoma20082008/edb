# edb

A Mini Database Engine

## Features

- [ ] Client/Server based on [Asio](https://github.com/chriskohlhoff/asio.git)
- [ ] Transaction Manager
- [ ] Index Manager
- [ ] Page Manager
- [ ] File Manager

## Build

```shell
cd ~
git clone https://github.com/xiaoma20082008/emeralddb.git edb
cd edb
mkdir -p build/Debug && cd build/Debug && cmake ../.. && make
```

## Credit

* Network using [Asio](https://github.com/chriskohlhoff/asio.git)
* Logging using [SPDLOG](https://github.com/google/googletest.git)
* Test using [GTEST](https://github.com/gabime/spdlog.git)