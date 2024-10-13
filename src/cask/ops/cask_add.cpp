#include <fmt/color.h>
#include <fmt/core.h>

#include <cask/ops/cask_add.hpp>
#include <cask/ops/cask_help.hpp>
#include <cask/util/library_index.hpp>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string_view>
#include <toml++/toml.hpp>
#include <unordered_map>

namespace fs = std::filesystem;

namespace add {

namespace {
void error_missing_argument() {
  help::fatal_error(fmt::format(
      R"(the following required arguments were not provided:
{}

{} {} {}

For more information, try '{}'
)",
      fmt::format(fg(help::blue) | fmt::emphasis::bold, "  <DEP_ID>"),
      fmt::format(fg(help::green) | fmt::emphasis::bold, "Usage:"),
      fmt::format(fg(help::blue) | fmt::emphasis::bold, "cask add"),
      fmt::format(fg(help::blue), "<DEP>[@VERSION]"),
      fmt::format(fg(help::blue) | fmt::emphasis::bold, "--help")));
  exit(EXIT_FAILURE);
}

void error_unknown_command(const std::string_view library) {
  help::fatal_error(fmt::format(
      R"(the library `{}` could not be found in registry index.
)",
      library));
  exit(EXIT_FAILURE);
}

}  // namespace

void run(const std::span<char *> args) {
  if (args.empty()) {
    error_missing_argument();
  }

  const auto library_id = args[0];

  if (auto library = library_index::Libraries::find(args[0]); library) {
    const fs::path path{fs::current_path()};

    if (!fs::exists(path / "Cask.toml")) {
      fmt::print(fg(fmt::color::red) | fmt::emphasis::bold, "error:");
      std::cout << "could not find `Cask.toml` in " << fs::absolute(path)
                << " or any parent directory" << std::endl;
      return;
    }

    auto config = toml::parse_file((path / "Cask.toml").string().c_str());
    auto dependencies = config["dependencies"].as_table();

    if (!dependencies) {
      config.insert("dependencies", toml::table{});
      dependencies = config["dependencies"].as_table();
    }

    if (auto name_node = dependencies->get(library_id)) {
    } else {
      dependencies->insert(library_id, library->last_version);

      std::ofstream cask_file(path / "Cask.toml");

      cask_file << "[package]\n";
      cask_file << config["package"];
      cask_file << "\n\n[dependencies]\n";
      cask_file << config["dependencies"];

      cask_file.close();
    }

    fmt::print(
        R"(      {} {} v{} to dependencies
)",
        fmt::format(fg(help::green) | fmt::emphasis::bold, "Adding"),
        library_id, library->last_version);
  } else {
    error_unknown_command(library_id);
  }
}

}  // namespace add
