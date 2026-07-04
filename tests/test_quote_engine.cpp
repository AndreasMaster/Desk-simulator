#include "rates/desk/QuoteEngine.hpp"

#include <cassert>

void test_quote_engine()
{
    const rates::desk::QuoteEngine quote_engine;
    const rates::products::Trade trade;
    const rates::market::MarketData market_data;

    assert(quote_engine.quote(trade, market_data) == 0.0);
}
