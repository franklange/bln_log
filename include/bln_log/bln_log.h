#pragma once

#include <string>
#include <sstream>
#include <utility>

template <typename... Ts>
auto stringify(Ts&&... ts) -> std::string
{
    std::stringstream s;
    ((s << std::forward<Ts>(ts) << " "), ...);
    return s.str();
}

#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#include <spdlog/spdlog.h>

#define bln_log(args, ...) SPDLOG_TRACE(stringify(args))
#define bln_dbg(args, ...) SPDLOG_DEBUG(stringify(args))
#define bln_err(args, ...) SPDLOG_ERROR(stringify(args))

#ifndef NDEBUG
struct Log
{
    Log()
    {
        spdlog::set_level(spdlog::level::trace);
        spdlog::set_pattern("[%H:%M:%S.%e] [%l] %v %$");
    }
};

Log g_log{};
#endif
