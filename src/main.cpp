#include <set>
#include "BinarySearchTree.h"

int main() {
    auto set = new std::set<int>();
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
    auto iterator1 = std::find(tree->begin(), tree->end(), 'B');
    iterator1 = std::find(tree->begin(), tree->end(), 'D');
    std::cout << *iterator1;
    std::cout << std::endl;
    std::cout << *std::max_element(tree->begin(), tree->end());
    return 0;
}
