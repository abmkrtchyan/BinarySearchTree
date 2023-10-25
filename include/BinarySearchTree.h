#ifndef BINARY_SEARCH_TREE_BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_BINARY_SEARCH_TREE_H


#include <iostream>
#include "Node.h"

template<class T = int>
class BinarySearchTree {
private:
    Node<T> *head;
public:
    BinarySearchTree();

    Node<T> *search(const T &elem);

    void insert(const T &elem);

    void remove(const T &elem);

    void printInorderTraversal();

    void printTree(Node<T> *root, int space);

    void printTree();
};

#endif //BINARY_SEARCH_TREE_BINARY_SEARCH_TREE_H

template<class T>
Node<T> *BinarySearchTree<T>::search(const T &elem) {
    Node<T> *current = this->head;
    while (current) {
        if (current->data == elem) return current;
        current = (elem < current->data) ? current->left : current->right;
    }
    return nullptr;
}

template<class T>
void BinarySearchTree<T>::insert(const T &elem) {
    Node<T> *current = this->head;
    Node<T> *parent = nullptr;
    while (current) {
        parent = current;
        current = (elem < current->data) ? current->left : current->right;
    }
    current = new Node(elem, parent);
    if (parent == nullptr) {
        this->head = current;
    } else {
        (elem < parent->data) ? parent->left = current : parent->right = current;
    }
}

template<class T>
void BinarySearchTree<T>::remove(const T &elem) {
    Node<T> *current = search(elem);
    if (current == nullptr) {
        return;
    };
    Node<T> *next;
    if (current->left && current->right) {
        next = current->right;
        while (next->left) {
            current->data = next->data;
            current = next;
            next = next->left;
        }
    } else if (current->left == nullptr) {
        if (current->parent != nullptr)
            if (current == current->parent->left)
                current->parent->left = current->right;
            else
                current->parent->right = current->right;
        else
            this->head = current->right;
        if (current->right)
            current->right->parent = current->parent;
        delete current;
        return;
    } else if (current->parent)
        if (current == current->parent->left)
            current->parent->left = current->left;
        else
            current->parent->right = current->left;
    else
        this->head = current->left;
    current->left->parent = current->parent;
    delete current;
}

template<class T>
void BinarySearchTree<T>::printInorderTraversal() {

}

template<class T>
void BinarySearchTree<T>::printTree(Node<T> *root, int space) {
    if (root == nullptr)
        return;
    space += 6;
    printTree(root->right, space);
    std::cout << std::endl;
    for (int i = 6; i < space; i++) {
        std::cout << " ";
    }
    std::cout << root->data << "\n";
    printTree(root->left, space);
}

template<class T>
void BinarySearchTree<T>::printTree() {
    printTree(this->head, 0);
}

template<class T>
BinarySearchTree<T>::BinarySearchTree() : head(nullptr) {}

