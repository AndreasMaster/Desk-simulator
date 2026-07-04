#include "rates/pricing/SwapPricer.hpp"

#include <cassert>

void test_swap_pricer()
{
    const rates::pricing::SwapPricer pricer;
    const rates::products::Swap swap;
    const rates::market::MarketData market_data;

    assert(pricer.price(swap, market_data) == 0.0);
}
