#pragma once

#include <span>
#include <string>
#include <utils/expected.hpp>

namespace new_cmd {

[[nodiscard]] Result run(const std::span<char *> args);

}  // namespace new_cmd
