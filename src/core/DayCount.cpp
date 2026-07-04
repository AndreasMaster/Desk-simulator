#include "rates/core/DayCount.hpp"

namespace rates::core {

double DayCount::year_fraction(Date start, Date end, DayCountConvention convention) const
{
    (void)start;
    (void)end;
    (void)convention;
    return 0.0;
}

} // namespace rates::core
