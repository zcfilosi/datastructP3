#include <string>
#include <fstream>
#include <iostream>
#include <vector>
//typedef int ItemType;
template<class ItemType>
struct TreeNode;

#include "QueType.h"
enum OrderType {PRE_ORDER, IN_ORDER, POST_ORDER};

template <class ItemType>
class TreeType
{
public:
  TreeType();                     // constructor
 ~TreeType();                    // destructor
  TreeType(const TreeType& originalTree);
  void operator=(const TreeType& originalTree);
  // copy constructor
  void MakeEmpty();
  void prePrint()const;
  void inPrint()const;
  void postPrint()const;
  void PreOrderPrint();
  void InOrderPrint();
  void PostOrderPrint();
  int LevelOrderPrint();
  bool IsEmpty() const;
  bool IsFull() const;
  int GetLength() const;
  ItemType GetItem(ItemType item, bool& found);
  void PutItem(ItemType item);
  void DeleteItem(ItemType item);
  void ResetTree(OrderType order);
  ItemType GetNextItem(OrderType order, bool& finished);
  void Print() const;
private:
  TreeNode<ItemType>* root;
  QueType<ItemType> preQue;
  QueType<ItemType> inQue;
  QueType<ItemType> postQue;
};



// Function prototypes for auxiliary functions.
template<class ItemType>
void PreOrder(TreeNode<ItemType>*, QueType<ItemType>&);
// Enqueues tree items in preorder.
template<class ItemType>
void InOrder(TreeNode<ItemType>*, QueType<ItemType>&);
// Enqueues tree items in inorder.
template<class ItemType>
void PostOrder(TreeNode<ItemType>*, QueType<ItemType>&);
// Enqueues tree items in postorder.

template<class ItemType>
struct TreeNode
{
  ItemType info;
  TreeNode* left;
  TreeNode* right;
};


template<class ItemType>
void PreOrder(TreeNode<ItemType>* tree,
     QueType<ItemType>& preQue)
// Post: preQue contains the tree items in preorder.
{
  if (tree != NULL)
  {
    preQue.Enqueue(tree->info);
    PreOrder(tree->left, preQue);
    PreOrder(tree->right, preQue);
  }
}

template<class ItemType>
void InOrder(TreeNode<ItemType>* tree,
     QueType<ItemType>& inQue)
// Post: inQue contains the tree items in inorder.
{
  if (tree != NULL)
  {
    InOrder(tree->left, inQue);
    inQue.Enqueue(tree->info);
    InOrder(tree->right, inQue);
  }
}

template<class ItemType>
void PostOrder(TreeNode<ItemType>* tree,
     QueType<ItemType>& postQue)
// Post: postQue contains the tree items in postorder.
{
  if (tree != NULL)
  {
    PostOrder(tree->left, postQue);
    PostOrder(tree->right, postQue);
    postQue.Enqueue(tree->info);
  }
}

template<class ItemType>
int TreeType<ItemType>::LevelOrderPrint(){
    if(root==NULL){
        return 0;
    }
    std::vector<std::vector<TreeNode<ItemType> *>> nodeStack(20);
    std::vector<std::vector<char>> branchStack(20);

    int z = 0;
    int numspaces = (this->GetLength())/2;
    for(int space = 0; space<numspaces; space++)
        std::cout<<" ";

    nodeStack.at(z).push_back(root);
    if(root->left !=NULL){
        branchStack.at(z).push_back('/');

    }
    if(root->right !=NULL){
        branchStack.at(z).push_back('\\');

    }
    std::cout<<root->info<<std::endl;
    for(int space = 0; space<numspaces; space++)
        std::cout<<" ";
    numspaces--;
    if(!branchStack.at(z).empty()){
        int t = 0;
        while(t<branchStack.at(z).size()){
            std::cout<<branchStack.at(z).at(t);

            t++;
        }
        std::cout<<std::endl;
    }
    while(!nodeStack.at(z).empty()){
        unsigned int t = 0;
        while(t<nodeStack.at(z).size()){

            if(nodeStack.at(z).at(t)->left !=NULL){
            nodeStack.at(z+1).push_back(nodeStack.at(z).at(t)->left);
            if(z!=0){
            branchStack.at(z).push_back('/');
        }
            //std::cout<<nodeStack.at(z).at(t)->left->info<<" ";
        }else{
        for(int q = 0; q<6; q++)
            branchStack.at(z).push_back(' ');

    }
            if(nodeStack.at(z).at(t)->right != NULL){
            nodeStack.at(z+1).push_back(nodeStack.at(z).at(t)->right);
            if(z != 0){
            branchStack.at(z).push_back('\\');
        }
            //std::cout<<nodeStack.at(z).at(t)->right->info<<" ";
        }else{
        for(int q = 0; q<6; q++)
            branchStack.at(z).push_back(' ');

    }

            t++;
        }
        //std::cout<<std::endl;
        int q=0;
        if(z!=0){
            for(int space = 0; space<numspaces; space++)
                std::cout<<" ";

        while(q<branchStack.at(z).size()){

            std::cout<<branchStack.at(z).at(q);
            for(int g=0; g<3; g++){
                    std::cout<<" ";
                }
            q++;
        }
        std::cout<<std::endl;

    }
    for(int space = 0; space<numspaces; space++)
        std::cout<<" ";

    q=0;
    while(q<nodeStack.at(z).size()){


        if(nodeStack.at(z).at(q)->left !=NULL)
            std::cout<<nodeStack.at(z).at(q)->left->info<<" ";

        for(int g=0; g<6; g++){
                std::cout<<" ";
            }

        if(nodeStack.at(z).at(q)->right !=NULL)
            std::cout<<nodeStack.at(z).at(q)->right->info<<" ";

        q++;
    }
    numspaces--;
    std::cout<<std::endl;
        z++;
    }
    return 1;

}


template<class ItemType>
void TreeType<ItemType>::PreOrderPrint(){
    PreOrder(root, preQue);
    bool finished = false;
    while(finished!=true){
        ItemType item = TreeType<ItemType>::GetNextItem(PRE_ORDER, finished);
        std::cout<<item<<" ";
    }
    std::cout<<std::endl;
}

template<class ItemType>
void TreeType<ItemType>::InOrderPrint(){
    InOrder(root, inQue);
    bool finished = false;
    while(finished!=true){
        ItemType item =TreeType<ItemType>::GetNextItem(IN_ORDER, finished);
        std::cout<<item<<" ";
    }
    std::cout<<std::endl;}

template<class ItemType>
void TreeType<ItemType>::PostOrderPrint(){
    PostOrder(root, postQue);
    bool finished = false;
    while(finished!=true){
        ItemType item =TreeType<ItemType>::GetNextItem(POST_ORDER, finished);
        std::cout<<item<<" ";
    }
    std::cout<<std::endl;
}


template <class ItemType>
bool TreeType<ItemType>::IsFull() const
// Returns true if there is no room for another item
//  on the free store; false otherwise.
{
  TreeNode<ItemType>* location;
  try
  {
    location = new TreeNode<ItemType>;
    delete location;
    return false;
  }
  catch(std::bad_alloc exception)
  {
    return true;
  }
}

template <class ItemType>
bool TreeType<ItemType>::IsEmpty() const
// Returns true if the tree is empty; false otherwise.
{
  return root == NULL;
}

template <class ItemType>
int CountNodes(TreeNode<ItemType>* tree);


template <class ItemType>
int TreeType<ItemType>::GetLength() const
// Calls recursive function CountNodes to count the
// nodes in the tree.
{
  return CountNodes(root);
}

template <class ItemType>
int CountNodes(TreeNode<ItemType>* tree)
// Post: returns the number of nodes in the tree.
{
  if (tree == NULL)
    return 0;
  else
    return CountNodes(tree->left) + CountNodes(tree->right) + 1;
}
template <class ItemType>
void Retrieve(TreeNode<ItemType>* tree,
     ItemType& item, bool& found);

     template <class ItemType>

ItemType TreeType<ItemType>::GetItem(ItemType item, bool& found)
// Calls recursive function Retrieve to search the tree for item.
{
  Retrieve(root, item, found);
  return item;
}

template <class ItemType>
void Retrieve(TreeNode<ItemType>* tree,
     ItemType& item, bool& found)
// Recursively searches tree for item.
// Post: If there is an element someItem whose key matches item's,
//       found is true and item is set to a copy of someItem;
//       otherwise found is false and item is unchanged.
{
  if (tree == NULL)
    found = false;                     // item is not found.
  else if (item < tree->info)
    Retrieve(tree->left, item, found); // Search left subtree.
  else if (item > tree->info)
    Retrieve(tree->right, item, found);// Search right subtree.
  else
  {
    item = tree->info;                 // item is found.
    found = true;
   }
}

template <class ItemType>
void Insert(TreeNode<ItemType>*& tree, ItemType item);
template <class ItemType>

void TreeType<ItemType>::PutItem(ItemType item)
// Calls recursive function Insert to insert item into tree.
{
  Insert(root, item);
}

template <class ItemType>
void Insert(TreeNode<ItemType>*& tree, ItemType item)
// Inserts item into tree.
// Post:  item is in tree; search property is maintained.
{
  if (tree == NULL)
  {// Insertion place found.
    tree = new TreeNode<ItemType>;
    tree->right = NULL;
    tree->left = NULL;
    tree->info = item;
  }
  else if (item < tree->info)
    Insert(tree->left, item);    // Insert in left subtree.
  else
    Insert(tree->right, item);   // Insert in right subtree.
}

template <class ItemType>
void DeleteNode(TreeNode<ItemType>*& tree);


template <class ItemType>
void Delete(TreeNode<ItemType>*& tree, ItemType item);



template <class ItemType>
void TreeType<ItemType>::DeleteItem(ItemType item)
// Calls recursive function Delete to delete item from tree.
{
	bool found = false;
	GetItem(item, found);
	if (found)
		Delete(root, item);
	else
	   std::cout << item << "is not in tree\n";
}



template <class ItemType>
void Delete(TreeNode<ItemType>*& tree, ItemType item)
// Deletes item from tree.
// Post:  item is not in tree.
{
  if (item < tree->info)
    Delete(tree->left, item);   // Look in left subtree.
  else if (item > tree->info)
    Delete(tree->right, item);  // Look in right subtree.
  else
    DeleteNode(tree);           // Node found; call DeleteNode.
}


template <class ItemType>
void GetPredecessor(TreeNode<ItemType>* tree, ItemType& data);

template <class ItemType>
void DeleteNode(TreeNode<ItemType>*& tree)
// Deletes the node pointed to by tree.
// Post: The user's data in the node pointed to by tree is no
//       longer in the tree.  If tree is a leaf node or has only
//       non-NULL child pointer the node pointed to by tree is
//       deleted; otherwise, the user's data is replaced by its
//       logical predecessor and the predecessor's node is deleted.
{
  ItemType data;
  TreeNode<ItemType>* tempPtr;

  tempPtr = tree;
  if (tree->left == NULL)
  {
    tree = tree->right;
    delete tempPtr;
  }
  else if (tree->right == NULL)
  {
    tree = tree->left;
    delete tempPtr;
  }
  else
  {
    GetPredecessor(tree->left, data);
    tree->info = data;
    Delete(tree->left, data);  // Delete predecessor node.
  }
}


template <class ItemType>
void GetPredecessor(TreeNode<ItemType>* tree, ItemType& data)
// Sets data to the info member of the right-most node in tree.
{
  while (tree->right != NULL)
    tree = tree->right;
  data = tree->info;
}


template <class ItemType>
void PrintTree(TreeNode<ItemType>* tree)
// Prints info member of items in tree in sorted order on screen.
{
  if (tree != NULL)
  {
    PrintTree(tree->left);   // Print left subtree.
    std::cout << tree->info<<"  ";
    PrintTree(tree->right);  // Print right subtree.
  }
}


template <class ItemType>
void TreeType<ItemType>::Print() const
// Calls recursive function Print to print items in the tree.
{
  PrintTree(root);
}



template <class ItemType>
TreeType<ItemType>::TreeType()
{
  root = NULL;
}

template <class ItemType>
void Destroy(TreeNode<ItemType>*& tree);



template <class ItemType>
TreeType<ItemType>::~TreeType()
// Calls recursive function Destroy to destroy the tree.
{
  Destroy(root);
}

template <class ItemType>
void Destroy(TreeNode<ItemType>*& tree)
// Post: tree is empty; nodes have been deallocated.
{
  if (tree != NULL)
  {
    Destroy(tree->left);
    Destroy(tree->right);
    delete tree;
  }
}



template <class ItemType>
void TreeType<ItemType>::MakeEmpty()
{
  Destroy(root);
  root = NULL;
}

template <class ItemType>
void CopyTree(TreeNode<ItemType>*& copy,
     const TreeNode<ItemType>* originalTree);



template <class ItemType>
TreeType<ItemType>::TreeType(const TreeType& originalTree)
// Calls recursive function CopyTree to copy originalTree
//  into root.
{
  CopyTree(root, originalTree.root);
}



template <class ItemType>
void TreeType<ItemType>::operator=
     (const TreeType& originalTree)
// Calls recursive function CopyTree to copy originalTree
// into root.
{
  {
  if (&originalTree == this)
    return;             // Ignore assigning self to self
  Destroy(root);      // Deallocate existing tree nodes
  CopyTree(root, originalTree.root);
  }

}

template <class ItemType>
void CopyTree(TreeNode<ItemType>*& copy,
     const TreeNode<ItemType>* originalTree)
// Post: copy is the root of a tree that is a duplicate
//       of originalTree.
{
  if (originalTree == NULL)
    copy = NULL;
  else
  {
    copy = new TreeNode<ItemType>;
    copy->info = originalTree->info;
    CopyTree(copy->left, originalTree->left);
    CopyTree(copy->right, originalTree->right);
  }
}


template <class ItemType>
void TreeType<ItemType>::ResetTree(OrderType order)
// Calls function to create a queue of the tree elements in
// the desired order.
{
  switch (order)
  {
  case PRE_ORDER:    preQue.MakeEmpty();
		             PreOrder(root, preQue);
                     break;
  case IN_ORDER:     inQue.MakeEmpty();
					 InOrder(root, inQue);
                     break;
  case POST_ORDER:  postQue.MakeEmpty();
					PostOrder(root, postQue);
                     break;
  }
}



template <class ItemType>
ItemType TreeType<ItemType>::GetNextItem(OrderType order, bool& finished)
// Returns the next item in the desired order.
// Post: For the desired order, item is the next item in the queue.
//       If item is the last one in the queue, finished is true;
//       otherwise finished is false.
{
  finished = false;
  ItemType item;
  switch (order)
  {
    case PRE_ORDER  : preQue.Dequeue(item);
                      if (preQue.IsEmpty())
                        finished = true;
                      break;
    case IN_ORDER   : inQue.Dequeue(item);
                      if (inQue.IsEmpty())
                        finished = true;
                      break;
    case  POST_ORDER: postQue.Dequeue(item);
                      if (postQue.IsEmpty())
                        finished = true;
                      break;
  }
  return item;
}
