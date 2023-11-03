#include "BinarySearchTree.h"
#include "AbstractBinaryTree.h"

int main() {
    auto tree = new BinarySearchTree<char>();
    tree->insert('A');
    tree->insert('B');
    tree->insert('C');
    std::cout << "______________________________________" << std::endl;
//    tree->printTree();
    tree->inOrder();
    tree->remove('F');
    tree->remove('A');
    std::cout << "______________________________________" << std::endl;
//    tree->printTree();
    tree->inOrder();
    std::cout << "______________________________________" << std::endl;
    char val = 'B';
    for (auto it = tree->begin(); it != tree->end(); it++) {
        std::cout << *it;
    }
//    auto node = std::find(tree->begin(), tree->end(), val);
    return 0;
}
