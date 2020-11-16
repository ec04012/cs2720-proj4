#include <iostream>
using namespace std;
#include <cmath>

#include "TreeType.h"

struct TreeNode {
    ItemType info;
    TreeNode* left;
    TreeNode* right;
};

TreeType::TreeType() {
    // Default constructor
    root = NULL;
}

TreeType::TreeType(const TreeType& originalTree) {
    // Implement this
    // CopyTree(root, originalTree.root);
    root = NULL;
}

void TreeType::Destroy(TreeNode*& tree)
// Post: tree is empty; nodes have been deallocated.
{
    if(tree != NULL) {
        Destroy(tree->left);
        Destroy(tree->right);
        delete tree;
    }
}

TreeType::~TreeType()
// Calls recursive function Destroy to destroy the tree.
{
    Destroy(root);
}

bool TreeType::IsFull() const
// Returns true if there is no room for another item
//  on the free store; false otherwise.
{
    TreeNode* location;
    try {
        location = new TreeNode;
        delete location;
        return false;
    } catch(std::bad_alloc exception) {
        return true;
    }
}

bool TreeType::IsEmpty() const
// Returns true if the tree is empty; false otherwise.
{
    return root == NULL;
}

int TreeType::GetLength() const
// Calls recursive function CountNodes to count the
// nodes in the tree.
{
    return CountNodes(root);
}

int TreeType::CountNodes(TreeNode* tree) const
// Post: returns the number of nodes in the tree.
{
    if(tree == NULL)
        return 0;
    else
        return CountNodes(tree->left) + CountNodes(tree->right) + 1;
}

// helper function for GetItem
void TreeType::Retrieve(TreeNode* tree, ItemType& item, bool& found)
// Recursively searches tree for item.
// Post: If there is an element someItem whose key matches item's,
//       found is true and item is set to a copy of someItem;
//       otherwise found is false and item is unchanged.
{
    if(tree == NULL)
        found = false;  // item is not found.
    else if(item < tree->info)
        Retrieve(tree->left, item, found);  // Search left subtree.
    else if(item > tree->info)
        Retrieve(tree->right, item, found);  // Search right subtree.
    else {
        item = tree->info;  // item is found.
        found = true;
    }
}

ItemType TreeType::GetItem(ItemType item, bool& found)
// Calls recursive function Retrieve to search the tree for item.
{
    Retrieve(root, item, found);
    return item;
}

void TreeType::PutItem(ItemType item)
// Calls recursive function Insert to insert item into tree.
{
    Insert(root, item);
}

// helper Function for PutItem
void TreeType::Insert(TreeNode*& tree, ItemType item)
// Inserts item into tree.
// Post:  item is in tree; search property is maintained.
{
    if(tree == NULL) {  // Insertion place found.
        tree = new TreeNode;
        tree->right = NULL;
        tree->left = NULL;
        tree->info = item;
    } else if(item < tree->info)
        Insert(tree->left, item);  // Insert in left subtree.
    else
        Insert(tree->right, item);  // Insert in right subtree.
}

void TreeType::DeleteItem(ItemType item)
// Calls recursive function Delete to delete item from tree.
{
    bool found = false;
    GetItem(item, found);
    if(found)
        Delete(root, item);
    else
        cout << item << "is not in tree\n";
}

void TreeType::Delete(TreeNode*& tree, ItemType item)
// Deletes item from tree.
// Post:  item is not in tree.
{
    if(item < tree->info)
        Delete(tree->left, item);  // Look in left subtree.
    else if(item > tree->info)
        Delete(tree->right, item);  // Look in right subtree.
    else
        DeleteNode(tree);  // Node found; call DeleteNode.
}

void TreeType::DeleteNode(TreeNode*& tree)
// Deletes the node pointed to by tree.
// Post: The user's data in the node pointed to by tree is no
//       longer in the tree.  If tree is a leaf node or has only
//       non-NULL child pointer the node pointed to by tree is
//       deleted; otherwise, the user's data is replaced by its
//       logical predecessor and the predecessor's node is deleted.
{
    ItemType data;
    TreeNode* tempPtr;

    tempPtr = tree;
    if(tree->left == NULL) {
        tree = tree->right;
        delete tempPtr;
    } else if(tree->right == NULL) {
        tree = tree->left;
        delete tempPtr;
    } else {
        GetPredecessor(tree->left, data);
        tree->info = data;
        Delete(tree->left, data);  // Delete predecessor node.
    }
}

// Helper function for DeleteNode
void TreeType::GetPredecessor(TreeNode* tree, ItemType& data)
// Sets data to the info member of the right-most node in tree.
{
    while(tree->right != NULL) tree = tree->right;
    data = tree->info;
}

// Helper function for Print
void TreeType::inOrderTraverse(TreeNode* tree) const
// Prints info member of items in tree in sorted order on screen.
{
    if(tree != NULL) {
        inOrderTraverse(tree->left);  // Print left subtree.
        cout << tree->info << "  ";
        inOrderTraverse(tree->right);  // Print right subtree.
    }
}

// Helper function for Print
void TreeType::preOrderTraverse(TreeNode* tree) const
// Prints info member of items in tree in pre order traversal on screen.
{
    if(tree != NULL) {
        cout << tree->info << "  ";
        preOrderTraverse(tree->left);   // Print left subtree.
        preOrderTraverse(tree->right);  // Print right subtree.
    }
}

// Helper function for Print
void TreeType::postOrderTraverse(TreeNode* tree) const
// Prints info member of items in tree in post order traversal on screen.
{
    if(tree != NULL) {
        postOrderTraverse(tree->left);   // Print left subtree.
        postOrderTraverse(tree->right);  // Print right subtree.
        cout << tree->info << "  ";
    }
}

void TreeType::Print() const
// Calls recursive function inOrderTraverse to print items in the tree.
{
    inOrderTraverse(root);
}
void TreeType::PreOrderPrint() const {  // Implement this function, You may call a helper function
                                        // Then Remove the following stub statement
    preOrderTraverse(root);
    // cout << "PreOrderPrint stub has been called\n";
}
void TreeType::PostOrderPrint() const {
    // Implement this function, You may call a helper function
    // Then Remove the following stub statement
    postOrderTraverse(root);
    // cout << "Post OrderPrint stub has been called\n";
}
void TreeType::PrintAncestors(int value) {
    // Implement this function, You may call a helper function
    // Then Remove the following stub statement

    if(root != NULL && root->info == value) {
        cout << value << " is the root value, No ancestor" << endl;
        return;
    }
    if(root == NULL) {
        cout << "Tree is empty" << endl;
        return;
    }

    // What to do for PrintAncestors on empty list?

    TreeNode* temp = root;
    QueType<int> que;
    bool inTree = true;

    while(temp != NULL && temp->info != value && inTree) {
        if(temp->info < value && temp->right != NULL) {
            que.Enqueue(temp->info);
            temp = temp->right;
        } else if(temp->info > value && temp->left != NULL) {
            que.Enqueue(temp->info);
            temp = temp->left;
        } else if(temp->info == value) {
            inTree = true;
        } else {
            inTree = false;
        }  // if else
    }      // while

    if(inTree) {
        ItemType item;
        while(!que.IsEmpty()) {
            que.Dequeue(item);
            if(item != value) {
                cout << item << " ";
            }
        }  // while
        cout << endl;
        return;
    }
    cout << value << " is not in the tree" << endl;
}

TreeNode* TreeType::GetTreeNode(TreeNode* root, int value) {
    // Helper function for GetSuccessor
    // Searches the tree for value and returns the node containing it.
    // If value is not in the tree, the pointer will be NULL.
    if(root == NULL) {
        return root;
    } else if(value < root->info) {
        return GetTreeNode(root->left, value);  // Search left subtree
    } else if(value > root->info) {
        return GetTreeNode(root->right, value);  // Search right subtree.
    } else {
        return root;
    }
}

TreeNode* TreeType::PtrToSuccessor(TreeNode*& tree) {
    // Helper function for GetSuccessor
    // returns a pointer to node with the smallest key value in the tree.
    TreeNode* successor = tree;
    while(successor->left != NULL) successor = successor->left;
    return successor;
}

int TreeType::GetSuccessor(int value) {
    // Implement this function, You may call a helper function
    TreeNode* currentNode = GetTreeNode(root, value);
    if(currentNode != NULL) {
        currentNode = currentNode->right;
        if(currentNode != NULL) {
            TreeNode* successor = PtrToSuccessor(currentNode);
            cout << successor->info << endl;
            return successor->info;
        }
        cout << "NULL Successor" << endl;
    } else {
        cout << "Item is not in tree." << endl;
    }
    // Then Remove the following stub statement
    return 0;  // you should change this return statement
}

// helper function for Mirror Image
void TreeType::mirror(TreeNode*& copy, const TreeNode* originalTree)
// Post: copy is the root of a tree that is a mirror Image of originalTree.
{  // implement this function
}

void TreeType::mirrorImage(TreeType& t) {
    // calls the helper function mirror
}

void TreeType::MakeEmpty() {
    Destroy(root);
    root = NULL;
}
void TreeType::CopyTree(TreeNode*& copy, const TreeNode* originalTree)
// Post: copy is the root of a tree that is a duplicate
// of originalTree.
{
    if(originalTree == NULL)
        copy = NULL;
    else {
        copy = new TreeNode;
        copy->info = originalTree->info;
        CopyTree(copy->left, originalTree->left);
        CopyTree(copy->right, originalTree->right);
    }
}

void TreeType::operator=(const TreeType& originalTree)
// Calls recursive function CopyTree to copy originalTree
// into root.
{
    {
        if(&originalTree == this) return;  // Ignore assigning self to self
        Destroy(root);                     // Deallocate existing tree nodes
        CopyTree(root, originalTree.root);
    }
}

void TreeType::LevelOrderPrint() const {  // Implement this function, you May use a data structure
    QueType<TreeNode*> nodeQue;
    TreeNode* currentNode;
    if(root != NULL) {
        currentNode = root;
        nodeQue.Enqueue(currentNode);
        int numNodesPrinted = 0;
        int sizeOfTree = CountNodes(root);  // used to stop printing once we've printed every node
        int i = 0;                          // Used to track how many nodes on a level we've printed
        int currentLevel = 0;               // used two track num of nodes on our current level

        // Align top level
        for(int j = 0; j < sizeOfTree; j++) {
            cout << "  ";
        }

        // Keep printing nodes until the queue is empty and we've printed every node.
        while(!nodeQue.IsEmpty() && numNodesPrinted < sizeOfTree) {
            nodeQue.Dequeue(currentNode);

            if(i == pow(2, currentLevel)) {
                // If we've reached the end of a level, print \n and align next level before continuing
                cout << endl;
                for(int j = 0; j < sizeOfTree - currentLevel - 1; j++) {
                    cout << "  ";
                }
                i = 0;
                currentLevel++;
            }

            // If the node is not NULL, enqueue left and right, and print the node's value
            if(currentNode != NULL) {
                nodeQue.Enqueue(currentNode->left);
                nodeQue.Enqueue(currentNode->right);
                cout << currentNode->info << " ";
                numNodesPrinted = numNodesPrinted + 1;  // Increment this every time we dequeue a non-null TreeNode
            } else {
                // If the node is null, print -
                cout << "- ";
            }
            i++;  // increment i everytime we print something, use i to keep track of how many nodes on a level we've printed
        }         // while que is not empty

        // If necessary, print extra dashes to fill current level
        /*
        int sizeOfCurrentLevel = pow(2, currentLevel);
        if(i < sizeOfCurrentLevel) {
            for(int j = i; j < sizeOfCurrentLevel; j++) {
                cout << "- ";
            }
        }
        */

    }  // if root is not null (ie if the tree is not empty)
}
