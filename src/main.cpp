#include "BinarySearchTree.h"
#include "AbstractBinaryTree.h"

int main() {
    AbstractBinaryTree<char> *tree = new BinarySearchTree<char>();
    tree->insert('A');
    tree->insert('B');
    tree->insert('C');
    std::cout << "______________________________________" << std::endl;
    tree->printTree();
    tree->remove('F');
    tree->remove('A');
    std::cout << "______________________________________" << std::endl;
    tree->printTree();
    std::cout << "______________________________________" << std::endl;
    return 0;
}
