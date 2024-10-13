#pragma once

#include <optional>
#include <string>
#include <utils/expected.hpp>

namespace opts {

enum class Command { Add, Build, Help, List, New, Run };

namespace command {
[[nodiscard]] std_26::expected<Command, std::string> from_str(
    const std::string_view str);
}

}  // namespace opts
