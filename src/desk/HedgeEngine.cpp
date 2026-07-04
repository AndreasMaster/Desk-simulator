#include "rates/desk/HedgeEngine.hpp"

namespace rates::desk {

double HedgeEngine::hedge_notional(const products::Trade& trade) const
{
    (void)trade;
    return 0.0;
}

} // namespace rates::desk
