#pragma once

#include "rates/market/MarketData.hpp"
#include "rates/products/Swap.hpp"

namespace rates::pricing {

class SwapPricer {
public:
    double price(const products::Swap& swap, const market::MarketData& market_data) const;
};

} // namespace rates::pricing
