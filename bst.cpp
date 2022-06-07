// bst.cpp
// CS24 Final Exam
// Implements class bst
// Mingyang Liu, June 6th, 2022

#include "bst.h"

#include <iostream>
using std::cout;



bst::bst(vector<int>&v){
    for(auto item:v){
        insert(item);
    }
}

bst::~bst(){
    clear(root);
}

void bst::clear(bstNode* n){
    if(!n){
        return;
    }
    clear(n->left);
    clear(n->right);
    delete(n);
}


bool bst::insert(int value) {

    if (root == nullptr){
        root = new bstNode(value);
        return true;
    }else{
        return insert(value, root);
    }

    return false; 

}


// recursive helper for insert (assumes n is never 0)

bool bst::insert(int value, bstNode *n) {

    if(value < n->info){
        if(n->left == nullptr){
            n->left = new bstNode(value);
            n->left->parent = n;
            return true;
        } else {
            return insert(value, n->left);
        }
    } else if (value > n->info) {
        if (n->right == nullptr){
            n->right = new bstNode(value);
            n->right->parent = n;
            return true;
        } else {
            return insert(value, n->right);
        }
    } else {
        return false;
    }

}


void bst::deleteSubtree(int key){
    bstNode* n = getNodeFor(key, root);
    clear(n->left);
    clear(n->right);
}
int bst::countLeaves(bstNode *n) const{
    if(!n){
        return 0;
    }
    if(n->left==nullptr&&n->right==nullptr){
        return 1;
    }
    else{
        return countLeaves(n->left)+countLeaves(n->right);
    }
}
int bst::countParentsWithTwoChildren(bstNode *n) const{
    if(!n){
        return 0;
    }
    if(n->left!=nullptr&&n->right!=nullptr){
        return countParentsWithTwoChildren(n->left)+1+countParentsWithTwoChildren(n->right);
    }else{
        return countParentsWithTwoChildren(n->left)+countParentsWithTwoChildren(n->right);
    }
}
int bst::height(bstNode *n) const{
    if(!n){
        return 0;
    }
    if(n->left||n->right){
        return max(height(n->left)+1,height(n->right)+1);
    }else{
        return 0;
    }
}
void bst::outputPreOrder(bstNode *n, vector<int>& output) const{
    if(!n){
        return;
    }
    output.push_back(n->info);
    outputPreOrder(n->left,output);
    outputPreOrder(n->right,output);
}
void bst::outputInOrder(bstNode *n, vector<int>& output) const{
    if(!n){
        return;
    }
    outputPreOrder(n->left,output);
    output.push_back(n->info);
    outputPreOrder(n->right,output);
}

typename bst::bstNode* bst::getNodeFor(int value, bstNode* n) const{
    while (n != nullptr) {
        if (value == n->info) {
            return n; 
        }
        else if (value < n->info) {
            return getNodeFor(value, n->left);
        } else {
            return getNodeFor(value, n->right);
        }
    }
    return nullptr; // Node doesn't exist in tree
}
