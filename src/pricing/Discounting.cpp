#include "rates/pricing/Discounting.hpp"
#include "rates/core/CashFlow.hpp"
#include "rates/market/MarketData.hpp"


namespace rates::pricing {

double Discounting::PV(const std::vector<core::CashFlow>& cf, const market::MarketData& market_data) const
{
    double pv=0;
    for ( const auto& cashflow : cf){
        pv+=cashflow.amount*market_data.discount_curve().discount_factor(cashflow.payment_time_years);
    }
return pv;
}

} // namespace rates::pricing

