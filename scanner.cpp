#include "scanner.hpp"

namespace Calculator
{
  Scanner::Scanner( std::istream& in ) :
    m_In( in )
  {
    accept();
    m_IsEmpty = (m_Token == Token::END);
  }

  Scanner::Token Scanner::token( void ) const
  {
    return m_Token;
  }

  double Scanner::value( void ) const
  {
    return m_Value;
  }

  bool Scanner::isDone( void ) const
  {
    return m_Token == Token::END;
  }

  bool Scanner::isEmpty( void ) const
  {
    return m_IsEmpty;
  }

  const std::string& Scanner::getID( void ) const
  {
    if ( m_Token == Token::IDENTIFIER )
      return m_ID;
    else
    {
      throw("No variable name can be provided!");
      static std::string error;
      return error;
    }
  }

  void Scanner::readNextCharacter( void )
  {
    m_Next = m_In.get();
    while ( m_Next == ' ' || m_Next == '\t' )
      m_Next = m_In.get();
  }

  void Scanner::accept( void )
  {
    readNextCharacter();

    switch ( m_Next )
    {
      case '+':
        m_Token = Token::PLUS;
        break;
      case '-':
        m_Token = Token::MINUS;
        break;
      case '*':
        m_Token = Token::MULTIPLY;
        break;
      case '/':
        m_Token = Token::DIVIDE;
        break;
      case '^':
        m_Token = Token::POWER;
        break;
      case '=':
        m_Token = Token::ASSIGN;
        break;
      case '(':
        m_Token = Token::LEFT_PAREN;
        break;
      case ')':
        m_Token = Token::RIGHT_PAREN;
        break;
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
      case '.':
        m_Token = Token::NUMBER;
        m_In.putback( m_Next );
        m_In >> m_Value;
        break;
      case '\n':
      case '\r':
      case EOF:
        m_Token = Token::END;
        break;
      default:
        if ( isalpha( m_Next ) || m_Next == '_' )
        {
          m_Token = Token::IDENTIFIER;
          m_ID.erase();
          do
          {
            m_ID += m_Next;
            m_Next = m_In.get();
          } while ( isalnum( m_Next ) );
          m_In.putback( m_Next );
        }
        else
        {
          m_Token = Token::ERROR;
        }
        break;
    }
  }

}