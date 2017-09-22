#ifndef SCANNER_HPP
#define SCANNER_HPP

#include "types.hpp"

namespace Calculator
{
  struct Scanner
  {
    enum Token
    {
      END,
      ERROR,
      NUMBER,
      PLUS,
      MULTIPLY,
      LEFT_PAREN,
      RIGHT_PAREN,
      ASSIGN,
      IDENTIFIER
    };
  public:
    Scanner( const std::string& buffer );
    Token token( void ) const;
    double value( void ) const;

    void accept( void );
  private:
    void skipWhiteSpace( void );

    const std::string& m_Buffer;
    std::size_t m_Index;
    Token m_Token;
    double m_Value;
  };
}

#endif