#pragma once

#include "rates/core/Date.hpp"

namespace rates::core {

enum class DayCountConvention {
    Act360,
    Act365F,
    Thirty360
};

class DayCount {
public:
    double year_fraction(Date start, Date end, DayCountConvention convention) const;
};

} // namespace rates::core
