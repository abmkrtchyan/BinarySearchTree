#ifndef BINARY_SEARCH_TREE_BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_BINARY_SEARCH_TREE_H


#include <iostream>
#include <stack>
#include "AbstractBinaryTree.h"
#include "Node.h"

template <class T = int>
class BinarySearchTree : public AbstractBinaryTree<T>
{
protected:
    Node<T>* head = nullptr;

public:
    BinarySearchTree();

    class iterator
    {
    public:
        using value_type = T;
        using pointer = const value_type*;
        using reference = const value_type&;
        using difference_type = ptrdiff_t;
        using iterator_category = std::forward_iterator_tag;

        using node_type = Node<value_type>;

        explicit iterator(node_type* head = nullptr) : mPtr(head)
        {
            if (mPtr != nullptr)
            {
                while (mPtr->left)
                {
                    moveToLeft();
                }
            }
        }

        reference operator*() const
        {
            return **mPtr;
        }

        pointer operator->()
        {
            return &(**mPtr);
        }

        iterator& operator++()
        {
            if (mPtr->right != nullptr)
            {
                moveToRight();
                while (mPtr->left != nullptr)
                {
                    moveToLeft();
                }
            }
            else if (!stack.empty())
            {
                mPtr = stack.top();
                stack.pop();
            }
            else
            {
                mPtr = nullptr;
            }
            return *this;
        }

        iterator operator++(int)
        {
            iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        void moveToLeft()
        {
            stack.push(mPtr);
            mPtr = mPtr->left;
        }

        void moveToRight()
        {
            mPtr = mPtr->right;
        }

        bool operator==(const iterator& b) const
        {
            return this->mPtr == b.mPtr;
        };

        bool operator!=(const iterator& b) const
        {
            return this->mPtr != b.mPtr;
        };

    private:
        std::stack<node_type*> stack;
        node_type* mPtr;
    };


    iterator begin()
    {
        return iterator(this->head);
    }

    iterator end()
    {
        return iterator(nullptr);
    }

    ~BinarySearchTree() override
    {
        delete head;
    }

    Node<T>* search(const T& elem) override;

    void insert(const T& elem) override;

    void remove(const T& elem) override;

    void printTree();

private:
    void remove(Node<T>* v);

    void transplant(Node<T>* u, Node<T>* v);

    Node<T>* min(Node<T>* x);

    Node<T>* successor(Node<T>* x);

    void printTree(Node<T>* root, int space);
};

#endif //BINARY_SEARCH_TREE_BINARY_SEARCH_TREE_H


template <class T>
BinarySearchTree<T>::BinarySearchTree() = default;

template <class T>
void BinarySearchTree<T>::remove(const T& elem)
{
    Node<T>* removedNode = this->search(elem);
    if (removedNode != nullptr)
        this->remove(removedNode);
}


template <class T>
Node<T>* BinarySearchTree<T>::search(const T& elem)
{
    Node<T>* current = this->head;
    while (current != nullptr)
    {
        if (**current == elem)
        {
            return current;
        }
        current = (elem < **current) ? current->left : current->right;
    }
    return nullptr;
}

template <class T>
void BinarySearchTree<T>::insert(const T& elem)
{
    auto newNode = new Node<T>(elem);

    Node<T>* current = this->head;
    Node<T>* parent = nullptr;
    while (current != nullptr)
    {
        parent = current;
        current = (*newNode < *current) ? current->left : current->right;
    }

    newNode->parent = parent;
    if (parent == nullptr)
    {
        this->head = newNode;
    }
    else
    {
        (*newNode < *parent) ? parent->left = newNode : parent->right = newNode;
    }
}

template <class T>
void BinarySearchTree<T>::transplant(Node<T>* u, Node<T>* v)
{
    if (!u->parent)
        this->head = v;
    else if (u->parent->left == u)
        u->parent->left = v;
    else
        u->parent->right = v;
    if (v)
        v->parent = u->parent;
}

template <class T>
Node<T>* BinarySearchTree<T>::min(Node<T>* x)
{
    while (x->left)
        x = x->left;

    return x;
}

template <class T>
Node<T>* BinarySearchTree<T>::successor(Node<T>* x)
{
    if (x->right)
        return min(x->right);
    else
    {
        auto parent = x->parent;
        while (parent and x == parent->right)
        {
            x = parent;
            parent = x->parent;
        }
        return parent;
    }
}

template <class T>
void BinarySearchTree<T>::remove(Node<T>* v)
{
    if (!v->left)
        transplant(v, v->right);
    else if (!v->right)
        transplant(v, v->left);
    else
    {
        Node<T>* successor = this->successor(v);
        if (successor != v->right)
        {
            transplant(successor, successor->right);
            successor->right = v->right;
            successor->right->parent = successor;
        }
        transplant(v, successor);
        successor->left = v->left;
        successor->left->parent = successor;
    }
}

template <class T>
void BinarySearchTree<T>::printTree(Node<T>* root, int space)
{
    if (root == nullptr)
        return;
    space += 6;
    printTree(root->left, space);
    std::cout << std::endl;
    for (int i = 6; i < space; i++)
    {
        std::cout << " ";
    }
    std::cout << **root << "\n";
    printTree(root->right, space);
}

template <class T>
void BinarySearchTree<T>::printTree()
{
    printTree(this->head, 0);
}
