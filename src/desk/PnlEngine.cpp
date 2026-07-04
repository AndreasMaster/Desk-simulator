#include "rates/desk/PnlEngine.hpp"

namespace rates::desk {

double PnlEngine::daily_pnl(const products::Trade& trade) const
{
    (void)trade;
    return 0.0;
}

} // namespace rates::desk
