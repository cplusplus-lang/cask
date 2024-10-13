#include <array>
#include <catch2/catch_test_macros.hpp>
#include <filesystem>
#include <utils/filesystem.hpp>

namespace fs = std::filesystem;

TEST_CASE("Filesystem") {
  const auto path{fs::temp_directory_path()};

  fs::current_path(path);

  SECTION("Ofstream") {
    const auto folder = path / "sandbox";

    fs::create_directories(folder);

    auto file = filesystem::ofstream(folder / "test.cpp");

    REQUIRE(file);
    REQUIRE(file->is_open());
  }

  SECTION("ErrorOfstreamCreation") {
    const fs::path folder{"/non_existing"};

    auto file = filesystem::ofstream(folder / "test.cpp");

    REQUIRE(!file);
    REQUIRE(!file.error());
    REQUIRE(file.error().error().find("error:") != std::string::npos);
    REQUIRE(file.error().error().find("couĺd not create file") !=
            std::string::npos);
  }

  SECTION("CleanUp") { fs::remove_all(path / "sandbox"); }
}
