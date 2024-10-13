#include <fmt/color.h>

#include <cask/ops/cask_build.hpp>
#include <cask/ops/cask_run.hpp>
#include <cassert>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <string_view>
#include <toml++/toml.hpp>

namespace fs = std::filesystem;

namespace run {

void run() {
  build::run();

  std::string project_name{};

  const fs::path path{fs::current_path()};

  try {
    auto config = toml::parse_file((path / "Cask.toml").string().c_str());

    if (auto package = config["package"].as_table()) {
      // Access the 'name' key and ensure it's a string
      if (auto name = package->get("name")->value<std::string_view>()) {
        project_name = *name;
        std::cout << "Project name: " << project_name << std::endl;
      } else {
        std::cerr << "'name' is not a valid string" << std::endl;
      }
    } else {
      std::cerr << "[package] table not found" << std::endl;
    }
  } catch (const toml::parse_error& err) {
    // std::cerr << "Parsing failed: " << err << std::endl;
    return;
  }

  const auto command{
      (path / "target" / "debug" / "build" / project_name).string()};

  std::system(command.c_str());
}

}  // namespace run
