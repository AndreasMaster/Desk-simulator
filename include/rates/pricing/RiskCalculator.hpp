#pragma once

#include "rates/market/MarketData.hpp"
#include "rates/products/Trade.hpp"

namespace rates::pricing {

class RiskCalculator {
public:
    double dv01(const products::Trade& trade, const market::MarketData& market_data) const;
};

} // namespace rates::pricing
