#pragma once

#include <cstdint>

namespace rates::core {

struct Date {
    std::int32_t year{};
    std::uint32_t month{};
    std::uint32_t day{};
};

} // namespace rates::core
