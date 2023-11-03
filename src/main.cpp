#include <set>
#include "BinarySearchTree.h"

int main() {
    auto set = new std::set<char>();
    set->insert('D');
    set->insert('E');
    set->insert('B');
    set->insert('A');
    set->insert('G');
    set->insert('C');
    set->insert('F');
    auto item = std::find(set->begin(), set->end(), 'B');
//    *item = 9;
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
        *it = 9;
    }
    tree->inOrder();
    auto node = std::find(tree->begin(), tree->end(), 'B');
    return 0;
}
