//
//  TreeNode.cpp
//  Binary Search Tree
//
//  Created by Tina Tavallaeian on 2017-11-15.
//  Copyright © 2017 Tina Tavallaeian. All rights reserved.
//

#include "TreeNode.h"
#include "DBentry.h"
#include "string.h"
using namespace std;

TreeNode::TreeNode(DBentry* _entryPtr){
    entryPtr = _entryPtr;
    left = NULL;
    right = NULL;
}

bool TreeNode::insert(DBentry* _entryPtr){
    bool exsists = false;
    if (entryPtr->getName().compare(_entryPtr->getName())==0)
        exsists = true;
    if (exsists == false){
        //if the name is smaller than the root, put it to the left
        if (_entryPtr->getName().compare(entryPtr->getName())<0){
            if (left == NULL)
                left = new TreeNode(_entryPtr);
            else{
                left->insert(_entryPtr);
            }
        }
        //if it doesnt exsist and its not smaller, its larger so it must get inserted into the right side
        else {
            if (right == NULL)
                right = new TreeNode(_entryPtr);
            else{
                right->insert(_entryPtr);
            }
        }}
    return exsists;
}



// the destructor
TreeNode::~TreeNode(){
    if (entryPtr!= NULL){//making sure i dont delete NULL
        delete entryPtr;
        entryPtr = NULL;
        left = NULL;
        right = NULL;}
   }

// sets the left child of the TreeNode.
void TreeNode::setLeft(TreeNode* newLeft){
    left = newLeft;}

// sets the right child of the TreeNode
void TreeNode::setRight(TreeNode* newRight){
    right = newRight;
}

// gets the left child of the TreeNode.
TreeNode* TreeNode::getLeft() const{
    return left;
}

// gets the right child of the TreeNode
TreeNode* TreeNode::getRight() const{
    return right;
}

// returns a pointer to the DBentry the TreeNode contains.
DBentry* TreeNode::getEntry() const{
    return entryPtr;
}

DBentry* TreeNode::search(TreeNode* root, string name){
    if (root == NULL) return NULL;//it doesnt exsist
    if (root->getEntry()->getName()==name) return root->getEntry();//i found it
    else if (root->getEntry()->getName() < name) return search(root->getRight(),name); //if the name is bigger
    else return search(root->getLeft(),name);//the name at this point is in the left side
}


TreeNode* TreeNode::givemetreenode (TreeNode* root, string name){
    if (root == NULL) return NULL;
    if (root->getEntry()->getName()==name) return root;
    else if (root->getEntry()->getName() < name) return givemetreenode(root->getRight(),name);
    else return givemetreenode(root->getLeft(),name);
    
}


TreeNode* TreeNode::FindMaxNode (TreeNode* root){
    
    if (root->getRight() == NULL)
        return root;
    else return FindMaxNode(root->getRight());}


bool TreeNode::DeleteNodeInBST (TreeNode* &root , string data) {\
    bool ididit;
    if (root == NULL) return ididit = false;
    if (root->getEntry()->getName() > data){
        if(left!=NULL)
            return(left->DeleteNodeInBST(left, data));
    }
    if (root->getEntry()->getName() < data)
    {
        if (right!= NULL)
        return (right->DeleteNodeInBST(right, data));}
    //at this point, i have found the one i want to delete YAY
    
    else {
        if (left == NULL && right == NULL) { //if it has no children
            root = NULL;
            delete this;
            ididit = true ;
         
        }
        
        else if (right == NULL && left != NULL){ //if it only has a left child
            root = left;
            left = NULL;
            delete this;
            ididit =  true;

        }
        else if (root->getLeft() == NULL && right != NULL){//if it only has a right child
            root = right;
            right = NULL;
            delete this;
            ididit = true;
        }
        else { // if it has two children
            TreeNode* maxNode = FindMaxNode(root->getLeft());
            DBentry* replaceme = new DBentry (maxNode->getEntry()->getName(), maxNode->getEntry()->getIPaddress(), maxNode->getEntry()->getActive());
            TreeNode* therest = new TreeNode (replaceme); //i copied the max
            left->DeleteNodeInBST(left, maxNode->getEntry()->getName()); //i have deleted my max in the original
            therest->setRight(root->right);
            therest ->setLeft(root->left);
            root = therest;
            //by the end of this, i have set it
            delete this;
            ididit = true;
        }
    }
    return ididit; 
}




