#include "node.hpp"

namespace Calculator
{
  namespace
  {
    struct UnaryNode : public ASTNode
    {
      UnaryNode( const node_ptr_t& child,
                 const std::string& description ) :
        m_Child( child ),
        m_Desc( description )
      { }
      virtual ~UnaryNode( void )
      { }
    public:
      virtual double calculate( void ) const = 0;
    public:
      virtual const std::string& description( void ) const
      {
        return m_Desc;
      }
      virtual void print( int indent ) const
      {
        std::cout << std::endl;
        for (int i=0; i<indent; ++i)
          std::cout << ' ';
        std::cout << description() << ": ";
        m_Child->print( indent + 2 );
      }
    protected:
      node_ptr_t m_Child;
    private:
      std::string m_Desc;
    };

    struct IdentityNode : public UnaryNode
    {
      IdentityNode( const node_ptr_t& child ) :
        UnaryNode( child, "Identity" )
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
        UnaryNode( child, "UnaryNegation" )
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
                    const real_function_t& func,
                    const std::string& name ) :
        UnaryNode( child, "Functional: " + name ),
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
                                        const real_function_t& func,
                                        const std::string& name )
  {
    return std::make_shared<FunctionNode>( child, func, name );
  }
}