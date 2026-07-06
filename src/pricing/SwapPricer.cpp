#include "rates/pricing/SwapPricer.hpp"
#include "rates/pricing/Discounting.hpp"
#include "rates/products/SwapLeg.hpp"
#include "rates/core/CashFlow.hpp"

namespace rates::pricing {

double SwapPricer::price(const products::Swap& swap, const market::MarketData& market_data) const
{
    Discounting discounting;
    auto receive_cashflows = swap.receive_leg.cash_flows(market_data);
    auto pay_cashflows = swap.pay_leg.cash_flows(market_data);

    return discounting.PV(receive_cashflows, market_data)
        - discounting.PV(pay_cashflows, market_data);
}

double SwapPricer::par_rate(const products::Swap& swap, const market::MarketData& market_data) const
{
const auto& curve = market_data.discount_curve();
   double numerator = (curve.discount_factor(swap.pay_leg.periods.front().payment_time_years)-curve.discount_factor(swap.pay_leg.periods.back().payment_time_years));
   std::vector< rates::core::CashFlow> cash_flows;
   for (const auto& period: swap.receive_leg.periods){
    rates::core::CashFlow cash_flow;
    cash_flow.amount=1;
    cash_flow.payment_time_years=period.payment_time_years;
    cash_flows.push_back(cash_flow);
   }
if (swap.receive_leg.type==rates::products::LegType::Floating)
{
   numerator = (curve.discount_factor(swap.receive_leg.periods.front().payment_time_years)-curve.discount_factor(swap.receive_leg.periods.back().payment_time_years));
   std::vector< rates::core::CashFlow> cash_flows;
   cash_flows.clear();
   for (const auto& period: swap.pay_leg.periods){
    rates::core::CashFlow cash_flow;
    cash_flow.amount=1;
    cash_flow.payment_time_years=period.payment_time_years;
    cash_flows.push_back(cash_flow);
   }
}
Discounting discounting;
double denominator = rates::pricing::Discounting::PV(cash_flows,market_data);
return numerator/denominator;
}

} // namespace rates::pricing
