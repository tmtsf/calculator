#ifndef NODE_HPP
#define NODE_HPP

#include "types.hpp"

namespace Calculator
{
  struct ASTNode
  {
    ASTNode( void );
    virtual ~ASTNode( void );
  public:
    virtual double calculate( void ) const = 0;
  public:
    static node_ptr_t formConstantNode( double number );

    static node_ptr_t formNegationNode( const node_ptr_t& child );
    static node_ptr_t formFunctionNode( const node_ptr_t& child,
                                        const real_function_t& func );

    static node_ptr_t formSummationNode( const node_ptr_t& leftNode,
                                         const node_ptr_t& rightNode );
    static node_ptr_t formMultiplicationNode( const node_ptr_t& leftNode,
                                              const node_ptr_t& rightNode );
  };

}

#endif