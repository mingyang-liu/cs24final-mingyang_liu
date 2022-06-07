// testbst.cpp
// Tests intbst.cpp for CS 24 lab

#include "bst.h"

#include <iostream>
using namespace std;

int getTest();

// creates two trees (one of which is empty),
// and does some simple tests of tree methods
int main() {
    vector<int> v {64, 128, 8, 512, 256, 32, 16, 4};

    bst bst1 {v};
  
    // let user choose one or all tests
    bool all = true;
    int testnum = getTest();
    if (testnum)
        all = false;
    if (all || testnum == 1){
        vector<int> output;
        cout <<"  pre-order traversal: ";
        bst1.outputPreOrder(output);
        for(auto i: output){
            cout<<i<<" ";
        }
        cout<<endl;
        cout << endl;
    }
    if (all || testnum == 2){
        cout<<" height of the tree: "<<bst1.height()<<endl;
    }   
    if (all || testnum == 3) {
        cout << " count leaves: " << bst1.countLeaves() << endl;
    }
    if(all || testnum == 4) {
        cout << " count parents with two childres: "<<bst1.countParentsWithTwoChildren()<<endl;
    }
    if(all || testnum == 5){
        cout<<" remove subtree rooted at 512"<<endl;
        vector<int> result;
        bst1.deleteSubtree(512);
        cout<<" print preorder after remove"<<endl;
        bst1.outputPreOrder(result);
        for(auto i: result){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    if(all || testnum == 6){
        cout<<"Leaves: ";
        cout<<bst1.countLeaves()<<endl;
    }
    if(all || testnum == 7){
        cout<<"Parent 2 Children: ";
        cout<<bst1.countParentsWithTwoChildren()<<endl;
    }
    if(all || testnum == 8){
        vector<int> result;
        cout<<"In order:";
        bst1.outputInOrder(result);
        for(auto i: result){
            cout<<i<<" ";
        }
        cout<<endl;
    }
	
    return 0;
}

int getTest() {
    cout << "Choice of tests:\n"
	 << "  0. all tests\n"
	 << "  1. just outputPreOrder\n"
	 << "  2. just height\n"
	 << "  3. just countLeaves\n"
	 << "  4. just countParentsWithTwoChildren\n"
	 << "  5. just deleteSubtree\n"<<endl;
	 
    do {
        int choice;
        cout << "Enter choice: ";
        cin >> choice;
        if (choice >=0 && choice <= 7)
            return choice;
        cout << "0, 1, 2, 3, 4, or 5 only!\n";
    } while (true);
}
