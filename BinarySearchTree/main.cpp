#include<iostream>
#include "BinarySearchTree.hpp"

int main(int argc, char **argv)
{
	auto tree = new BinarySearchTree<int>();
    tree->Insert(5);
    tree->Insert(8);
    tree->Insert(34);
    tree->Insert(78);
    tree->Insert(4);
    tree->Insert(3);
    tree->Insert(2);
    tree->Insert(55);
    
    std::cout << tree->GetSize() << std::endl;
    std::cout << tree->IsBalanced() << std::endl;
    
    tree->PrintInOrder();
	return 0;
}
