// Test driver

#include <cctype>
#include <cstring>
#include <iostream>
#include <string>

#include "TreeType.cpp"
using namespace std;

// TreeType& makeTree(int arr[], int size);
template <class ItemType>
void makeTree(TreeType<ItemType>& balancedTree, int arr[], int size);

template <class ItemType>
void makeBalancedTree(TreeType<ItemType>& balancedTree, int arr[], int lower, int higher);

int main() {
    string command;  // operation to be executed

    int item;
    TreeType<int> tree;
    bool found;
    ifstream inFile;
    inFile.open("input.txt");
    inFile >> command;

    cout << "Implemented by Eric Chow" << endl;

    while(command != "Quit") {
        // 1
        if(command == "PutItem") {
            // cout << "Enter Item to be inserted in the tree  ";
            inFile >> item;
            tree.PutItem(item);
            cout << item;
            cout << " is inserted" << endl;
        }
        // 2
        else if(command == "DeleteItem") {
            inFile >> item;
            tree.DeleteItem(item);
        }
        // 3
        else if(command == "GetItem") {
            inFile >> item;
            item = tree.GetItem(item, found);
            if(found)
                cout << item << " found in tree." << endl;
            else
                cout << item << "  is not in tree." << endl;
        }
        // 4
        else if(command == "GetLength") {
            cout << "Calling GetLength\n";
            cout << "Number of nodes is " << tree.GetLength() << endl;
        }
        // 5
        else if(command == "IsEmpty")
            if(tree.IsEmpty())
                cout << "Tree is empty." << endl;
            else
                cout << "Tree is not empty." << endl;
        // 6
        else if(command == "IsFull")
            if(tree.IsFull())
                cout << "Tree is full." << endl;
            else
                cout << "Tree is not full." << endl;
        // 7
        else if(command == "Print") {
            cout << "Printing the tree...InOrder Traversal\n";
            tree.Print();
            cout << endl;
        }
        // 8
        else if(command == "PreOrderPrint") {
            cout << "PreOrder Print:\n";
            tree.PreOrderPrint();
            cout << endl;
        }
        // 9
        else if(command == "PostOrderPrint") {
            cout << "PostOrder Print:\n";
            tree.PostOrderPrint();
            cout << endl;
        }
        // 10
        else if(command == "LevelOrderPrint") {
            cout << "LevelOrder Print:\n\n";
            tree.LevelOrderPrint();
        }
        // 11
        else if(command == "MakeEmpty") {
            tree.MakeEmpty();
            std::cout << "Tree has been made empty." << endl;
        }

        // 12
        else if(command == "GetSuccessor") {
            inFile >> item;
            cout << "Logical successor of " << item << " is: ";
            tree.GetSuccessor(item);
        }
        // 13
        else if(command == "PrintAncestorsOf") {
            inFile >> item;
            cout << "testing Ancestors of " << item << endl;
            tree.PrintAncestors(item);
        }
        // 14
        else if(command == "MirrorImage") {
            cout << "Testing Mirror Image\n";
            tree.MakeEmpty();
            tree.PutItem(10);
            tree.PutItem(13);
            tree.PutItem(5);
            tree.PutItem(4);
            tree.PutItem(7);
            tree.PutItem(12);
            tree.PutItem(20);
            cout << "\nOriginal Tree before mirroring:\n" << endl;
            tree.LevelOrderPrint();
            TreeType<int> mirrorOftree;
            tree.mirrorImage(mirrorOftree);
            cout << "Original Tree After Mirroring:\n" << endl;
            tree.LevelOrderPrint();
            cout << "Mirror Image:\n" << endl;
            mirrorOftree.LevelOrderPrint();
        }

        // 15
        else if(command == "MakeTree") {
            int array[100], length;
            inFile >> length;
            for(int i = 0; i < length; i++) inFile >> array[i];
            // After implementing makeTree
            // Remove the follwoing comment to call the function
            TreeType<int> balancedTree;
            makeTree(balancedTree, array, length);
            cout << "balancedTree.LevelOrderPrint()\n" << endl;
            balancedTree.LevelOrderPrint();
            cout << "balancedTree.InOrderPrint()" << endl;
            for(int i = 0; i < length; i++) {
                cout << array[i] << "  ";
            }
            cout << endl;
        } else
            cout << "Undefined Command!" << command << endl;
        inFile >> command;
    }
    cout << "Testing completed." << endl;

    return 0;
}

// implement this function
// you may define and call helper functions.
// The helper function could be an iterative or a recursive function.
template <class ItemType>
void makeTree(TreeType<ItemType>& balancedTree, int arr[], int size) {
    // call recursive function to make bst
    makeBalancedTree(balancedTree, arr, 0, size);
}

template <class ItemType>
void makeBalancedTree(TreeType<ItemType>& balancedTree, int arr[], int lower, int higher) {
    if(lower == higher) {
        // base case, when there is only one element
        return;
    }

    // General cases
    int mid = (lower + higher) / 2;                        // calcualate mid-point
    balancedTree.PutItem(arr[mid]);                        // add element at mid-point to Tree
    makeBalancedTree(balancedTree, arr, lower, mid);       // perform recursion on left half
    makeBalancedTree(balancedTree, arr, mid + 1, higher);  // perform recursion on right half
}
