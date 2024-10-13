#include <fmt/core.h>

#include <commands/help.hpp>
#include <string>
#include <utils/expected.hpp>
#include <utils/filesystem.hpp>

namespace {
[[nodiscard]] Result error_could_not_open_file(const fs::path file) {
  return help::fatal_error(fmt::format(
      R"(couĺd not create file `{}`
)",
      fs::absolute(file).string()));
}
}  // namespace

namespace filesystem {

std_26::expected<std::ofstream, Result> ofstream(const fs::path path) {
  std::ofstream stream(path);

  if (!stream.is_open()) {
    return std_26::unexpected(error_could_not_open_file(path));
  }

  return stream;
}
}  // namespace filesystem