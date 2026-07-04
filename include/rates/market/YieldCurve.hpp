#pragma once

#include "rates/market/CurvePoint.hpp"

#include <vector>

namespace rates::market {

class YieldCurve {
public:
    YieldCurve() = default;
    explicit YieldCurve(std::vector<CurvePoint> points);

    const std::vector<CurvePoint>& points() const;

    double zero_rate(double tenor_years) const;

    double discount_factor(double tenor_years) const;

private:
    std::vector<CurvePoint> points_{};
};

} // namespace rates::market
