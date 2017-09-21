#include "node.hpp"

namespace Calculator
{
  ASTNode::ASTNode( void )
  { }

  ASTNode::~ASTNode( void )
  { }

  bool ASTNode::isLValue( void ) const
  {
    return false;
  }

  void ASTNode::assign( double value )
  {
    // no-op for most types of AST node
    // only implemented for the variable node
  }


  RealNumberIfAny::RealNumberIfAny( void ) :
    m_HasValue( false ),
    m_Value( std::numeric_limits<double>::quiet_NaN() )
  { }
}