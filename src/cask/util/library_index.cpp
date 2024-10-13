#include <fmt/core.h>

#include <cask/util/library_index.hpp>

namespace library_index {

const std::unordered_map<std::string_view, Library> Libraries::libraries = {
    {"fmt",
     {"11.0.2", "fmt::fmt",
      [](const std::string& version) {
        return fmt::format(R"(CPMAddPackage("gh:fmtlib/fmt#{version}"))",
                           fmt::arg("version", version));
      }}},
    {"tomlplusplus",
     {"3.4.0", "tomlplusplus::tomlplusplus", [](const std::string& version) {
        return fmt::format(
            R"(CPMAddPackage("gh:marzer/tomlplusplus#{version}"))",
            fmt::arg("version", version));
      }}}};

}  // namespace library_index