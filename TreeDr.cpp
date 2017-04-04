// Test driver
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>

#include "TreeType.h"
using namespace std;

int main()
{

        ifstream inFile; // file containing operations
        ofstream outFile; // file containing output
        string inFileName; // input file external name
        string outFileName; // output file external name
        string outputLabel;
        string command;  // operation to be executed

        int item;
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
                        cout<<" ";
                        cout << item;
                        cout << " is inserted" << endl;
                }
                else if (command == "DeleteItem")
                {
                        inFile >> item;
                        tree.DeleteItem(item);
                        cout<<" ";
                        cout << item;
                        cout << " is deleted" << endl;
                }
                else if (command == "GetItem")
                {
                        inFile >> item;

                        item = tree.GetItem(item, found);
                        if (found)
                                cout << item << " found in list." << endl;
                        else cout << item  << " not in list."  << endl;
                }
                else if (command == "GetLength")
                        cout << "Number of nodes is " << tree.GetLength() << endl;
                else if (command == "IsEmpty")
                        if (tree.IsEmpty())
                                cout  << "Tree is empty." << endl;
                        else cout  << "Tree is not empty."  << endl;

                else if (command == "PrintTree")
                {
                        cout <<endl;
                        tree.Print();

                        cout  << endl;
                }
                else if (command == "LevelOrderPrint")
                {
                        cout <<endl;
                        tree.LevelOrderPrint();

                        cout  << endl;
                }
                else if (command == "InOrderPrint")
                {
                        cout <<endl;
                        tree.InOrderPrint();

                        cout << endl;
                }
                else if (command == "PreOrderPrint")
                {
                        cout <<endl;
                        tree.PreOrderPrint();

                        cout << endl;
                }
                else if (command == "PostOrderPrint")
                {
                        cout<<endl;
                        tree.PostOrderPrint();

                        cout<< endl;
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
                        cout  << "Next item is: " << item << endl;
                        if (finished)
                                cout  << orderItem << " traversal is complete." << endl;
                }
                else if (command == "IsFull")
                        if (tree.IsFull())
                                cout  << "Tree is full."  << endl;
                        else cout  << "Tree is not full." << endl;
                else if (command == "MakeEmpty")
                {
                        tree.MakeEmpty();
                        cout  << "Tree has been made empty." << endl;
                }
                else cout  << " Command not recognized." << endl;
                numCommands++;
                cout <<  " Command is completed."  << endl;
                inFile >> command;
        }

        cout << "Testing completed."  << endl;
        inFile.close();
        outFile.close();
        return 0;
}
