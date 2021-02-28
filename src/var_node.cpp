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
        m_VarMap( varMap ),
        m_Desc( "Variable" )
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
      virtual const std::string& description( void ) const
      {
        return m_Desc;
      }
      virtual void print( int indent ) const
      {
        std::cout << std::endl;
        for (int i=0; i<indent; ++i)
          std::cout << ' ';
        std::cout << description() << ": " << m_ID << "\t" << calculate();
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
      std::string m_Desc;
    };
  }

  node_ptr_t ASTNode::formVariableNode( const std::string& identifier,
                                        var_map_t& varMap )
  {
    return std::make_shared<VariableNode>( identifier, varMap );
  }
}