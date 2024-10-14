#pragma once

#include <fmt/color.h>

#include <cask/util/op_result.hpp>
#include <string_view>

namespace cask::util::io {

constexpr fmt::color blue{fmt::color::deep_sky_blue};
constexpr fmt::color green{fmt::color::light_green};
constexpr fmt::color red{fmt::color::red};

[[nodiscard]] OpResult fatal_error(const std::string_view msg);

}  // namespace cask::util::io
