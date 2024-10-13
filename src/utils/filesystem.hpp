#pragma once

#include <filesystem>
#include <fstream>
#include <utils/expected.hpp>

namespace fs = std::filesystem;

namespace filesystem {
[[nodiscard]] std_26::expected<std::ofstream, Result> ofstream(
    const fs::path path);
}
