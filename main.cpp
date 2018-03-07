//
//  main.cpp
//  Binary Search Tree
//
//  Created by Tina Tavallaeian on 2017-11-15.
//  Copyright © 2017 Tina Tavallaeian. All rights reserved.
//
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string.h>
#include <iomanip>
#include "DBentry.h"
#include "TreeNode.h"
#include "TreeDB.h"
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    TreeDB mytree;
    int countactive = 0;
    
    cout << "> ";
    string line, command;
    getline(cin, line);
    while (!cin.eof()) {
        stringstream linestream(line);
        //command is retracted from line stream
        linestream >> command;
        //going through each command and applying what is needed
        
        if (command == "insert") {
            string Dname;
            unsigned int DIPaddress;
            string activeornot;
            bool Dactive;
            bool exsists;
            //getting each variable
            linestream >> Dname >> DIPaddress >> activeornot;
            if (mytree.find(Dname) != NULL) cout << "Error: entry already exsists" << endl;
            //just to make sure
            else {//adding the active and not active
                if (activeornot == "active"){
                    Dactive = true;
                    countactive = countactive + 1;
                }
                else
                    Dactive = false;
                
                //first i have to make my DB entry
                DBentry* madeEntry = new DBentry (Dname, DIPaddress , Dactive);
                exsists = mytree.insert(madeEntry); //in this function i add the entry i made
                //to the tree, it returns false if it already exsists and returns true if it doesnt
                if (exsists==false){
                    
                    cout <<"Success"<<endl;}
                else
                    cout << "Error: entry already exsists" << endl;
                
                
            }}
        
        else if (command == "find"){
            string Dname;
            string activeornot = "inactive";
            linestream >> Dname;
            DBentry* foundit;
            foundit = mytree.find(Dname);
            //this function retrurns the address of the DBentry that Dname belongs to and returns NULL if it does not exsist
            if (foundit == NULL)
                cout << "Error: entry does not exsist" << endl;
            else{
                if (foundit->getActive() == 1) //making sure i print active and not the boolean
                    activeornot = "active";
                
                cout << foundit->getName() << " : " << foundit->getIPaddress() << " : "
                << activeornot << endl;
            }
        }
        
        else if (command == "remove"){
            string Dname;
            linestream >> Dname;
            
            if (mytree.getroot() == NULL) //if the tree is empty
                cout << "Error: entry does not exist" << endl;
            else if (mytree.find(Dname) == NULL) //if i didnt find the Dname they entered (Extra caution)
                cout << "Error: entry does not exist" << endl;
            else {
                DBentry* foundit = mytree.find(Dname); //i change my count integer
                if (foundit->getActive() == 1)
                    countactive = countactive  - 1;
                
                bool ididit = mytree.remove(Dname); //this function returns true if it deletes and
                //returns false if it didnt exsist
                if (ididit == true)
                    cout << "Success" << endl;
                if (ididit == false)
                    cout << "Eror: entry does not exist" << endl;
            }
        }
        
        else if (command == "printall"){
            mytree.printTree(mytree.getroot());//this function follows the L>N>R and prints everything
        }
        else if (command == "printprobes") {
            string Dname;
            linestream >> Dname;
            if (mytree.getroot() == NULL)// making sure the tree is not empty
                cout << "Error: entry does not exist" << endl;
            else if (mytree.find(Dname) == NULL) //making sure the Dname exist
                cout << "Error: entry does not exist" << endl;
            
            else{
                int probes = mytree.printProbes(mytree.getroot(), Dname, 0);//this function returns
                //the number of probes, it returns 0 if the entry was not there
                if (probes == 0)
                    cout << "Error: entry does not exist" << endl;
                else
                    cout << probes << endl;}
        }
        else if (command == "removeall"){
            mytree.clear(mytree.getroot());//this function clears the entire tree
            mytree.setroot(NULL);//since i statically declared my tree, i make sure to set it to NULL
            cout << "Success" << endl;
        }
        else if (command == "countactive"){
            cout << countactive << endl; //just prints the countactive integer
        }
        else if (command == "updatestatus"){
            string Dname, Dstatus;
            linestream >> Dname >> Dstatus;
            DBentry* foundit;
            
            foundit = mytree.find(Dname);
            if (foundit == NULL)//making sure the entry they are trying to update exists
                cout << "Error: entry does not exist" << endl;
            else {
                if (Dstatus == "active" && foundit->getActive() == 0)
                    //if they change it from inactive to active, i have to make sure my countactive is aware
                    countactive = countactive + 1; 
                if (Dstatus == "inactive" && foundit->getActive() == 1)
                    countactive = countactive - 1;
                if (Dstatus == "active" ) //setting active and inactive of the DBentry
                    foundit->setActive(1);
                if (Dstatus == "inactive")
                    foundit->setActive(0);
                cout << "Success" <<endl;
            }
            
            
        }
        
        
        linestream.ignore(1000, '\n');
        command = "hehe...nottoday"; //this is to ensure if the user
        //presses enter i dont get invalid command
        cout << "> ";
        getline(cin, line);
        
    }
    return 0;
}
