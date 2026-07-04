#include "rates/market/MarketData.hpp"

#include <utility>

namespace rates::market {

MarketData::MarketData(YieldCurve discount_curve)
    : discount_curve_(std::move(discount_curve))
{
}

const YieldCurve& MarketData::discount_curve() const
{
    return discount_curve_;
}

} // namespace rates::market
