#include <array>
#include <cask/ops/cask_build.hpp>
#include <cask/ops/cask_new.hpp>
#include <catch2/catch_test_macros.hpp>
#include <filesystem>

namespace fs = std::filesystem;

TEST_CASE("Build", "BuildProject") {
  const auto path{fs::temp_directory_path()};

  fs::current_path(path);

  SECTION("New") {
    const char* arg1 = "sandbox";
    char* argv[] = {const_cast<char*>(arg1)};
    int argc = sizeof(argv) / sizeof(argv[0]);

    cask::new_::exec(std::span(argv, argc));

    REQUIRE(fs::exists(path / "sandbox" / "Cask.toml"));
    REQUIRE(fs::exists(path / "sandbox" / "src" / "main.cpp"));
  }

  SECTION("Run") {
    fs::current_path(path / "sandbox");
    cask::build::exec();

    fs::current_path(path / "sandbox" / "target" / "debug" / "build");

    REQUIRE(fs::exists(path / "sandbox" / "target" / "debug" / "build"));
    // REQUIRE(fs::exists(path / "sandbox" / "target" / "debug" / "build" /
    //                    "Makefile"));
    //  REQUIRE(fs::exists(path / "sandbox" / "target" / "debug" / "build" /
    //                     "sandbox"));
  }

  SECTION("CleanUp") { fs::remove_all(path / "sandbox"); }
}
