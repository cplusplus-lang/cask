#include <cask/ops/cask_add.hpp>
#include <cask/ops/cask_build.hpp>
#include <cask/ops/cask_help.hpp>
#include <cask/ops/cask_new.hpp>
#include <cask/ops/cask_run.hpp>
#include <cask/util/op_result.hpp>
#include <cask/util/opts.hpp>
#include <iostream>
#include <span>
#include <string_view>
#include <vector>

namespace {
const std::span<char*> cmd_args(const std::span<char*> args) {
  return args.subspan(1, args.size() - 1);
}
}  // namespace

int main(int ac, char* av[]) {
  const auto args = std::span(av + 1, ac - 1);

  if (args.empty()) {
    help::run();
    exit(EXIT_FAILURE);
  }

  const auto command{opts::command::from_str(args[0])};

  if (!command) {
    std::cout << command.error();
    exit(EXIT_FAILURE);
  }

  OpResult result{};

  switch (*command) {
    case opts::Command::Add: {
      add::run(cmd_args(args));
      break;
    }
    case opts::Command::Help: {
      help::run(cmd_args(args));
      break;
    }
    case opts::Command::List: {
      help::list();
      break;
    }
    case opts::Command::New: {
      result = cask::new_::exec(cmd_args(args));
      break;
    }
    case opts::Command::Build: {
      result = cask::build::exec();
      break;
    }
    case opts::Command::Run: {
      run::run();
      break;
    }
  }

  if (!result) {
    std::cout << result.error();
    exit(EXIT_FAILURE);
  }

  std::cout << *result;
}
