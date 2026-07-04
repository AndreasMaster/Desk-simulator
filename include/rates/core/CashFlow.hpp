#pragma once

#include "rates/core/Date.hpp"

namespace rates::core {

struct CashFlow {
    double payment_time_years{};
    double amount{};
};

} // namespace rates::core
