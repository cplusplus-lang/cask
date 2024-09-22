//              Copyright Cask Authors
// Distributed under the Boost Software License, Version 1.0.
//   (See accompanying file LICENSE.txt or copy at
//        https://www.boost.org/LICENSE_1_0.txt)

// SPDX-License-Identifier: BSL-1.0

//
// This file implements the Cask functionality.

#include <commands/help.hpp>

int main(int ac, char *av[]) {
  if (ac < 2) {
    help::run();
    return 1;
  }

  help::run();

  return 0;
}