#include <fstream>
#include <string>

#include "QueType.cpp"

template <class ItemType>
struct TreeNode;

template <class ItemType>
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
    TreeNode<ItemType>* root;
    void Destroy(TreeNode<ItemType>*& tree);
    void Retrieve(TreeNode<ItemType>* tree, ItemType& item, bool& found);
    void Insert(TreeNode<ItemType>*& tree, ItemType item);
    void DeleteNode(TreeNode<ItemType>*& tree);
    void Delete(TreeNode<ItemType>*& tree, ItemType item);
    void GetPredecessor(TreeNode<ItemType>* tree, ItemType& data);
    int CountNodes(TreeNode<ItemType>* tree) const;
    TreeNode<ItemType>* GetTreeNode(TreeNode<ItemType>* root, int value);
    TreeNode<ItemType>* PtrToSuccessor(TreeNode<ItemType>*& tree);
    void inOrderTraverse(TreeNode<ItemType>* tree) const;
    void preOrderTraverse(TreeNode<ItemType>* tree) const;
    void postOrderTraverse(TreeNode<ItemType>* tree) const;
    void mirror(TreeNode<ItemType>*& copy, const TreeNode<ItemType>* originalTree);
    void CopyTree(TreeNode<ItemType>*& copy, const TreeNode<ItemType>* originalTree);
};
