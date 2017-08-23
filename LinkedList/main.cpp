#include <iostream>
#include "LinkedList.hpp"

int main(int argc, char **argv)
{
    // Initialization
    LinkedList<int> list = LinkedList<int>();
    
    // IsEmpty() test
	std::cout << "Is empty: " << list.IsEmpty() << std::endl;
    
    // AddTail chaining test
    list.AddTail(5).AddTail(55).AddTail(-1);
    
    std::cout << "Tail: " << list.GetTail() << std::endl;
    
    // Lenght test
    std::cout << "Length: " << list.Length() << std::endl;
    
    // Test chaining of add head
    list.AddHead(5).AddHead(4);
    
    // Testing GetHead();
    std::cout << "Head: " << list.GetHead() << " " << "New Length: " << list.Length() << std::endl;
        
    // operator = test 
    auto list2 = list;
    
    std::cout << list2.Length() << std::endl;
    
    // copy constructor test 
    auto list3 = LinkedList<int>(list);
    
    std::cout << list3.Length() << std::endl;
     
    list3.RemoveAll();
    
    std::cout << list3.Length() << std::endl;
     
	return 0;
}
