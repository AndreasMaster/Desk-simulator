#include "rates/market/YieldCurve.hpp"

#include <algorithm>
#include <stdexcept>
#include <utility>

namespace rates::market {

YieldCurve::YieldCurve(std::vector<CurvePoint> points)
    : points_(std::move(points))
{
    std::sort(points_.begin(), points_.end(), [](const CurvePoint& left, const CurvePoint& right) {
        return left.tenor_years < right.tenor_years;
    });
}

const std::vector<CurvePoint>& YieldCurve::points() const
{
    return points_;
}

double YieldCurve::zero_rate(double tenor_years) const
{
    if (points_.empty()) {
        throw std::runtime_error("Cannot get zero rate from an empty yield curve.");
    }

    if (points_.size() == 1 || tenor_years <= points_.front().tenor_years) {
        return points_.front().rate;
    }

    for (std::size_t i = 1; i < points_.size(); ++i) {
        const CurvePoint& left = points_[i - 1];
        const CurvePoint& right = points_[i];

        if (tenor_years <= right.tenor_years) {
            const double tenor_range = right.tenor_years - left.tenor_years;

            if (tenor_range == 0.0) {
                return right.rate;
            }

            const double weight = (tenor_years - left.tenor_years) / tenor_range;
            return left.rate + weight * (right.rate - left.rate);
        }
    }

    return points_.back().rate;
}

} // namespace rates::market
