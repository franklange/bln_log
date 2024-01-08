#include <bln_log/bln_log.h>

#include <thread>

auto main() -> int
{
    const float n{3.14};

    bln_log("foo", 17, n);
    bln_log("bla");

    bln_dbg("just", 99, "for debugging", n);

    bln_err("oh oh");

    return 0;
}
