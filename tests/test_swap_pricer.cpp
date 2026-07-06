#include "rates/pricing/SwapPricer.hpp"
#include "rates/market/YieldCurve.hpp"

#include <cassert>

void test_swap_pricer()
{
    const rates::pricing::SwapPricer pricer;
    rates::products::Swap swap;
    const rates::market::MarketData market_data(
        rates::market::YieldCurve({
            {1.0, 0.0}
        })
    );

    swap.receive_leg.notional = 100.0;
    swap.receive_leg.fixed_rate = 0.05;
    swap.receive_leg.periods = {
        {0.0, 1.0, 1.0, 1.0}
    };

    swap.pay_leg.notional = 100.0;
    swap.pay_leg.fixed_rate = 0.03;
    swap.pay_leg.periods = {
        {0.0, 1.0, 1.0, 1.0}
    };

    assert(pricer.price(swap, market_data) == 2.0);
}
