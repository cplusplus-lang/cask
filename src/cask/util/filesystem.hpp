#pragma once

#include <cask/util/op_result.hpp>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

namespace filesystem {
[[nodiscard]] std_26::expected<std::ofstream, OpResult> ofstream(
    const fs::path path);
}
