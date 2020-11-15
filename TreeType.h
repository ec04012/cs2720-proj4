#include <fstream>
#include <string>
typedef int ItemType;
struct TreeNode;
#include "QueType.cpp"
class TreeType {
   public:
    TreeType();                              // constructor
    TreeType(const TreeType& originalTree);  // copy constructor
    ~TreeType();                             // destructor
    void MakeEmpty();
    bool IsEmpty() const;
    bool IsFull() const;
    int GetLength() const;
    ItemType GetItem(ItemType item, bool& found);
    void PutItem(ItemType item);
    void DeleteItem(ItemType item);
    void operator=(const TreeType& originalTree);
    void Print() const;
    void LevelOrderPrint() const;
    void PrintAncestors(int value);
    void PreOrderPrint() const;
    void PostOrderPrint() const;
    int GetSuccessor(int value);
    void mirrorImage(TreeType& t);

   private:
    TreeNode* root;
    void Destroy(TreeNode*& tree);
    void Retrieve(TreeNode* tree, ItemType& item, bool& found);
    void Insert(TreeNode*& tree, ItemType item);
    void DeleteNode(TreeNode*& tree);
    void Delete(TreeNode*& tree, ItemType item);
    void GetPredecessor(TreeNode* tree, ItemType& data);
    int CountNodes(TreeNode* tree) const;
    TreeNode* GetTreeNode(TreeNode* root, int value);
    TreeNode* PtrToSuccessor(TreeNode*& tree);
    void inOrderTraverse(TreeNode* tree) const;
    void preOrderTraverse(TreeNode* tree) const;
    void postOrderTraverse(TreeNode* tree) const;
    void mirror(TreeNode*& copy, const TreeNode* originalTree);
    void CopyTree(TreeNode*& copy, const TreeNode* originalTree);
};
