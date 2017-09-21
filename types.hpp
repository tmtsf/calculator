#ifndef TYPES_HPP
#define TYPES_HPP

#include <memory>
#include <map>

namespace Calculator
{
  struct ASTNode;
  using node_ptr_t = std::shared_ptr<ASTNode>;
}

#endif