#pragma once

#include "rates/products/Trade.hpp"

namespace rates::desk {

class PnlEngine {
public:
    double daily_pnl(const products::Trade& trade) const;
};

} // namespace rates::desk
