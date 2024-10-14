#pragma once

#include <cask/util/op_result.hpp>
#include <span>

namespace cask::new_ {

[[nodiscard]] OpResult exec(const std::span<char *> args);

}  // namespace cask::new_
