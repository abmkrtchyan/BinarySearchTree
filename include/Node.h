#ifndef BINARY_SEARCH_TREE_NODE_H
#define BINARY_SEARCH_TREE_NODE_H

template<class T = int>
class Node {
private:
    T data;
public:
    Node *left;
    Node *right;
    Node *parent;

    T &operator*() {
        return data;
    }

    bool operator<(const Node<T> &other) {
        return this->data < other.data;
    }

    explicit Node(int data, Node *parent = nullptr, Node *left = nullptr, Node *right = nullptr) :
            data(data),
            left(left),
            right(right),
            parent(parent) {}
};

#endif //BINARY_SEARCH_TREE_NODE_H
