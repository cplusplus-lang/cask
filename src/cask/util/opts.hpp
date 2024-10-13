#pragma once

#include <cask/util/expected.hpp>
#include <optional>
#include <string>

namespace opts {

enum class Command { Add, Build, Help, List, New, Run };

namespace command {
[[nodiscard]] std_26::expected<Command, std::string> from_str(
    const std::string_view str);
}

}  // namespace opts
