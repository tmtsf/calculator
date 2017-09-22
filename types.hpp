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
#include <vector>

namespace Calculator
{
  struct ASTNode;
  using node_ptr_t = std::shared_ptr<ASTNode>;
  using node_ptr_coll_t = std::vector<node_ptr_t>;

  using boolean_vec_t = std::vector<bool>;

  using real_function_t = double (*)(double);
  using func_map_t = std::map<std::string, real_function_t>;

  struct RealNumberIfAny;
  using var_map_t = std::map<std::string, RealNumberIfAny>;
}

#endif