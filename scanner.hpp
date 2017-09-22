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
    explicit Scanner( std::istream& in );
    Token token( void ) const;
    double value( void ) const;
    bool isDone( void ) const;
    bool isEmpty( void ) const;

    void accept( void );
  private:
    void readNextCharacter( void );

    std::istream& m_In;
    char m_Next;
    bool m_IsEmpty;
    Token m_Token;
    double m_Value;
    std::string m_VariableName;
  };
}

#endif