#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include <iostream>
#include <queue>

template <class T>
class BinarySearchTree
{
public:
	class Node
	{
	private:
		Node *m_parent;
		Node *m_left;
		Node *m_right;
		T m_data;
	public:
		Node() : m_parent(0), m_left(0), m_right(0) { }
		Node(const T& data) : m_parent(0), m_left(0), m_right(0), m_data(data) { }
		~Node()
		{
			if ( m_left != 0 )
			{
				delete m_left;
				m_left = 0;
			}
			if ( m_right != 0 )
			{
				delete m_right;
				m_right = 0;
			}
		}

		Node *parent() { return m_parent; }
		Node *left() { return m_left; }
		Node *right() { return m_right; }
		
		const T& data() const { return m_data; }
		void setData(const T& data) { this->m_data = data; }

		friend class BinarySearchTree<T>;
	};
private:
	Node *root;

public:
	BinarySearchTree()
		: root(0)
	{
	}
	~BinarySearchTree()
	{
		delete root;
		root = 0;
	}

	void print(int level = 0, Node *node = 0, int leftRootRight = 0)
	{
		int mylevel = level;
		if ( node == 0 )
			node = root;

		if ( node != 0 )
		{
			for ( int i = 0 ; i < mylevel ; i++ )
			{
				std::cout << "     ";
			}	
			std::cout << "`-";
			if ( leftRootRight < 0 )
				std::cout << "(L)";
			else if ( leftRootRight == 0 )
				std::cout << "(0)";
			else if ( leftRootRight > 0 )
				std::cout << "(R)";

			std::cout << node->data() << std::endl;
			if ( node->left() != 0 )
			{
				print(mylevel + 1, node->left(), -1);
			}
			if ( node->right() != 0 )
			{
				print(mylevel + 1,node->right(), 1);
			}
			//functor(node);
			//functor(node->left());
			//functor(node->right());
		}
	}
	void breadthFirstTraverse()
	{
		std::queue< Node * > q;
		q.push( root );
		q.push( 0 );//line-break;
		int w = 64;
		int level = 0;
		for (  ; !q.empty() ; q.pop() )
		{
			Node *node = q.front();
			if ( node == 0 )
			{
				std::cout << std::endl;
				level++;
			}
			else
			{
				std::cout.width(w/(level+1));
				std::cout << node->data();

				if ( node->left() != 0 )
					q.push( node->left() );
				if ( node->right() != 0 )
					q.push( node->right() );
				q.push( 0 );
			}
		}
	}

	void insert(const T& data, Node *node = 0)
	{
		if ( node == 0 )
		{
			node = root;
		}

		if ( root == 0 )
		{
			root = new Node(data);
		}
		else
		{
			if ( data > node->data() )
			{
				if ( node->right() != 0 )
				{
					insert( data, node->right() );
				}
				else
				{
					node->m_right = new Node(data);
				}
			}
			else
			{
				if ( node->left() != 0 )
				{
					insert( data, node->left() );
				}
				else
				{
					node->m_left = new Node(data);
				}
			}
		}
	}

	void invert(Node *node = 0)
	{
		if ( node == 0 )
			node = root;

		if ( node->left() != 0 )
			invert( node->left() );
		if ( node->right() != 0 )
			invert( node->right() );

		Node *swap = node->m_left;
		node->m_left = node->m_right;
		node->m_right = swap;
	}

};

#endif
