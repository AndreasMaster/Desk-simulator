#pragma once

#include "rates/core/CashFlow.hpp"
#include "rates/market/MarketData.hpp"


#include <vector>

namespace rates::products {

enum class LegType {
    Fixed,
    Floating
};

struct CouponPeriod {
    double start_time_years{};
    double end_time_years{};
    double payment_time_years{};
    double accrual{};
};

class SwapLeg {
public:
    LegType type{LegType::Fixed};
    double notional{};
    double fixed_rate{};
    double spread{};
    std::vector<CouponPeriod> periods{};

    std::vector<rates::core::CashFlow> cash_flows(
        const rates::market::MarketData& market_data
    ) const;
};

} // namespace rates::products
