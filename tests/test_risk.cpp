#include "rates/pricing/RiskCalculator.hpp"

#include <cassert>

void test_risk()
{
    const rates::pricing::RiskCalculator risk_calculator;
    const rates::products::Trade trade;
    const rates::market::MarketData market_data;

    assert(risk_calculator.dv01(trade, market_data) == 0.0);
}
