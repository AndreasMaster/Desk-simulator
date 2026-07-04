#pragma once

#include "rates/market/YieldCurve.hpp"

namespace rates::market {

class MarketData {
public:
    MarketData() = default;
    explicit MarketData(YieldCurve discount_curve);

    const YieldCurve& discount_curve() const;

private:
    YieldCurve discount_curve_{};
};

} // namespace rates::market
