#pragma once

#include <chrono>
#include <iostream>
#include <mutex>
#include <string>

#if BLN_LOG_DBG
    #define bln_log_dbg(args...) bln_log::println(args)
#else
    #define bln_log_dbg(...) (void)0
#endif

#define bln_log_rel(args...) bln_log::println(args)

namespace bln_log {

inline auto timestamp() -> std::string
{
    using namespace std::chrono;
    const auto now = system_clock::to_time_t(system_clock::now());

    std::string s(24, '\0');
    std::strftime(&s[0], s.size(), "[%F %T] ", std::localtime(&now));

    return s;
}

template <typename S, typename... Ts, typename = std::enable_if_t<std::is_base_of_v<std::ostream, S>>>
void println(S& o, Ts&&... ts)
{
#if BLN_LOG_MT
    static std::mutex m;
    std::lock_guard<std::mutex> lock{m};
#endif

    o << timestamp();
    ((o << std::forward<Ts>(ts) << " "), ...);
    o << std::endl;
}

template <typename... Ts>
void println(Ts&&... ts)
{
    println(std::cout, std::forward<Ts>(ts)...);
}

} // namespace bln_log
