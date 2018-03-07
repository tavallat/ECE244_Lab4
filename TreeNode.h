#ifndef _TREENODE_H
#define _TREENODE_H

#include "DBentry.h"
using namespace std;

class TreeNode {
private:
    DBentry* entryPtr = NULL;
    TreeNode* left = NULL;
    TreeNode* right = NULL;
    
    
public:
    
    DBentry* search(TreeNode* root, string name);//given root and name, this function returns the DBentry of the one im searching
    
    
    bool insert(DBentry* _entryPtr);//this function inserts the given entryPts inside my BST
    
    TreeNode();//default constructor

    TreeNode(DBentry* _entryPtr); //constructs a TreeNode setting its entryPts to be _entryPtr
    
    // the destructor
    ~TreeNode();
    
    // sets the left child of the TreeNode.
    void setLeft(TreeNode* newLeft);
    
    // sets the right child of the TreeNode
    void setRight(TreeNode* newRight);
    
    // gets the left child of the TreeNode.
    TreeNode* getLeft() const;
    
    // gets the right child of the TreeNode
    TreeNode* getRight() const;
    
    // returns a pointer to the DBentry the TreeNode contains.
    DBentry* getEntry() const;
    
  //  TreeNode* findmax(TreeNode* root); //this finds the maxnode
    
    TreeNode* givemetreenode (TreeNode* root, string name);
    
    //bool deleteleft (TreeNode* root);
    
   // void deleteroot (TreeNode* root);
    
    bool DeleteNodeInBST (TreeNode*& root , string data);//this function deletes the TreeNode 
    
    TreeNode* FindMaxNode (TreeNode* root);//this function finds the max in the BST
    
    
    
};



#endif
