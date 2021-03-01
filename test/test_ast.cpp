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
      std::string s("sin((2 * (-pi) ^ 2 / +4)^3)");
      std::istringstream in(s);
      Scanner scanner( in );

      func_map_t funcMap = getFunctionTable();

      var_map_t varMap;
      addConstantsToVariableMap( "e", std::exp(1.), varMap );
      addConstantsToVariableMap( "pi", 3.14159265358979, varMap );

      Parser parser( scanner, varMap, funcMap );
      parser.parse();

      double result = parser.calculate();
      double expected = std::sin(std::pow(3.14159265358979, 6.) / 8.);
      EXPECT_NEAR(result, expected, 1e-6);

      printf("\n************************************************************************************\n");
      printf("The value of the expression is: \n");
      printf("%s = %.9f\n", s.c_str(), parser.calculate());
      printf("\n\nThe AST of the expression is: \n");
      parser.print();
      printf("\n\n");
      printf("************************************************************************************\n\n");
    }
  }
}