#pragma once

#include "rates/products/Trade.hpp"

namespace rates::desk {

class HedgeEngine {
public:
    double hedge_notional(const products::Trade& trade) const;
};

} // namespace rates::desk
