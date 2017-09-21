#include "node.hpp"

namespace Calculator
{

  namespace
  {
    struct VariableNode : public ASTNode
    {
      VariableNode( const std::string& identifier,
                    var_map_t& varMap ) :
        m_ID( identifier ),
        m_VarMap( varMap )
      { }
      virtual ~VariableNode( void )
      { }
    public:
      virtual double calculate( void ) const override
      {
        if ( m_VarMap[m_ID].m_HasValue )
          return m_VarMap[m_ID].m_Value;
        else
          throw("The variable " + m_ID + " is not initialized!");
      }
    public:
      virtual bool isLValue( void ) const override
      {
        return true;
      }
      virtual void assign( double value ) override
      {
        m_VarMap.insert( std::make_pair( m_ID, RealNumberIfAny() ) );
        m_VarMap[m_ID].m_HasValue = true;
        m_VarMap[m_ID].m_Value = value;
      }
    private:
      std::string m_ID;
      var_map_t& m_VarMap;
    };
  }

  node_ptr_t ASTNode::formVariableNode( const std::string& identifier,
                                        var_map_t& varMap )
  {
    return std::make_shared<VariableNode>( identifier, varMap );
  }
}