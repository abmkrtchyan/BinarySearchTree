#ifndef BINARY_SEARCH_TREE_NODE_H
#define BINARY_SEARCH_TREE_NODE_H

template<class T = int>
class Node {
public:
    T data;
    Node *left;
    Node *right;
    Node *parent;

    T &operator*() {
        return data;
    }

    explicit Node(int data, Node *parent = nullptr, Node *left = nullptr, Node *right = nullptr) :
            data(data),
            left(left),
            right(right),
            parent(parent) {}
};

#endif //BINARY_SEARCH_TREE_NODE_H
