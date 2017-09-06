#include <iostream>
#include <memory>
#include <algorithm>
#include <iterator>
#include "BinarySearchTree.h"


template<typename T> void
binarySearchTree<T>::destroy(T * root) {
    /*
     * Since we use shared_ptr, we will do nothing, left it for GC.
     */
/*
    if (!root) return;
    if (root->left) destroy(root->left);
    if (root->right) destroy(root->right);
    delete root;
    return;
*/
}

template<typename T> void
binarySearchTree<T>::walk(T* x) {
    /* preorder tree walk */
    using std::cout;
    /*bind*/
    // using std::ostream_iterator;
    // ostream_iterator<decltype(x->key)> outite(cout, " ");
    if(x) cout << x->key << " ";
    else return;
    if (x->left) treeWalk(x->left);
    if (x->right) treeWalk(x->right);
    return;
}


template<typename T>
T* 
binarySearchTree<T>::search(T* x, decltype(T::key) k) {
    if ((!x) || k == x->key) 
        return x;
    if (k < x->key)
    {
        return search(x->left, k);
    }
    else 
        return search(x->right, k);
}
template<typename T>
T* binarySearchTree<T>::minimum(T* x, decltype(T::key) k) {
    while (x->left) {
        x = x->left;
    }
    return x;
}
template<typename T>
T* binarySearchTree<T>::maximum(T* x, decltype(T::key) k) {
    while (x->right) {
        x = x->right;
    }
    return x;
}
template<typename T>
T* binarySearchTree<T>::successor(T* x) {
    if (!x) return x;
     /*
      * x
      *  \
      *   o (x's successor)
      */
    if (x->right) return minimum(x->right);
    /*
     *     o (x's successor)
     *    /
     *   o
     *    \
     *     x
     */
    else {
        /* From CLRS */
        T* y = x->p;
        while (y && y->right == x) {
            x = y;
            y = x->p;
        }
        return y;
    }
}
template<typename T>
T* binarySearchTree<T>::predecessor(T* x) {
    /*
     *   x
     *  /
     * o
     *
     */
    if (!x)return x;
    if (x->left) return maximum(x->left);
    /*
     * o (x's predecessor)
     *  \
     *   x
     *  / \
     * nil ...
     *
     */
    else {
        T* y = x->p;
        while (y && y->left == x) {
            x = y;
            y = x->p;
        }
        return y;
    }
}

template<typename T> void 
binarySearchTree<T>::insert(const T &t) {// move instead of copy
    using std::shared_ptr;
    using std::make_shared;
    shared_ptr<T> p = make_shared<T>(t.key);
    T* z = p.get();
    T* x = root, y = nullptr;
    /* From CLRS p294 */
    while(x) {
        y = x;
        if (z->key < y->key) {
            x = x->left;
        }
        else {
            x = x->right;
        }
    } // end while
    z->p = y;
    if (y) {
        if (z->key < y->key) {
            y->left = z;
        }
        else {
            y->right = z;
        }
    }
    else {
        root = z;
    }
    return;
}


int main() {

    return 0;
}
