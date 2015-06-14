#include "BinarySearchTree.h"

#include <iostream>

int main()
{
	BinarySearchTree<int> tree;

	tree.insert(17);
	tree.insert(6);
	tree.insert(3);
	tree.insert(1);
	tree.insert(12);
	tree.insert(9);
	tree.insert(15);
	tree.insert(46);
	tree.insert(56);
	tree.insert(48);

	tree.print();
	//tree.breadthFirstTraverse();

	//std::cout << tree;
	return 0;
}
