#include <iostream>
#include "node.hpp"

int main()
{
  using namespace Calculator;

  node_ptr_t nodeOne = ASTNode::formConstantNode( 6. );
  node_ptr_t nodeTwo = ASTNode::formConstantNode( 5. );
  node_ptr_t nodeSum = ASTNode::formMultiplicationNode( nodeOne, nodeTwo );

  std::cout << nodeSum->calculate() << std::endl;

  return 0;
}