#pragma once

#include "rates/core/Date.hpp"

namespace rates::core {

struct CashFlow {
    Date payment_date{};
    double amount{};
};

} // namespace rates::core
