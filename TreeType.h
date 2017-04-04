#ifndef TREETYPE_H
#define TREETYPE_H



#include <string>
#include <fstream>
#include <iostream>
#include "QueType.h"
typedef int ItemType;
enum OrderType {PRE_ORDER, IN_ORDER, POST_ORDER};



template<class T>
class TreeType
{

public:
    struct TreeNode
    {
      T info;
      TreeNode* left;
      TreeNode* right;
    };
  TreeType();                     // constructor
 ~TreeType();                    // destructor
  TreeType(const TreeType& originalTree);
  void operator=(const TreeType& originalTree);
  // copy constructor
  void MakeEmpty();
  bool IsEmpty() const;
  bool IsFull() const;
  int GetLength() const;
  T GetItem(T item, bool& found);
  void PutItem(T item);
  void DeleteItem(T item);
  void ResetTree(OrderType order);
  T GetNextItem(OrderType order, bool& finished);
  void Print() const;
private:
  TreeNode* root;
  QueType preQue;
  QueType inQue;
  QueType postQue;
};
#include "TreeType.tpp"

#endif
