#pragma once

template <typename Type>
class Node
{
public:
    Node(Type element){
        this->data = element;
        this->next = nullptr;
    }
    
    Node(Type element, Node* previous){
        this->data = element;
        previous->next = this;
    }
    
    Node(const Node &other){
        this->data = other.data;
        this->next = other.next;
    }
    
    ~Node(){
        delete this->next;
    }
    
    Node& operator=(const Node& other){
        this->data = other.data;
        this->next = other.next;
        
        return *this;
    }
    
    Type data;
    Node* next;
};
