#pragma once

#include <cask/util/op_result.hpp>
#include <span>

namespace cask {
namespace new_ {

[[nodiscard]] OpResult exec(const std::span<char *> args);

}  // namespace new_
}  // namespace cask
