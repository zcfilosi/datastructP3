#include "QueType.h"

template <class T>
bool TreeType<T>::IsFull() const
// Returns true if there is no room for another item
//  on the free store; false otherwise.
{
  TreeType<T>::TreeNode* location;
  try
  {
    location = new TreeNode;
    delete location;
    return false;
  }
  catch(std::bad_alloc exception)
  {
    return true;
  }
}



template <class T>
bool TreeType<T>::IsEmpty() const
// Returns true if the tree is empty; false otherwise.
{
  return root == NULL;
}


int CountNodes(TreeType<T>::TreeNode* tree);



template <class T>
int TreeType<T>::GetLength() const
// Calls recursive function CountNodes to count the
// nodes in the tree.
{
  return CountNodes(root);
}


template<class T>
int CountNodes(TreeType<T>::TreeNode* tree)
// Post: returns the number of nodes in the tree.
{
  if (tree == NULL)
    return 0;

  else
    return CountNodes(tree->left) + CountNodes(tree->right) + 1;
}


template <class T>
void Retrieve(TreeType<T>::TreeNode* tree,
     T& item, bool& found);


template <class T>
T TreeType<T>::GetItem(T item, bool& found)
// Calls recursive function Retrieve to search the tree for item.
{
  Retrieve(root, item, found);
  return item;
}



template <class T>
void Retrieve(TreeType<T>::TreeNode* tree,
     T& item, bool& found)
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


template <class T>
void Insert(TreeType<T>::TreeNode*& tree, T item);



template <class T>
void TreeType<T>::PutItem(T item)
// Calls recursive function Insert to insert item into tree.
{
  Insert(root, item);
}



template <class T>
void Insert(TreeType<T>::TreeNode*& tree, T item)
// Inserts item into tree.
// Post:  item is in tree; search property is maintained.
{
  if (tree == NULL)
  {// Insertion place found.
    tree = new TreeType<T>::TreeNode;
    tree->right = NULL;
    tree->left = NULL;
    tree->info = item;
  }
  else if (item < tree->info)
    Insert(tree->left, item);    // Insert in left subtree.
  else
    Insert(tree->right, item);   // Insert in right subtree.
}


template <class T>
void DeleteNode(TreeType<T>::TreeNode*& tree);



template <class T>
void Delete(TreeType<T>::TreeNode*& tree, T item);



template <class T>
void TreeType<T>::DeleteItem(T item)
// Calls recursive function Delete to delete item from tree.
{
	bool found = false;
	GetItem(item, found);
	if (found)
		Delete(root, item);
	else
		cout << item << "is not in tree\n";
}



template <class T>
void Delete(TreeType<T>::TreeNode*& tree, T item)
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



template <class T>
void GetPredecessor(TreeType<T>::TreeNode* tree, T& data);



template <class T>
void DeleteNode(TreeType<T>::TreeNode*& tree)
// Deletes the node pointed to by tree.
// Post: The user's data in the node pointed to by tree is no
//       longer in the tree.  If tree is a leaf node or has only
//       non-NULL child pointer the node pointed to by tree is
//       deleted; otherwise, the user's data is replaced by its
//       logical predecessor and the predecessor's node is deleted.
{
  T data;
  TreeType<T>::TreeNode* tempPtr;

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



template <class T>
void GetPredecessor(TreeType<T>::TreeNode* tree, T& data)
// Sets data to the info member of the right-most node in tree.
{
  while (tree->right != NULL)
    tree = tree->right;
  data = tree->info;
}



template <class T>
void PrintTree(TreeType<T>::TreeNode* tree)
// Prints info member of items in tree in sorted order on screen.
{
  if (tree != NULL)
  {
    PrintTree(tree->left);   // Print left subtree.
    cout << tree->info<<"  ";
    PrintTree(tree->right);  // Print right subtree.
  }
}




template <class T>
void TreeType<T>::Print() const
// Calls recursive function Print to print items in the tree.
{
  PrintTree(root);
}



template <class T>
TreeType<T>::TreeType()
{
  root = NULL;
}



template <class T>
void Destroy(TreeType<T>::TreeNode*& tree);

template <class T>
TreeType::~TreeType()
// Calls recursive function Destroy to destroy the tree.
{
  Destroy(root);
}



template <class T>
void Destroy(TreeType<T>::TreeNode*& tree)
// Post: tree is empty; nodes have been deallocated.
{
  if (tree != NULL)
  {
    Destroy(tree->left);
    Destroy(tree->right);
    delete tree;
  }
}




template <class T>
void TreeType<T>::MakeEmpty()
{
  Destroy(root);
  root = NULL;
}



/*

template <class T>
void CopyTree(TreeNode*& copy,
     const TreeNode* originalTree);

*/

template <class T>
TreeType<T>::TreeType(const TreeType<T>::TreeType& originalTree)
// Calls recursive function CopyTree to copy originalTree
//  into root.
{
  CopyTree(root, originalTree.root);
}




template <class T>
void TreeType<T>::operator=
     (const TreeType<T>::TreeType& originalTree)
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




template <class T>
void CopyTree(TreeType<T>::TreeNode*& copy,
     const TreeType<T>::TreeNode* originalTree)
// Post: copy is the root of a tree that is a duplicate
//       of originalTree.
{
  if (originalTree == NULL)
    copy = NULL;
  else
  {
    copy = new TreeNode;
    copy->info = originalTree->info;
    CopyTree(copy->left, originalTree->left);
    CopyTree(copy->right, originalTree->right);
  }
}
// Function prototypes for auxiliary functions.





template <class T>
void PreOrder(TreeType<T>::TreeNode*, QueType&);
// Enqueues tree items in preorder.






template <class T>
void InOrder(TreeType<T>::TreeNode*, QueType&);
// Enqueues tree items in inorder.






template <class T>
void PostOrder(TreeType<T>::TreeNode*, QueType&);
// Enqueues tree items in postorder.






template <class T>
void TreeType::ResetTree(OrderType order)
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




template <class T>
void PreOrder(TreeType<T>::TreeNode* tree,
     QueType& preQue)
// Post: preQue contains the tree items in preorder.
{
  if (tree != NULL)
  {
    preQue.Enqueue(tree->info);
    PreOrder(tree->left, preQue);
    PreOrder(tree->right, preQue);
  }
}





template <class T>
void InOrder(TreeType<T>::TreeNode* tree,
     QueType& inQue)
// Post: inQue contains the tree items in inorder.
{
  if (tree != NULL)
  {
    InOrder(tree->left, inQue);
    inQue.Enqueue(tree->info);
    InOrder(tree->right, inQue);
  }
}






void PostOrder(TreeType<T>::TreeNode* tree,
     QueType& postQue)
// Post: postQue contains the tree items in postorder.
{
  if (tree != NULL)
  {
    PostOrder(tree->left, postQue);
    PostOrder(tree->right, postQue);
    postQue.Enqueue(tree->info);
  }
}






template <class T>
T TreeType::GetNextItem(OrderType order, bool& finished)
// Returns the next item in the desired order.
// Post: For the desired order, item is the next item in the queue.
//       If item is the last one in the queue, finished is true;
//       otherwise finished is false.
{
  finished = false;
  T item;
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
