#pragma once

#include "Node.hpp"

template <typename T>
class LinkedList
{
public:
    LinkedList();
    LinkedList(const LinkedList &other);
    ~LinkedList();
    LinkedList& operator=(const LinkedList& other);

public:
    void RemoveAll();

public:
    LinkedList& AddTail(T const &);
    LinkedList& AddHead(T const &);
    
    int Remove(T element);
    void RemoveAt(int index);

public:    
    T* ElementAt(int index);
    int IndexOf(T element);
    int Contains(T element);
    
    T const & GetHead();
    T const & GetTail();
    
    int Length();
    bool IsEmpty();

    int Clear();

private:
    void DestroyFrom(Node<T>* node);
    void Initialize();
    
private:
    Node<T>* head;
    Node<T>* tail;
    int count;
};

template <typename T>
LinkedList<T>::LinkedList(){
    this->Initialize();
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList& other){
    this->head = other.head;
    this->tail = other.tail;
        
    this->count = other.count;
}

template <typename T>
LinkedList<T>::~LinkedList(){
   this->RemoveAll();
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator =(const LinkedList& other){
    this->head = other.head;
    this->tail = other.tail;
    this->count = other.count;
}

template <typename T>
LinkedList<T>& LinkedList<T>::AddTail(T const & element) {
    if(this->IsEmpty()){
        this->head = new Node<T>(element);
        this->tail = this->head;
    }
    else
    {
        this->tail = new Node<T>(element, this->tail);
    }
    
    this->count++;
    return *this;
}

template <typename T>
LinkedList<T>& LinkedList<T>::AddHead(T const & element) {
    auto node = new Node<T>(element);
    
    if(this->IsEmpty()){
        this->tail = node;
    }
    
    this->head = new Node<T>(element);
    
    this->count++;
    return *this;
}

template <typename T>
T const & LinkedList<T>::GetHead(){
    return this->head->data;
}

template <typename T>
T const & LinkedList<T>::GetTail(){
    return this->tail->data;
}

template <typename T>
int LinkedList<T>::Length() {
    return this->count;
}

template <typename T>
bool LinkedList<T>::IsEmpty() {
    return this->count == 0;
}

template <typename T>
void LinkedList<T>::RemoveAll() {
    this->DestroyFrom(this->head);
    this->Initialize();
}

template <typename T>
void LinkedList<T>::DestroyFrom(Node<T>* node) {
    auto curr = this->head;
    auto prev = this->head;
    
    while(curr) {
        prev = curr;
        curr = curr->next;
        
        delete prev;
    }
}

template <typename T>
void LinkedList<T>::Initialize() {
    this->head = nullptr;
    this->tail = nullptr;
    this->count = 0;
}