#pragma once

namespace rates::market {

struct CurvePoint {
    double tenor_years{};
    double rate{};
};

} // namespace rates::market
