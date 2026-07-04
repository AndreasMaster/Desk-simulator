#pragma once

#include "rates/core/Schedule.hpp"

namespace rates::products {

enum class LegType {
    Fixed,
    Floating
};

class SwapLeg {
public:
    LegType type{LegType::Fixed};
    rates::core::Schedule schedule{};
    double notional{};
    double rate{};
};

} // namespace rates::products
