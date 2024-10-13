#include <fmt/core.h>

#include <cask/ops/cask_help.hpp>
#include <cask/util/expected.hpp>
#include <cask/util/filesystem.hpp>
#include <string>

namespace {
[[nodiscard]] OpResult error_could_not_open_file(const fs::path file) {
  return help::fatal_error(fmt::format(
      R"(couĺd not create file `{}`
)",
      fs::absolute(file).string()));
}
}  // namespace

namespace filesystem {

std_26::expected<std::ofstream, OpResult> ofstream(const fs::path path) {
  std::ofstream stream(path);

  if (!stream.is_open()) {
    return std_26::unexpected(error_could_not_open_file(path));
  }

  return stream;
}
}  // namespace filesystem