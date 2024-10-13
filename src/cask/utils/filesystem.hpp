#pragma once

#include <cask/utils/expected.hpp>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

namespace filesystem {
[[nodiscard]] std_26::expected<std::ofstream, Result> ofstream(
    const fs::path path);
}
