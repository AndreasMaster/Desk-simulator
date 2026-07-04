#pragma once

#include "rates/core/CashFlow.hpp"

#include <vector>

namespace rates::products {

enum class LegType {
    Fixed,
    Floating
};

class SwapLeg {
public:
    std::vector<rates::core::CashFlow> cash_flows{};
};

} // namespace rates::products
