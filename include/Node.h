#ifndef BINARY_SEARCH_TREE_NODE_H
#define BINARY_SEARCH_TREE_NODE_H

template <class T = int>
class Node
{
public:
    T data;
    Node* left;
    Node* right;
    Node* parent;

    const T& operator*()
    {
        return data;
    }

    bool operator<(const Node& other)
    {
        return this->data < other.data;
    }

    Node(const T& data, Node* parent = nullptr, Node* left = nullptr, Node* right = nullptr) :
        data(data),
        left(left),
        right(right),
        parent(parent)
    {
    }

    ~Node()
    {
        delete left;
        delete right;
        delete parent;
    }
};

#endif //BINARY_SEARCH_TREE_NODE_H
