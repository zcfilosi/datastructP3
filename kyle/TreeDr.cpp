// Test driver
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>
#include <sstream>

#include "TreeType.cpp"
#include "QueType.cpp"

using namespace std;

template <class ItemType>
TreeType<ItemType> MakeTree(ItemType arr[]);

int main()
{
  ifstream inFile;       // file containing operations
  ofstream outFile;      // file containing output
  string inFileName;     // input file external name
  string outFileName;    // output file external name
  string outputLabel;
  string command;        // operation to be executed

  /*
  // My tests:
  TreeType<int> tree;
  tree.PutItem(15);
  tree.PutItem(6);
  tree.PutItem(4);
  tree.PutItem(10);
  tree.PutItem(20);
  tree.PutItem(16);
  tree.PutItem(17);
  tree.DeleteItem(4);
  cout << "Tree Length: " << tree.GetLength() << endl;
  tree.InOrderPrint();
  cout << endl << "4's Ancestors: ";
  tree.Ancestors(4);
  cout << "Level Order Print:" << endl << endl;
  tree.InOrderPrint();
  tree.LevelOrderPrint();

  TreeType<int> treet = tree.MirrorImage();
  treet.InOrderPrint();
  treet.LevelOrderPrint();
  
  int ar[] = {1, 2, 3, 4, 5, 6, 7};
  TreeType<int> mtree = MakeTree(ar);

  */
  char item;
  string orderItem;
  TreeType<int> tree;
  OrderType order;
  bool found;
  bool finished;
  int numCommands;

  // Prompt for file names, read file names, and prepare files
  cout << "Enter name of input command file; press return." << endl;
  cin  >> inFileName;
  inFile.open(inFileName.c_str());

  cout << "Enter name of output file; press return." << endl;
  cin  >> outFileName;
  outFile.open(outFileName.c_str());

  cout << "Enter name of test run; press return." << endl;
  cin  >> outputLabel;
  outFile << outputLabel << endl;

  inFile >> command;

  numCommands = 0;
  while (command != "Quit")
  { 
    cout << command;
    if (command == "PutItem")
    {
      inFile >> item; 
      tree.PutItem(item);
      outFile << item;
      outFile << " is inserted" << endl;
    }
    else if (command == "DeleteItem")
    {
      inFile >> item;
      tree.DeleteItem(item);
      outFile << item;
      outFile << " is deleted" << endl;
    }
    else if (command == "GetItem")
    {
      inFile >> item;

      item = tree.GetItem(item, found);
      if (found)
        outFile << item << " found in list." << endl;
      else outFile << item  << " not in list."  << endl;  
    } 
    else if (command == "GetLength")  
      outFile << "Number of nodes is " << tree.GetLength() << endl;
    else if (command == "IsEmpty")
      if (tree.IsEmpty())
        outFile << "Tree is empty." << endl;
      else outFile << "Tree is not empty."  << endl;  
  
    else if (command == "PrintTree")
    {
      tree.Print();
      outFile << endl;
    }  
    else if (command == "ResetTree")
    {
      inFile >> orderItem;
      if (orderItem == "PRE_ORDER")
        order = PRE_ORDER;
      else if (orderItem == "IN_ORDER")
        order = IN_ORDER;
      else order = POST_ORDER;    
         
      tree.ResetTree(order);
    }
    else if (command == "GetNextItem")
    {
      inFile >> orderItem;
      if (orderItem == "PRE_ORDER")
        order = PRE_ORDER;
      else if (orderItem == "IN_ORDER")
        order = IN_ORDER;
      else order = POST_ORDER;    
      item = tree.GetNextItem(order,finished);
      outFile << "Next item is: " << item << endl;
      if (finished)
        outFile << orderItem << " traversal is complete." << endl;
    }     
    else if (command == "IsFull")
      if (tree.IsFull())
        outFile << "Tree is full."  << endl;
      else outFile << "Tree is not full." << endl;  
    else if (command == "MakeEmpty")
    {
      tree.MakeEmpty();
      outFile << "Tree has been made empty." << endl;
    }
    else if (command == "MakeTree") {
      string line, phr;
      vector<char> vec;
      int len = 0, temp = 0;
      getline(inFile, line);
      stringstream ss(line);
      while (getline(ss, phr, ' ')) { // to get the length
        sscanf(phr.c_str(), "%d", &temp);
        item = (char) temp;
        vec.push_back(item);
        len++;
      }
      int * arr = new int[len];
      for (unsigned int i = 0; i < vec.size(); i++) {
        arr[i] = vec.at(i);
        cout << arr[i] << endl;
      }
      // MakeTree call
    }
    else if (command == "LevelOrderPrint") {
    
    }
	else cout << " Command not recognized." << endl;
    numCommands++;
    cout <<  " Command is completed."  << endl;
    inFile >> command;
  }
 
  cout << "Testing completed."  << endl;
  inFile.close();
  outFile.close();
  
  return 0;
}

template <class ItemType>
TreeType<ItemType> MakeTree(ItemType arr[]) {
  TreeType<ItemType> tree;
  int len = 0;
  while (arr[len] != 0) {
    len++;
  }
  cout << len << endl;
  return tree;
}