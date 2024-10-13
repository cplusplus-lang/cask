#pragma once

#include <cask/util/expected.hpp>
#include <span>
#include <string>

namespace new_cmd {

[[nodiscard]] Result run(const std::span<char *> args);

}  // namespace new_cmd
