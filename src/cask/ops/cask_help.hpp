#pragma once

#include <cask/util/op_result.hpp>
#include <span>
#include <string_view>

namespace help {

void run();
void run(const std::span<char *> args);
void list();

}  // namespace help
