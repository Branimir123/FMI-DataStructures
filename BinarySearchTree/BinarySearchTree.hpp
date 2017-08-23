#pragma once

#include <iostream>
#include <algorithm>

template <class T>
class BinarySearchTree 
{   
public:
    BinarySearchTree() : _root(nullptr), _size(0) {}; 
    BinarySearchTree(const BinarySearchTree& other);
    ~BinarySearchTree();
    BinarySearchTree& operator=(const BinarySearchTree& other);
    
    void Insert(const T& key) { _Insert(_root, key); _size++; }
    void Remove(const T& key) { _Remove(_root, key); }
    bool Find(const T& key) { return _Find(_root, key); }

    size_t GetSize() const { return _size; }
    size_t GetHeight() const { return (size_t)_Height(_root); }

    bool IsBalanced() const { return _Balanced(_root); }
    bool IsPerfectlyBalanced() const { return _PerfectBalanced(_root); }

    void PrintInOrder() const { return _Print(_root); }

private:
    // Private Fields
    struct Node
    {
        T key;
        Node* left;
        Node* right;
        
        Node(const T& key, Node* left = nullptr, Node* right = nullptr)
            : key(key), left(left), right(right) {};
    } * _root;
    size_t _size;
    
    // Private Functions
    void _Clear(Node* from); 
    Node* _Copy(Node* root); 
    
    bool _Find(const Node* root, const T& key) const; 
    void _Insert(Node*& root, const T& key); 
    void _Remove(Node*& root, const T& key); 
    
    Node* _ExtractMin(Node*& root);
    
    int _Height(const Node* root) const; 
    size_t _Weight(const Node* root) const; 
    
    bool _Balanced(const Node* root) const;
    bool _PerfectBalanced(const Node* root) const;
    
    void _Print(const Node* from) const; 
};

template <class T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree& other) {
    _root = this->Copy(other._root);
    _size = other._size;
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree(){
    _Clear(_root);
}

template <class T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(const BinarySearchTree& other) {
    if(&other != this) {
        _Clear(_root);
        _root = _Copy(other._root);
        _size = other._size;
    }
    return *this;
}

template <class T>
void BinarySearchTree<T>::_Clear(Node* from) {
    if(from) {
        clear(from->left);
        clear(from->right);
        delete _root;
    }
}

template <class T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::_Copy(Node* from) {
    return _root ? 
        new Node(_root->key, _Copy(_root->left), _Copy(_root->right)) : 
        _root;
}

template <class T>
bool BinarySearchTree<T>::_Find(const Node* root, const T& key) const
{
    if (!root)
    {
        return false;
    }
    
    if(root->key == key){
        return true;
    }
    
    return key < root->key ? _Find(root->left) : _Find(root->right);
}

template <class T>
void BinarySearchTree<T>::_Insert(Node*& root, const T& key) {
    if (!root) 
    {
        root = new Node(key);
    }
    else
    { 
        _Insert(key < root->key ? root->left : root->right, key);
    }
}

template <class T>
void BinarySearchTree<T>::_Remove(Node*& root, const T& key) {
    if (!root) return;
        if (root->key == key)
        {
            Node* toDel = root;
            if (!root->left)
            {
                root = root->right;
            }
            else if (!root->right)
            {
                root = root->left;
            }
            else
            {
                Node* mR = extractMin(root->right);
                mR->left = root->left;
                mR->right = root->right;
                root = mR;
            }
            _size--;
            delete toDel;
        }
    else
    {
        remove(key < _root->key ? _root->left : _root->right, key);
    }
}

template <class T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::_ExtractMin(Node*& root) {
    if (root->left) 
    {
        return _ExtractMin(root->left);
    }

    Node* n = root;
    root = root->right;
    return n;
}

template <class T>
int BinarySearchTree<T>::_Height(const Node* root) const {
    if (!root) 
    { 
        return 0; 
    }
    
    return 1 + std::max(_Height(root->left), _Height(root->right));
}

template <class T>
size_t BinarySearchTree<T>::_Weight(const Node* root) const {
    if (!root)
    { 
        return 0;
    }
 
    return 1 + _Weight(root->left) + _Weight(root->right);
}

template <class T>
bool BinarySearchTree<T>::_Balanced(const Node* root) const {
    if (!root) 
    { 
        return true;
    }
    
    return abs(_Height(root->left) - _Height(root->right)) < 2 &&
               _Balanced(root->left) && _Balanced(root->right);
}

template <class T>
bool BinarySearchTree<T>::_PerfectBalanced(const Node* root) const {
    if (!root) 
    {
        return true;
    }
    
    return labs(_Weight(root->left) - _Weight(root->right)) < 2 &&
            _PerfectBalanced(root->left) && _PerfectBalanced(root->right);
}

template <class T>
void BinarySearchTree<T>::_Print(const Node* from) const {
    if(from){
        _Print(from->left);
        std::cout << from->key << " ";
        _Print(from->right);
    }
}