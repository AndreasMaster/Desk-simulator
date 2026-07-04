#include "rates/pricing/RiskCalculator.hpp"

namespace rates::pricing {

double RiskCalculator::dv01(const products::Trade& trade, const market::MarketData& market_data) const
{
    (void)trade;
    (void)market_data;
    return 0.0;
}

} // namespace rates::pricing
