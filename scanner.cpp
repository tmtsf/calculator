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
      case '*':
        m_Token = Token::MULTIPLY;
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
          m_VariableName.erase();
          do
          {
            m_VariableName += m_Next;
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