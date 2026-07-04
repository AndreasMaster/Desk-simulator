#pragma once

#include "rates/market/MarketData.hpp"
#include "rates/products/Trade.hpp"

namespace rates::desk {

class QuoteEngine {
public:
    double quote(const products::Trade& trade, const market::MarketData& market_data) const;
};

} // namespace rates::desk
