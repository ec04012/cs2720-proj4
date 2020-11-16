#include <iostream>

#include "TreeType.cpp"

using namespace std;

int main() {
    TreeType<int> tree;
    TreeType<int> mirror;

    cout << "Getting 10" << endl;
    bool found = false;
    cout << tree.GetItem(10, found);
    cout << "GettingLength" << endl;
    cout << tree.GetLength();
    cout << "Tree is empty" << endl;
    cout << tree.IsEmpty();
    cout << "Tree is full" << endl;
    cout << tree.IsEmpty();
    cout << "In order" << endl;
    tree.Print();
    cout << "Pre order" << endl;
    tree.PreOrderPrint();
    cout << "Post order" << endl;
    tree.PostOrderPrint();
    cout << "Level order" << endl;
    tree.LevelOrderPrint();
    cout << "Make empty" << endl;
    tree.MakeEmpty();
    cout << "Get successor" << endl;
    tree.GetSuccessor(10);
    cout << "Print ancestors" << endl;
    tree.PrintAncestors(10);
    cout << "Mirror image" << endl;
    tree.mirrorImage(mirror);

    exit(0);

    tree.PutItem(50);
    tree.PutItem(40);
    tree.PutItem(60);
    tree.PutItem(35);
    tree.PutItem(45);
    tree.PutItem(55);
    tree.PutItem(65);
    tree.LevelOrderPrint();
    cout << endl;
    TreeType<int> tree2(tree);
    tree2.LevelOrderPrint();
    cout << endl;

    tree2.DeleteItem(35);
    tree2.PutItem(100);

    cout << "======================" << endl;

    tree.LevelOrderPrint();
    cout << endl;

    tree2.LevelOrderPrint();
    cout << endl;

    tree.mirrorImage(tree2);
    cout << endl;

    cout << "======================" << endl;

    tree.LevelOrderPrint();
    cout << endl;

    tree2.LevelOrderPrint();
    cout << endl;

    cout << endl;
    return 0;
}