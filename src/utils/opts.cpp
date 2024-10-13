#include <fmt/core.h>

#include <commands/help.hpp>
#include <string>
#include <string_view>
#include <unordered_map>
#include <utils/opts.hpp>

namespace opts::command {

namespace {
Result unknown_command(std::string_view command) {
  return help::fatal_error(fmt::format(R"(no such command: `{}`

       View all installed commands with `cask --list`
)",
                                       command));
}
}  // namespace

std_26::expected<Command, std::string> from_str(const std::string_view str) {
  static const std::unordered_map<std::string_view, Command> command_map{
      {"add", Command::Add},    {"--help", Command::Help},
      {"help", Command::Help},  {"--list", Command::List},
      {"new", Command::New},    {"run", Command::Run},
      {"build", Command::Build}};

  if (auto it{command_map.find(str)}; it != command_map.end()) {
    return it->second;
  } else {
    return std_26::unexpected(unknown_command(str).error());
  }
}

}  // namespace opts::command
