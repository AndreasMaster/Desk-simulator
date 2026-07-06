#include "rates/products/SwapLeg.hpp"
#include "rates/core/CashFlow.hpp"
using namespace std;

namespace rates::products {

    std::vector<rates::core::CashFlow> SwapLeg::cash_flows(
        const rates::market::MarketData& market_data) const
    {

        vector<rates::core::CashFlow> result;
        for (const auto& period : periods){
                double rate = fixed_rate;
                if (type==LegType::Floating) {
                    const auto& curve = market_data.discount_curve();
                    rate = ((curve.discount_factor(period.start_time_years)/curve.discount_factor(period.end_time_years))-1)/period.accrual;
                }
                rates::core::CashFlow cash_flow;
                cash_flow.amount = (rate + spread ) * notional*period.accrual;
                cash_flow.payment_time_years = period.payment_time_years;
                result.push_back(cash_flow);
            }
        return result;
    }
} 