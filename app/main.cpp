#include "rates/io/ReportPrinter.hpp"
#include "rates/io/CsvReader.hpp"
#include "rates/market/YieldCurve.hpp"
#include "rates/market/CurvePoint.hpp"
#include "rates/market/MarketData.hpp"
#include "rates/core/CashFlow.hpp"
#include "rates/pricing/Discounting.hpp"
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
    rates::core::CashFlow cash_flow{1.5, 100.0};
    rates::pricing::Discounting discounting;
    cout << "PV cashflow: " << discounting.PV(cash_flow, market_data) << "\n";
    return 0;
}
