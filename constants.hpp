#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include "node.hpp"

namespace Calculator
{
  void addConstantsToVariableMap( const std::string& name,
                                  double value,
                                  var_map_t& varMap );
}


#endif