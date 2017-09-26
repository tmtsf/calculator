#include "parser.hpp"
#include "functions.hpp"
#include "constants.hpp"

int main()
{
  using namespace Calculator;

  // node_ptr_t nodeOne = ASTNode::formConstantNode( 3.14159265358979 / 2 );
  // node_ptr_t nodeNeg = ASTNode::formNegationNode( nodeOne );
  // node_ptr_t nodeFunc = ASTNode::formFunctionNode( nodeNeg, std::sin );

  // std::cout << nodeFunc->calculate() << std::endl;

  // node_ptr_t nodeTwo = ASTNode::formConstantNode( 5. );
  // node_ptr_t nodeSum = ASTNode::formSummationNode( nodeFunc, nodeTwo );

  // std::cout << nodeSum->calculate() << std::endl;

  // var_map_t varMap;
  // node_ptr_t nodeVar = ASTNode::formVariableNode( "simpleVariable", varMap );
  // node_ptr_t nodeAssign = ASTNode::formAssignmentNode( nodeVar, nodeSum );

  // std::cout << nodeAssign->calculate() << std::endl;

  // node_ptr_t nodeThree = ASTNode::formConstantNode( 3 );
  // node_ptr_t nodeMultiSum = ASTNode::formMultipleMultiplicationNode( nodeFunc );
  // nodeMultiSum->addChildNode( nodeTwo, false );
  // nodeMultiSum->addChildNode( nodeThree, true );
  // std::cout << nodeMultiSum->calculate() << std::endl;

  try
  {
    std::istringstream in("sin((2 * pi)^3)");
    Scanner scanner( in );

    func_map_t funcMap = getFunctionTable();

    var_map_t varMap;
    addConstantsToVariableMap( "e", std::exp(1.), varMap );
    addConstantsToVariableMap( "pi", 3.14159265358979, varMap );

    Parser parser( scanner, varMap, funcMap );
    parser.parse();

    std::cout << parser.calculate() << std::endl;
  }
  catch ( const std::string& message )
  {
    std::cout << message << std::endl;
  }

  return 0;
}