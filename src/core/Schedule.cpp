#include "rates/core/Schedule.hpp"

#include <utility>

namespace rates::core {

Schedule::Schedule(std::vector<Date> dates)
    : dates_(std::move(dates))
{
}

const std::vector<Date>& Schedule::dates() const
{
    return dates_;
}

} // namespace rates::core
