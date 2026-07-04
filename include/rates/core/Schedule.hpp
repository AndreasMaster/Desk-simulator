#pragma once

#include "rates/core/Date.hpp"

#include <vector>

namespace rates::core {

class Schedule {
public:
    Schedule() = default;
    explicit Schedule(std::vector<Date> dates);

    const std::vector<Date>& dates() const;

private:
    std::vector<Date> dates_{};
};

} // namespace rates::core
