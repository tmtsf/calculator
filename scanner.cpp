#include "scanner.hpp"

namespace Calculator
{
  Scanner::Scanner( const std::string& buffer ) :
    m_Buffer( buffer ),
    m_Index( 0 )
  {
    accept();
  }

  Token Scanner::token( void ) const
  {
    return m_Token;
  }

  double Scanner::value( void ) const
  {
    return m_Value;
  }

  void Scanner::skipWhiteSpace( void )
  {
    while ( std::isspace( m_Buffer[m_Index] ) )
      ++m_Index;
  }

  void Scanner::accept( void )
  {
    skipWhiteSpace();

    switch ( m_Buffer[m_Index] )
    {
      case '+':
        m_Token = Token::PLUS;
        ++m_Index;
        break;
      case '*':
        m_Token = Token::MULTIPLY;
        ++m_Index;
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
        m_Value = std::stod( m_Buffer, m_Index );
    }
  }

}