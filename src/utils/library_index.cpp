//              Copyright Cask Authors
// Distributed under the Boost Software License, Version 1.0.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.boost.org/LICENSE_1_0.txt)

// SPDX-License-Identifier: BSL-1.0

#include <fmt/core.h>

#include <utils/library_index.hpp>

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