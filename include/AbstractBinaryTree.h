#ifndef BINARY_SEARCH_TREE_ABSTRACT_BINARY_TREE_H
#define BINARY_SEARCH_TREE_ABSTRACT_BINARY_TREE_H

#include "Node.h"

template<class T = int>
class AbstractBinaryTree {
protected:
    Node<T> *head;
public:
    virtual Node<T> *search(const T &elem) = 0;

    virtual void insert(const T &elem) = 0;

    virtual void remove(const T &elem) = 0;

    virtual void printTree() = 0;
};

#endif //BINARY_SEARCH_TREE_ABSTRACT_BINARY_TREE_H
