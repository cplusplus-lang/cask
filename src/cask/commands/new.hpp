#pragma once

#include <cask/utils/expected.hpp>
#include <span>
#include <string>

namespace new_cmd {

[[nodiscard]] Result run(const std::span<char *> args);

}  // namespace new_cmd
