#include <iostream>

#include "TreeType.h"

using namespace std;

int main() {
    TreeType tree;
    tree.PutItem(50);
    tree.PutItem(40);
    tree.PutItem(60);
    tree.PutItem(35);
    tree.PutItem(45);
    tree.PutItem(55);
    tree.PutItem(65);
    tree.LevelOrderPrint();
    cout << endl;
    TreeType tree2(tree);
    tree2.LevelOrderPrint();
    cout << endl;

    tree2.DeleteItem(35);
    tree2.PutItem(100);

    tree.LevelOrderPrint();
    cout << endl;

    tree2.LevelOrderPrint();
    cout << endl;
    return 0;
}