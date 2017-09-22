#include "functions.hpp"

namespace Calculator
{
  const func_map_t& getFunctionTable( void )
  {
    static func_map_t theMap;

    theMap[ "log" ] = std::log;
    theMap[ "exp" ] = std::exp;
    theMap[ "sqrt" ] = std::sqrt;
    theMap[ "sin" ] = std::sin;
    theMap[ "cos" ] = std::cos;

    return theMap;
  }
}