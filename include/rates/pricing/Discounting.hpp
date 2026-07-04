#pragma once

#include "rates/market/MarketData.hpp"
#include "rates/core/CashFlow.hpp"

namespace rates::pricing {

class Discounting {
public:
    double PV(
    const std::vector<core::CashFlow>& cash_flows,
    const market::MarketData& market_data
) const;
};

} // namespace rates::pricing
