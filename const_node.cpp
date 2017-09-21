#include "node.hpp"

namespace Calculator
{
  namespace
  {
    struct ConstantNode : public ASTNode
    {
      ConstantNode( double number ) :
        m_Number( number )
      { }
      virtual ~ConstantNode( void )
      { }
    public:
      virtual double calculate( void ) const override
      {
        return m_Number;
      }
    private:
      double m_Number;
    };
  }

  node_ptr_t ASTNode::formConstantNode( double number )
  {
    return std::make_shared<ConstantNode>( number );
  }
}