//
//  TreeDB.cpp
//  Binary Search Tree
//
//  Created by Tina Tavallaeian on 2017-11-15.
//  Copyright © 2017 Tina Tavallaeian. All rights reserved.
//

#include "TreeDB.h"
#include "TreeNode.h"
#include "DBentry.h"
#include <string.h>
#include <iostream>



using namespace std;

TreeDB::TreeDB(){
    root = NULL;
}

void TreeDB::printTree(TreeNode* root){
    //this function goes through in the L>N>R order and prints every single node in the BST
    if (root == NULL)
        return; 
    if (root!= NULL){
        string activeornot = "active";
        printTree(root->getLeft());//reccursively go left
        cout << root->getEntry()->getName() << " : " << root->getEntry()->getIPaddress() << " : " ;
        if (root->getEntry()->getActive() == 0)
            activeornot = "inactive"; //making sure that we dont print 0 and 1 but the actual word
        cout << activeornot << endl;
        printTree(root->getRight());//reccurssively go right
        
    }
}

TreeNode* TreeDB::getroot(){//this function returns the tree's root
    return root;
}


bool TreeDB::insert(DBentry* newEntry){
    // inserts the entry pointed to by newEntry into the database.
    // If an entry with the same key as newEntry's exists
    // in the database, it returns false. Otherwise, it returns true.
    bool italreadyexsists = false;
    if (root == NULL){
        root = new TreeNode(newEntry);
        probesCount = probesCount +1 ;
        return false;}
    else{
        italreadyexsists = root-> insert(newEntry);
        if (italreadyexsists == false)
            probesCount = probesCount +1;
        return italreadyexsists;}
    
}



void TreeDB::setroot(TreeNode* node){// this function sets the root
    root = node;
}

// the destructor, deletes all the entries in the database.
TreeDB::~TreeDB(){
    delete root;
    root  = NULL;//good practice
}



// searches the database for an entry with a key equal to name.
// If the entry is found, a pointer to it is returned.
// If the entry is not found, the NULL pointer is returned.
// Also sets probesCount
DBentry* TreeDB::find(string name){
    return root->search(root, name);
}




bool TreeDB::remove(string name){
    // deletes the entry with the specified name (key)  from the database.
    // If the entry was indeed in the database, it returns true.
    // Returns false otherwis
    if (root==NULL)
        return(false);
    return root->DeleteNodeInBST(root, name);
}

// deletes all the entries in the database.
void TreeDB::clear(TreeNode* root){
    if (root!= NULL)
        delete root;
    
}

// prints the number of probes stored in probesCount
int TreeDB::printProbes(TreeNode* root, string name, int count) {
    int counter  = count;
    // DBentry* pointer = root->search(root, name);
    if (root == NULL) counter = 0;
    
    else {
        if (root->getEntry()->getName() == name)
            counter = 1;
        else if (root->getEntry()->getName() < name)
            counter = 1 + printProbes(root->getRight(), name, counter);
        
        else if (root->getEntry()->getName() > name)
            counter = 1 + printProbes(root->getLeft(),name, counter);
    }
    return counter;
}

// computes and prints out the total number of active entries
// in the database (i.e. entries with active==true).
void TreeDB::countActive () const{
}
