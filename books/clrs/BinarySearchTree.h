#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <memory>
#include <iostream>
template <typename T>
class binaryNode {
public:
    /* default ctor */
    binaryNode(): key(0), left(nullptr), right(nullptr), p(nullptr) {}
    /* ctor  */
    binaryNode(const binaryNode &n): 
        key(n.key), left(n.left), right(n.right),p(n.p) {}
    binaryNode(const T& t):key(t), left(nullptr), right(nullptr), p(nullptr){}
    /* dtor */
    ~binaryNode() = default;
/* data member */
public:
    binaryNode *left;
    binaryNode *right;
    binaryNode *p;
    T key;
};
template<typename T>
class binarySearchTree {
public:
    /* ctor */
    binarySearchTree():root(nullptr) {}
    /* dtor */
    ~binarySearchTree() {
        destroy(root);
    }
private:
    void destroy(T*);
    

public:
    void walk(T*);
    T* search(T*, decltype(T::key));
    T* minimum(T*, decltype(T::key));
    T* maximum(T*, decltype(T::key));
    T* successor(T*);
    T* predecessor(T*);
    void insert(const T &);
public:
    T* root;
};




#endif // BINARY_SEARCH_TREE_H
