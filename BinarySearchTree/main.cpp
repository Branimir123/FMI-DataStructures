#include<iostream>
#include "BinarySearchTree.hpp"

int main(int argc, char **argv)
{
	auto tree = new BinarySearchTree<int>();
    tree->Insert(5);
    tree->Insert(8);
    tree->Insert(23);
    
    std::cout << tree->GetSize() << std::endl;
	return 0;
}
