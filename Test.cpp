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
    for(int i = 35; i < 66; i++) {
        cout << "i=" << i << endl;
        tree.PrintAncestors(i);
        cout << endl;
    }
    return 0;
}