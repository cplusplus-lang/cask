#include <array>
#include <cask/ops/cask_new.hpp>
#include <catch2/catch_test_macros.hpp>
#include <filesystem>
#include <string_view>

namespace fs = std::filesystem;
using std::literals::string_view_literals::operator""sv;

namespace {
constexpr auto test_folder = "sandbox"sv;
const auto temp_directory_path{fs::temp_directory_path()};
}  // namespace

TEST_CASE("Create new project", "[cask_new]") {
  SECTION("Test") {
    fs::current_path(temp_directory_path);

    const char* arg1 = test_folder.data();
    char* argv[] = {const_cast<char*>(arg1)};
    int argc = sizeof(argv) / sizeof(argv[0]);

    const auto result = cask::new_::exec(std::span(argv, argc));

    REQUIRE(fs::exists(temp_directory_path / test_folder / "Cask.toml"));
    REQUIRE(fs::exists(temp_directory_path / test_folder / "src" / "main.cpp"));

    REQUIRE(result);
    REQUIRE(result->find("Created") != std::string::npos);
  }

  SECTION("CleanUp") { fs::remove_all(temp_directory_path / test_folder); }
}

TEST_CASE("No path given", "[cask_new.err.missing_path]") {
  const auto result = cask::new_::exec(std::span<char*>());

  REQUIRE(!result);
  REQUIRE(result.error().find("error:") != std::string::npos);
  REQUIRE(result.error().find("<path>") != std::string::npos);
}

TEST_CASE("Directory Exists", "[cask_new.err.existing_directory]") {
  SECTION("Test") {
    fs::current_path(temp_directory_path);

    const char* arg1 = test_folder.data();
    char* argv[] = {const_cast<char*>(arg1)};
    int argc = sizeof(argv) / sizeof(argv[0]);

    // Create folder
    fs::create_directories(temp_directory_path / test_folder);
    REQUIRE(fs::is_directory(temp_directory_path / test_folder));

    // Conflicting paths
    const auto result = cask::new_::exec(std::span(argv, argc));

    REQUIRE(!result);
    REQUIRE(result.error().find("error:") != std::string::npos);
    REQUIRE(result.error().find("already exists") != std::string::npos);
  }

  SECTION("CleanUp") { fs::remove_all(temp_directory_path / test_folder); }
}
