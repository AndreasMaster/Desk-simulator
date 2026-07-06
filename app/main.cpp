#include "rates/io/ReportPrinter.hpp"
#include "rates/io/CsvReader.hpp"
#include "rates/market/YieldCurve.hpp"
#include "rates/market/CurvePoint.hpp"
#include "rates/market/MarketData.hpp"
#include "rates/core/CashFlow.hpp"
#include "rates/pricing/Discounting.hpp"
#include "rates/products/Swap.hpp"
#include "rates/pricing/SwapPricer.hpp"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    rates::io::ReportPrinter printer;
    printer.print_line(std::cout, "Rates Desk Simulator");
    rates::io::CsvReader reader;
    auto rows = reader.read("data/eur_curve.csv");
    vector<rates::market::CurvePoint> points;
    for (size_t i=1;i<rows.size();i++)
    {
        rates::market::CurvePoint curve_point;
        curve_point.tenor_years = stod(rows[i][0]);
        curve_point.rate = stod(rows[i][1]);
        points.push_back(curve_point);
    }
    rates::market::YieldCurve yield_curve(points);
    cout << "interpoleret rente: "<<yield_curve.zero_rate(1.5)<<"\n";
    cout << "discount factor : "<<yield_curve.discount_factor(1.5)<<"\n";
    rates::market::MarketData market_data(std::move(yield_curve));
    rates::products::Swap swap;
    swap.receive_leg.type = rates::products::LegType::Floating;
    swap.receive_leg.spread = 0.005;
    swap.receive_leg.notional = 100.0;
    swap.receive_leg.periods = {
        {0.0, 1.0, 1.0, 1.0},
        {1.0, 2.0, 2.0, 1.0},
        {2.0, 3.0, 3.0, 1.0}
    };

    swap.pay_leg.type = rates::products::LegType::Fixed;
    swap.pay_leg.fixed_rate = 0.025;
    swap.pay_leg.notional = 100.0;
    swap.pay_leg.periods = swap.receive_leg.periods;

    rates::pricing::SwapPricer pricer;
    double swap_pv = pricer.price(swap,market_data);
    cout << "Swap PV: "<<swap_pv<<"\n";
    return 0;
}
