# bln_log
Basic logger.

```c++
#include <bln_log/log.hpp>

#define log(args...) bln_log_rel(args)
#define dbg(args...) bln_log_dbg(args)

#include <fstream>

auto main() -> int
{
    std::ofstream logFile{"my.log"};

    float value{97.2};

    log("hi");
    log(std::cerr, value, "oh oh");
    dbg(logFile, "lots of", value)
    dbg("just", 99, "for debugging", value);

    return 0;
}
```

### Build
Compile flags to be used in your cmake/gcc calls:
* `BLN_LOG_DBG` enables the `bln_log_dbg` macro (default: off)
* `BLN_LOG_MT` adds thread-safe locking to every log call (default: off)

Example:
```bash
g++ -std=c++2b -Wall -DBLN_LOG_DBG -DBLN_LOG_MT main.cpp
```
or in cmake
```cmake
target_compile_definitions(${PROJECT_NAME} PRIVATE BLN_LOG_MT)
```