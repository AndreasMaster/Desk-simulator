#pragma once

#include "rates/products/SwapLeg.hpp"

namespace rates::products {

class Swap {
public:
    SwapLeg pay_leg{};
    SwapLeg receive_leg{};
};

} // namespace rates::products
