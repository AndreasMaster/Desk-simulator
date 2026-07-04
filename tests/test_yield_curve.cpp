#include "rates/market/YieldCurve.hpp"

#include <cassert>

void test_swap_pricer();
void test_quote_engine();
void test_risk();

namespace {

void test_yield_curve_starts_empty()
{
    const rates::market::YieldCurve curve;
    assert(curve.points().empty());
}

} // namespace

int main()
{
    test_yield_curve_starts_empty();
    test_swap_pricer();
    test_quote_engine();
    test_risk();

    return 0;
}
