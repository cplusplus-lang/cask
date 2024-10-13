#include <array>
#include <cask/commands/new.hpp>
#include <catch2/catch_test_macros.hpp>
#include <filesystem>

namespace fs = std::filesystem;

TEST_CASE("New") {
  const auto path{fs::temp_directory_path()};

  fs::current_path(path);

  SECTION("New") {
    const char* arg1 = "sandbox";
    char* argv[] = {const_cast<char*>(arg1)};
    int argc = sizeof(argv) / sizeof(argv[0]);

    const auto result = new_cmd::run(std::span(argv, argc));

    REQUIRE(fs::exists(path / "sandbox" / "Cask.toml"));
    REQUIRE(fs::exists(path / "sandbox" / "src" / "main.cpp"));

    REQUIRE(result);
    REQUIRE(result->find("Created") != std::string::npos);
  }

  SECTION("ErrorMissingPath") {
    const auto result = new_cmd::run(std::span<char*>());

    REQUIRE(!result);
    REQUIRE(result.error().find("error:") != std::string::npos);
    REQUIRE(result.error().find("<path>") != std::string::npos);
  }

  SECTION("ErrorExistingDirectory") {
    const char* arg1 = "sandbox";
    char* argv[] = {const_cast<char*>(arg1)};
    int argc = sizeof(argv) / sizeof(argv[0]);

    const auto result = new_cmd::run(std::span(argv, argc));

    REQUIRE(!result);
    REQUIRE(result.error().find("error:") != std::string::npos);
    REQUIRE(result.error().find("already exists") != std::string::npos);
  }

  SECTION("CleanUp") { fs::remove_all(path / "sandbox"); }
}
