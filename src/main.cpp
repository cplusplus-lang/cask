//              Copyright Cask Authors
// Distributed under the Boost Software License, Version 1.0.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.boost.org/LICENSE_1_0.txt)

// SPDX-License-Identifier: BSL-1.0

//
// This file implements the Cask functionality.

#include <commands/help.hpp>
#include <utils/opts.hpp>

int main(int ac, char* av[]) {
  if (ac < 2) {
    help::help();
    return 1;
  }

  const auto command{opts::command::from_str(av[1])};

  if (!command.has_value()) {
    help::unknown_command(av[1]);
    return 1;
  }

  switch (command.value()) {
    case opts::Command::Help:
      help::help();
      break;
    case opts::Command::List:
      help::list();
      break;
  }

  return 0;
}
