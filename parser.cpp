#include "parser.hpp"

namespace Calculator
{
  Parser::Parser( Scanner& scanner,
                  var_map_t& varMap,
                  const func_map_t& funcMap ) :
    m_Scanner( scanner ),
    m_Root(),
    m_Status( Status::OK ),
    m_VarMap( varMap ),
    m_FuncMap( funcMap )
  { }

  Parser::~Parser( void )
  { }

  Parser::Status Parser::parse( void )
  {
    m_Root = expression();
    if ( !m_Scanner.isDone() )
      m_Status = Status::ERROR;

    return m_Status;
  }

  double Parser::calculate( void ) const
  {
    return m_Root->calculate();
  }

  node_ptr_t Parser::expression( void )
  {
    node_ptr_t pNode = term();
    Scanner::Token token = m_Scanner.token();

    if ( token == Scanner::Token::PLUS || token == Scanner::Token::MINUS )
    {
      node_ptr_t pSumNode = ASTNode::formMultipleSummationNode( pNode );

      do
      {
        m_Scanner.accept();
        node_ptr_t pNewNode = term();
        pSumNode->addChildNode( pNewNode, token == Scanner::Token::PLUS );
        token = m_Scanner.token();
      } while ( token == Scanner::Token::PLUS || token == Scanner::Token::MINUS );
      pNode = pSumNode;
    }
    else if ( token == Scanner::Token::ASSIGN )
    {
      m_Scanner.accept();
      node_ptr_t pRightNode = expression();

      if ( pNode->isLValue() )
      {
        pNode = ASTNode::formAssignmentNode( pNode, pRightNode );
      }
      else
      {
        m_Status = Status::ERROR;
        pNode = expression();
      }
    }

    return pNode;
  }

  node_ptr_t Parser::term( void )
  {
    node_ptr_t pNode = factor();
    Scanner::Token token = m_Scanner.token();

    if ( token == Scanner::Token::MULTIPLY || token == Scanner::Token::DIVIDE )
    {
      node_ptr_t pProductNode = ASTNode::formMultipleMultiplicationNode( pNode );

      do
      {
        m_Scanner.accept();
        node_ptr_t pNewNode = factor();
        pProductNode->addChildNode( pNewNode, token == Scanner::Token::MULTIPLY );
        token = m_Scanner.token();
      } while ( token == Scanner::Token::MULTIPLY || token == Scanner::Token::DIVIDE );
      pNode = pProductNode;
    }

    return pNode;
  }

  node_ptr_t Parser::factor( void )
  {
    node_ptr_t pNode;
    Scanner::Token token = m_Scanner.token();

    if ( token == Scanner::Token::LEFT_PAREN )
    {
      m_Scanner.accept();
      pNode = expression();
      if ( m_Scanner.token() != Scanner::Token::RIGHT_PAREN )
        m_Status = Status::ERROR;
      else
        m_Scanner.accept();
    }
    else if ( token == Scanner::Token::NUMBER )
    {
      pNode = ASTNode::formConstantNode( m_Scanner.value() );
      m_Scanner.accept();
    }
    else if ( token == Scanner::Token::IDENTIFIER )
    {
      const std::string& id = m_Scanner.getID();
      m_Scanner.accept();

      if ( m_Scanner.token() == Scanner::Token::LEFT_PAREN )
      {
        m_Scanner.accept();
        pNode = expression();
        if ( m_Scanner.token() == Scanner::Token::RIGHT_PAREN )
          m_Scanner.accept();
        else
          m_Status = Status::ERROR;

        auto it = m_FuncMap.find( id );
        if ( it != m_FuncMap.cend() )
        {
          pNode = ASTNode::formFunctionNode( pNode, it->second );
        }
        else
        {
          throw("Unknow function encountered!");
        }
      }
      else
      {
        pNode = ASTNode::formVariableNode( id, m_VarMap );
      }
    }
    else if ( token == Scanner::Token::MINUS )
    {
      m_Scanner.accept();
      pNode = ASTNode::formNegationNode( factor() );
    }
    else
    {
      m_Scanner.accept();
      m_Status = Status::ERROR;
    }

    return pNode;
  }
}