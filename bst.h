// bst.h
// Binary search tree header file for CS 24 final exam

#ifndef BST_H
#define BST_H

#include <iostream>
#include <vector>
using namespace std;

class bst {

 public:
    
    // YOU MAY NOT CHANGE THE GIVEN PUBLIC OR PRIVATE METHODS, BUT YOU CAN ADD HELPER PRIVATE METHODS
    
    // TO DO: Implement a parametrized constructor that constructs a bst from the elements in the given vector v
    // You must insert the element of v into the bst in the order that they appear in the vector
    // Insert the first element in v, then the second, and so on
    bst(vector<int>&v); 
	
    //TO DO: Implement the destructor
    ~bst();
     
    int countLeaves() const { return countLeaves(root); }
    int countParentsWithTwoChildren() const {return countParentsWithTwoChildren(root);};
    int height() const {return height(root);};
    void outputPreOrder(vector<int>& output) const {return outputPreOrder(root, output);};
    void outputInOrder(vector<int>& output) const {return outputInOrder(root, output);};
    bool insert(int key);

    // TO DO: IMPLEMENT THE FOLLOWING PUBLIC AND PRIVATE METHODS:
    
    //deleteSubtree Deletes the subtree in the BST that is rooted at the given key value
    void deleteSubtree(int key); 
    
 private:

    struct bstNode {
	int info;
	bstNode *left, *right, * parent;
    bstNode(int v=0) : info(v), left(nullptr), right(nullptr), parent(nullptr) { }
    };

    bstNode *root;
	
    // TO DO: IMPLEMENT THE FOLLOWING PRIVATE METHODS:
	
    // countLeaves() returns the number of leaf nodes
    int countLeaves(bstNode *n) const;
	
    // countParentsWithTwoChildren() returns the number of parents with two children
    int countParentsWithTwoChildren(bstNode *n) const;
	
    // height() returns the height of the bst. Note height of an empty bst is -1.
    // the height of a one node tree is 0
    int height(bstNode *n) const;
	
    //outputPreOrder() stores the result of a preorder traversal in the vector output
    void outputPreOrder(bstNode *n, vector<int>& output) const;
	
    //outputInOrder() stores the result of an inorder traversal in the vector output
    void outputInOrder(bstNode *n, vector<int>& output) const;

    //METHODS ALREADY IMPLEMENTED
    bstNode* getNodeFor(int value, bstNode* n) const;
    bool insert(int value, bstNode *n);
    
   
    //Add any new helper methods here
    void clear(bstNode* n);

};

#endif
