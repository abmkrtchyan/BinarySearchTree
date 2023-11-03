#include <set>
#include "BinarySearchTree.h"

int main() {
    auto tree = new BinarySearchTree<char>();
    tree->insert('D');
    tree->insert('E');
    tree->insert('B');
    tree->insert('A');
    tree->insert('G');
    tree->insert('C');
    tree->insert('F');
    std::cout << "______________________________________" << std::endl;
    tree->inOrder();
    tree->remove('F');
    tree->remove('A');
    std::cout << "______________________________________" << std::endl;
    tree->inOrder();
    std::cout << "______________________________________" << std::endl;
    for (auto it = tree->begin(); it != tree->end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << "______________________________________" << std::endl;
    tree->inOrder();
    std::cout << *std::find(tree->begin(), tree->end(), 'B');
    return 0;
}
