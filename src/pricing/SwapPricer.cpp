#include "rates/pricing/SwapPricer.hpp"

namespace rates::pricing {

double SwapPricer::price(const products::Swap& swap, const market::MarketData& market_data) const
{
    (void)swap;
    (void)market_data;
    return 0.0;
}

} // namespace rates::pricing
