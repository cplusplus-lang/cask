#pragma once

#include <string>
#include <tl/expected.hpp>

namespace std_26 = tl;

using Result = std_26::expected<std::string, std::string>;
