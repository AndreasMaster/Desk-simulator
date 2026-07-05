#include "rates/pricing/SwapPricer.hpp"
#include "rates/pricing/Discounting.hpp"

namespace rates::pricing {

double SwapPricer::price(const products::Swap& swap, const market::MarketData& market_data) const
{
    Discounting discounting;
    const double receiver_pv = discounting.PV(swap.receive_leg.cash_flows,market_data);
    const double payer_pv = discounting.PV(swap.pay_leg.cash_flows,market_data);
    return receiver_pv-payer_pv;
}

} // namespace rates::pricing
