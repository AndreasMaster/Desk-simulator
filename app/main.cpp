#include "rates/io/ReportPrinter.hpp"
#include "rates/io/CsvReader.hpp"
#include "rates/market/YieldCurve.hpp"
#include "rates/market/CurvePoint.hpp"
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
    return 0;
}
