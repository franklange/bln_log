#include <bln_log/log.hpp>

#define log(args...) bln_log_rel(args)
#define dbg(args...) bln_log_dbg(args)

#include <fstream>

auto main() -> int
{
    std::ofstream logFile{"my.log"};

    float n{97.2};

    log("foo", 3, n);
    log("bla");
    log(std::cerr, "sdfsdfsd");
    log(logFile, "[MYTAG]", n, "fspfokdsfksdkfs");

    dbg("just", 99, "for debugging", n);

    return 0;
}
