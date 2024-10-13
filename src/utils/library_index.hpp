#pragma once

#include <functional>
#include <optional>
#include <span>
#include <string>
#include <unordered_map>

namespace library_index {

struct Library {
  std::string_view last_version;
  std::string_view link_id;
  std::function<std::string(const std::string&)> package_include;
};

class Libraries {
 public:
  static const std::optional<Library> find(std::string_view key) {
    if (auto it{libraries.find(key)}; it != libraries.end()) {
      return it->second;
    }

    return std::nullopt;
  }

 private:
  static const std::unordered_map<std::string_view, Library> libraries;
};

}  // namespace library_index
