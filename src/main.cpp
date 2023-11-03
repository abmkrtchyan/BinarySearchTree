#include <set>
#include "BinarySearchTree.h"

int main() {
    auto tree = new BinarySearchTree<char>();
    std::cout << "______________________________________" << std::endl;
    tree->insert('D');
    tree->insert('E');
    tree->insert('B');
    tree->insert('A');
    tree->insert('G');
    tree->insert('C');
    tree->insert('F');
    tree->inOrder();
    std::cout << "______________________________________" << std::endl;
    tree->remove('F');
    tree->inOrder();
    std::cout << "______________________________________" << std::endl;
    tree->remove('A');
    tree->inOrder();
    std::cout << "______________________________________" << std::endl;
    for (auto it = tree->begin(); it != tree->end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << "\n______________________________________" << std::endl;
    std::cout << *std::find(tree->begin(), tree->end(), 'B');
    std::cout << std::endl;
    std::cout << *std::max_element(tree->begin(), tree->end());
    return 0;
}
