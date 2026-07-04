#include "rates/pricing/Discounting.hpp"
#include "rates/core/CashFlow.hpp"
#include "rates/market/MarketData.hpp"


namespace rates::pricing {

double Discounting::PV(const std::vector<core::CashFlow>& cf, const market::MarketData& market_data) const
{
    double pv=0;
return cf.amount*market_data.discount_curve().discount_factor(cf.payment_time_years);
}

} // namespace rates::pricing

