#ifndef TYPES_HPP
#define TYPES_HPP

#include <memory>
#include <map>
#include <functional>
#include <cmath>
#include <string>
#include <limits>
#include <cctype>
#include <sstream>
#include <cstdlib>

namespace Calculator
{
  struct ASTNode;
  using node_ptr_t = std::shared_ptr<ASTNode>;

  using real_function_t = double (*)(double);
  using func_map_t = std::map<std::string, real_function_t>;

  struct RealNumberIfAny;
  using var_map_t = std::map<std::string, RealNumberIfAny>;
}

#endif