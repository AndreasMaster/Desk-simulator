#include "rates/desk/QuoteEngine.hpp"

namespace rates::desk {

double QuoteEngine::quote(const products::Trade& trade, const market::MarketData& market_data) const
{
    (void)trade;
    (void)market_data;
    return 0.0;
}

} // namespace rates::desk
