# bln_log
Basic thread-safe logger.

### Dependencies
* spdlog
* fmt

### Example
```c++
#include <bln_log/bln_log.h>

auto main() -> int
{
    const float n{3.14};

    bln_log("foo", 17, n);
    bln_log("bla");

    bln_dbg("just", 99, "for debugging", n);

    bln_err("oh oh");

    return 0;
}
```
