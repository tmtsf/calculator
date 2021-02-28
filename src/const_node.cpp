#include "node.hpp"

namespace Calculator
{
  namespace
  {
    struct ConstantNode : public ASTNode
    {
      ConstantNode( double number ) :
        m_Number( number ),
        m_Desc( "Constant" )
      { }
      virtual ~ConstantNode( void )
      { }
    public:
      virtual double calculate( void ) const override
      {
        return m_Number;
      }
      virtual const std::string& description( void ) const
      {
        return m_Desc;
      }
      virtual void print( int indent ) const
      {
        std::cout << std::endl;
        for (int i=0; i<indent; ++i)
          std::cout << ' ';
        std::cout << description() << ": " << m_Number;
      }
    private:
      double m_Number;
      std::string m_Desc;
    };
  }

  node_ptr_t ASTNode::formConstantNode( double number )
  {
    return std::make_shared<ConstantNode>( number );
  }
}