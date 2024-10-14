#include <fmt/core.h>

#include <cask/util/expected.hpp>
#include <cask/util/io.hpp>
#include <string_view>

namespace cask::util::io {

OpResult fatal_error(const std::string_view msg) {
  return std_26::unexpected(fmt::format(
      R"({} {})",
      fmt::format(fg(cask::util::io::red) | fmt::emphasis::bold, "error:"),
      msg));
}

}  // namespace cask::util::io
