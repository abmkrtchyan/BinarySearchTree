#ifndef BINARY_SEARCH_TREE_BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_BINARY_SEARCH_TREE_H


#include <iostream>
#include <stack>
#include "AbstractBinaryTree.h"
#include "Node.h"

template<class T = int>
class BinarySearchTree : public AbstractBinaryTree<T> {
public:
    BinarySearchTree();

    class iterator {
    public:
        using value_type = T;
        using pointer_type = Node<T> *;
        using reference_type = T &;
        using iterator_category = std::forward_iterator_tag;

        explicit iterator(pointer_type head = nullptr) : mPtr(head) {
            if (mPtr != nullptr) {
                while (mPtr->left) {
                    moveToLeft();
                }
            }
        }

        reference_type operator*() {
            return (*mPtr).data;
        }

        pointer_type operator->() {
            return mPtr;
        }

        iterator &operator++() {
            if (mPtr->right != nullptr) {
                moveToRight();
                while (mPtr->left != nullptr) {
                    moveToLeft();
                }
            } else if (!stack.empty()) {
                mPtr = stack.top();
                stack.pop();
            } else {
                mPtr = nullptr;
            }
            return *this;
        }

        iterator::pointer_type operator++(int) {
            iterator::pointer_type tmp = mPtr;
            ++(*this);
            return tmp;
        }

        void moveToLeft() {
            stack.push(mPtr);
            mPtr = mPtr->left;
        }

        void moveToRight() {
            mPtr = mPtr->right;
        }

        bool operator==(const iterator &b) {
            return this->mPtr == b.mPtr;
        };

        bool operator!=(const iterator &b) {
            return this->mPtr != b.mPtr;
        };


    private:
        std::stack<pointer_type> stack;
        pointer_type mPtr;
    };

    class const_iterator {
    public:
        using value_type = T;
        using pointer_type = Node<T> *;
        using reference_type = T &;
        using iterator_category = std::forward_iterator_tag;

        explicit const_iterator(pointer_type head = nullptr) : mPtr(head) {
            if (mPtr != nullptr) {
                while (mPtr->left) {
                    moveToLeft();
                }
            }
        }

        reference_type operator*() const {
            return **mPtr;
        }

        pointer_type operator->() const {
            return mPtr;
        }

        const_iterator &operator++() {
            if (mPtr->right != nullptr) {
                moveToRight();
                while (mPtr->left != nullptr) {
                    moveToLeft();
                }
            } else if (!stack.empty()) {
                mPtr = stack.top();
                stack.pop();
            } else {
                mPtr = nullptr;
            }
            return *this;
        }

        void moveToLeft() {
            stack.push(mPtr);
            mPtr = mPtr->left;
        }

        void moveToRight() {
            mPtr = mPtr->right;
        }

        bool operator==(const iterator &b) const {
            return this->mPtr == b.mPtr;
        };

        bool operator!=(const iterator &b) const {
            return this->mPtr != b.mPtr;
        };


    private:
        std::stack<pointer_type> stack;
        pointer_type mPtr;
    };

    iterator begin() {
        return iterator(this->head);
    }

    iterator end() {
        return iterator(nullptr);
    }

    const_iterator cbegin() const {
        return const_iterator(this->head);
    }

    const_iterator cend() const {
        return const_iterator(nullptr);
    }

    Node<T> *search(const T &elem);

    void insert(const T &elem);

    void remove(const T &elem);

    void remove(Node<T> *v);

    void transplant(Node<T> *u, Node<T> *v);

    Node<T> *min(Node<T> *x);

    Node<T> *successor(Node<T> *x);

    void printTree(Node<T> *root, int space);

    void printTree();

    void inOrder();
};

template<class T>
void BinarySearchTree<T>::inOrder() {
    for (auto it: *this) {
        std::cout << it << " ";
    }
    std::cout << std::endl;
}

template<class T>
BinarySearchTree<T>::BinarySearchTree() = default;

template<class T>
void BinarySearchTree<T>::remove(const T &elem) {
    Node<T> *removedNode = this->search(elem);
    if (removedNode != nullptr)
        this->remove(removedNode);
}

#endif //BINARY_SEARCH_TREE_BINARY_SEARCH_TREE_H

template<class T>
Node<T> *BinarySearchTree<T>::search(const T &elem) {
    Node<T> *current = this->head;
    while (current != nullptr) {
        if (current->data == elem) {
            return current;
        }
        current = (elem < current->data) ? current->left : current->right;
    }
    return nullptr;
}

template<class T>
void BinarySearchTree<T>::insert(const T &elem) {
    Node<T> *current = this->head;
    Node<T> *parent = nullptr;
    while (current != nullptr) {
        parent = current;
        current = (elem < current->data) ? current->left : current->right;
    }
    current = new Node<T>(elem, parent);
    if (parent == nullptr) {
        this->head = current;
    } else {
        (elem < parent->data) ? parent->left = current : parent->right = current;
    }
}

template<class T>
void BinarySearchTree<T>::transplant(Node<T> *u, Node<T> *v) {
    if (!u->parent)
        this->head = v;
    else if (u->parent->left == u)
        u->parent->left = v;
    else
        u->parent->right = v;
    if (v)
        v->parent = u->parent;
}

template<class T>
Node<T> *BinarySearchTree<T>::min(Node<T> *x) {
    while (x->left)
        x = x->left;

    return x;
}

template<class T>
Node<T> *BinarySearchTree<T>::successor(Node<T> *x) {
    if (x->right)
        return min(x->right);
    else {
        auto parent = x->parent;
        while (parent and x == parent->right) {
            x = parent;
            parent = x->parent;
        }
        return parent;
    }
}

template<class T>
void BinarySearchTree<T>::remove(Node<T> *v) {
    if (!v->left)
        transplant(v, v->right);
    else if (!v->right)
        transplant(v, v->left);
    else {
        Node<T> *successor = this->successor(v);
        if (successor != v->right) {
            transplant(successor, successor->right);
            successor->right = v->right;
            successor->right->parent = successor;
        }
        transplant(v, successor);
        successor->left = v->left;
        successor->left->parent = successor;
    }
}

template<class T>
void BinarySearchTree<T>::printTree(Node<T> *root, int space) {
    if (root == nullptr)
        return;
    space += 6;
    printTree(root->left, space);
    std::cout << std::endl;
    for (int i = 6; i < space; i++) {
        std::cout << " ";
    }
    std::cout << root->data << "\n";
    printTree(root->right, space);
}

template<class T>
void BinarySearchTree<T>::printTree() {
    printTree(this->head, 0);
}
