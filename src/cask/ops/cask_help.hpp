#pragma once

#include <fmt/color.h>

#include <cask/util/op_result.hpp>
#include <span>
#include <string_view>

namespace help {

constexpr fmt::color blue{fmt::color::deep_sky_blue};
constexpr fmt::color green{fmt::color::light_green};
constexpr fmt::color red{fmt::color::red};

void run();
void run(const std::span<char *> args);
void list();
[[nodiscard]] OpResult fatal_error(const std::string_view msg);

}  // namespace help
