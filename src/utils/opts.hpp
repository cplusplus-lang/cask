#pragma once

#include <optional>
#include <string>

namespace opts {

enum class Command { Add, Build, Help, List, New, Run };

namespace command {
Command from_str(const std::string_view str);
}

}  // namespace opts
