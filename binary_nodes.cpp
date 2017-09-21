#include "node.hpp"

namespace Calculator
{
  namespace
  {
    struct BinaryNode : public ASTNode
    {
      BinaryNode( const node_ptr_t& leftNode,
                  const node_ptr_t& rightNode ) :
        m_LeftNode( leftNode ),
        m_RightNode( rightNode )
      { }
      virtual ~BinaryNode( void )
      { }
    public:
      virtual double calculate( void ) const = 0;
    protected:
      node_ptr_t m_LeftNode;
      node_ptr_t m_RightNode;
    };

    struct SummationNode : public BinaryNode
    {
      SummationNode( const node_ptr_t& leftNode,
                     const node_ptr_t& rightNode ) :
        BinaryNode( leftNode, rightNode )
      { }
      virtual ~SummationNode( void )
      { }
    public:
      virtual double calculate( void ) const override
      {
        return m_LeftNode->calculate() + m_RightNode->calculate();
      }
    };

    struct MultiplicationNode : public BinaryNode
    {
      MultiplicationNode( const node_ptr_t& leftNode,
                          const node_ptr_t& rightNode ) :
        BinaryNode( leftNode, rightNode )
      { }
      virtual ~MultiplicationNode( void )
      { }
    public:
      virtual double calculate( void ) const override
      {
        return m_LeftNode->calculate() * m_RightNode->calculate();
      }
    };
  }

  node_ptr_t ASTNode::formSummationNode( const node_ptr_t& leftNode,
                                         const node_ptr_t& rightNode )
  {
    return std::make_shared<SummationNode>( leftNode, rightNode );
  }

  node_ptr_t ASTNode::formMultiplicationNode( const node_ptr_t& leftNode,
                                              const node_ptr_t& rightNode )
  {
    return std::make_shared<MultiplicationNode>( leftNode, rightNode );
  }
}