#pragma once

#include <span>
#include <string_view>

namespace new_cmd {

void run(const std::span<char *> args);

}  // namespace new_cmd
