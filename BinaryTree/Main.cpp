#include "binary_tree.h"

int main()
{
	binary_tree<int> tree;
	tree.insert(2);
	tree.insert(3);
	tree.insert(4);
	tree.insert(5);
	tree.insert(1);
	tree.insert(-2);
	tree.insert(0);
	tree.insert(8);
	for (auto value : tree.values())
	{
		std::cout << value << std::endl;
	}
	
	std::cout << std::endl << tree.search(3);

}