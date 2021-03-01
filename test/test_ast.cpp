#include "gtest/gtest.h"
#include "parser.hpp"
#include "functions.hpp"
#include "constants.hpp"

namespace Calculator
{
  namespace test
  {
    TEST(test_ast, PrintAST)
    {
      std::istringstream in("sin((2 * -pi ^ 2 / +4)^3)");
      Scanner scanner( in );

      func_map_t funcMap = getFunctionTable();

      var_map_t varMap;
      addConstantsToVariableMap( "e", std::exp(1.), varMap );
      addConstantsToVariableMap( "pi", 3.14159265358979, varMap );

      Parser parser( scanner, varMap, funcMap );
      parser.parse();

      printf("\n************************************************************************************\n");
      printf("The value fo the expression is: \n");
      printf("sin((2 * -pi ^ 2 / +4)^3) = %.9f\n", parser.calculate());
      printf("\n\nThe AST of the expression is: \n");;
      parser.print();
      printf("\n\n");
      printf("************************************************************************************\n\n");
    }
  }
}