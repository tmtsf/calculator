#ifndef TYPES_HPP
#define TYPES_HPP

#include <memory>
#include <map>
#include <functional>
#include <cmath>

namespace Calculator
{
  struct ASTNode;
  using node_ptr_t = std::shared_ptr<ASTNode>;

  using real_function_t = std::function<double(double)>;
}

#endif