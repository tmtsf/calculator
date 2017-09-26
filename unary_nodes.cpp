#include "node.hpp"

namespace Calculator
{
  namespace
  {
    struct UnaryNode : public ASTNode
    {
      UnaryNode( const node_ptr_t& child ) :
        m_Child( child )
      { }
      virtual ~UnaryNode( void )
      { }
    public:
      virtual double calculate( void ) const = 0;
    protected:
      node_ptr_t m_Child;
    };

    struct IdentityNode : public UnaryNode
    {
      IdentityNode( const node_ptr_t& child ) :
        UnaryNode( child )
      { }
      virtual ~IdentityNode( void )
      { }
    public:
      virtual double calculate( void ) const override
      {
        return m_Child->calculate();
      }
    };

    struct NegationNode : public UnaryNode
    {
      NegationNode( const node_ptr_t& child ) :
        UnaryNode( child )
      { }
      virtual ~NegationNode( void )
      { }
    public:
      virtual double calculate( void ) const override
      {
        return - m_Child->calculate();
      }
    };

    struct FunctionNode : public UnaryNode
    {
      FunctionNode( const node_ptr_t& child,
                    const real_function_t& func ) :
        UnaryNode( child ),
        m_Func( func )
      { }
      virtual ~FunctionNode( void )
      { }
    public:
      virtual double calculate( void ) const override
      {
        return m_Func( m_Child->calculate() );
      }
    private:
      real_function_t m_Func;
    };
  }

  node_ptr_t ASTNode::formIdentityNode( const node_ptr_t& child )
  {
    return std::make_shared<IdentityNode>( child );
  }

  node_ptr_t ASTNode::formNegationNode( const node_ptr_t& child )
  {
    return std::make_shared<NegationNode>( child );
  }

  node_ptr_t ASTNode::formFunctionNode( const node_ptr_t& child,
                                        const real_function_t& func )
  {
    return std::make_shared<FunctionNode>( child, func );
  }
}