#include "constants.hpp"

namespace Calculator
{
  void addConstantsToVariableMap( const std::string& name,
                                  double value,
                                  var_map_t& varMap )
  {
    varMap[ name ] = RealNumberIfAny( value );
  }
}