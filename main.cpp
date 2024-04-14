#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Student.h"
#include "AVLTree.h"

using namespace std;

//insert NAME ID
/*
 * checks if name and id satisfy constraints and prints successful/not successful
 * creates new student object and adds it to the vectors
 * calls insert helper to initially place node, then checks balance factor and balances if needed
 * function done and main done
 * */

//remove ID
/*
 * finds the id in AVLVect then calls remove finder to recursively find the student object
 * if found it calls remove on the student object
 * remove: checks if object called is root and changes root node accordingly
 *         otherwise, it checks if there are no children, one child, or two children and moves pointers
 *         deletes student and id from vectors
 * function done
 * main done
 * */

//search ID
/*
 * loops through student vector and prints name if found
 * function done
 * main done
 * */

//search NAME
/*
 * loops through student vector and prints id if found
 * function done
 * main done
 * */

//printInorder
/*
 * Inorder print has nodes sorted from smallest to largest
 * sorts student vector and loops through printing out values
 * function done
 * main done
 * */

//printPreorder
/*
 * recursively loops from root to nodes, moving down left path first then right
 * function done
 * main done
 * */

//printPostorder
/*
 * recursively loops from root to nodes, moving down right path first then left
 * function done
 * main done
 * */

//printLevelCount
/*
 * recursively loops through right height and left height and returns a count int
 * whichever is higher, add 1 and return for level count
 * function done
 * main done
 * */

//removeInorder N
/*
 * sort student vector, find student at index n
 * call remove function on that student
 * function done
 * main done
 * */

int main(){
    AVLTree avl;
//    avl.insert(55555555, "five");
//    avl.insert(33333333, "three");
//    avl.insert(77777777, "seven");
//    avl.insert(22222222, "two");
//    avl.insert(44444444, "four");
//    avl.insert(66666666, "six");
//    avl.insert(88888888, "eight");
//    avl.insert(11111111, "one");


//    avl.insert(44444444, "four");
//    avl.insert(33333333, "three");
//    avl.insert(88888888, "eight");
//    avl.insert(99999999, "nine");




    //avl.printLevelCount();
//    avl.printInOrder(avl.getRoot());
//    cout<<endl;
    //avl.searchName("onee");
//    avl.removeId(44444444);
//    avl.printInOrder(avl.getRoot());
//    cout<<endl;
    //avl.newRemove(avl.getRoot(),avl.getRoot());
//    avl.removeInOrder(2);
//    avl.printInOrder(avl.getRoot());
    //avl.removeInOrder(0);



//
    int numLines;
    cin>>numLines;
    for(int i=-1; i<numLines; i++){
        //used from the powerpoint on canvas
        string line;
        getline(cin, line);

        istringstream in(line);

        string command;
        in>>command;
        if(command=="insert"){
            string name;
            string id;
            getline(in,name,'"');
            getline(in,name,'"');
            in>>id;

            avl.insert(id, name);
        }
        if(command=="remove"){
            int id;
            in>>id;
            avl.removeId(id);
        }
        if(command=="search"){
             string name;
             in>>name;
             bool isNum = false;
             for(char c: name){
                 if(!isalpha(c) && isdigit(c)){
                     isNum = true;
                 }
             }
             if(isNum){
                 int id = stoi(name);
                 avl.searchID(id);
             }
             else{
                 name.erase(name.begin());
                 name.pop_back();
                 //cout<<name<<endl;
                 avl.searchName(name);
             }
        }
        if(command=="printInorder"){
            avl.printInOrder(avl.getRoot());
            cout<<endl;
        }
        if(command=="printPreorder"){
            avl.printPreOrder(avl.getRoot());
            cout<<endl;
        }
        if(command=="printPostorder"){
            avl.printPostOrder(avl.getRoot());
            cout<<endl;
        }
        if(command=="printLevelCount"){
            avl.printLevelCount();
            cout<<endl;
        }
        if(command=="removeInorder"){
            int n;
            in>>n;
            avl.removeInOrder(n);
        }
    }

    return 0;
}
