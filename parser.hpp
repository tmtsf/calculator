#ifndef PARSER_HPP
#define PARSER_HPP

#include "node.hpp"
#include "scanner.hpp"

namespace Calculator
{
    struct Parser
    {
      enum Status
      {
        OK,
        QUIT,
        ERROR
      };
    public:
      Parser( Scanner& scanner,
              var_map_t& varMap,
              const func_map_t& funcMap );
      ~Parser( void );
  
      Status parse( void );
      double calculate( void ) const;
    private:
      node_ptr_t expression( void );
      node_ptr_t term( void );
      node_ptr_t factor( void );
    private:
      Scanner& m_Scanner;
      node_ptr_t m_Root;
      Status m_Status;
      var_map_t& m_VarMap;
      const func_map_t& m_FuncMap;
    };
  }  

#endif