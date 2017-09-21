#include <iostream>
#include "node.hpp"

int main()
{
  using namespace Calculator;

  node_ptr_t nodeOne = ASTNode::formConstantNode( 6. );
  node_ptr_t nodeNeg = ASTNode::formNegationNode( nodeOne );
  node_ptr_t nodeFunc = ASTNode::formFunctionNode( nodeOne, []( double x ) { return std::sin(x); } );

  node_ptr_t nodeTwo = ASTNode::formConstantNode( 5. );
  node_ptr_t nodeSum = ASTNode::formSummationNode( nodeFunc, nodeTwo );

  std::cout << nodeSum->calculate() << std::endl;

  return 0;
}