//
// Created by Sophie Shah on 2/7/2024.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
//#include "Student.cpp"
#include "AVLTree.h"

using namespace std;

//constructor for avl tree
AVLTree::AVLTree() {
    root = nullptr;
    treeHeight = 0;
}

AVLTree::~AVLTree(){
    queue<Student*> q;
    q.push(root);

    while(!q.empty()){
        Student* curr = q.front();
        if(curr->left!=nullptr){
            q.push(curr->left);
        }
        if(curr->right!=nullptr){
            q.push(curr->right);
        }
        q.pop();
        delete curr;
    }
    treeHeight = 0;
    AVLStudentVect.clear();
    AVLVect.clear();
}

//determines if input is valid and prints successful/unsuccessful
// calls insert helper and adds id and student object to vectors
void AVLTree::insert(string ID, string name){
    //add to vector, print successful/unsuccessful
    bool isValid = insertValid(ID, name);
    if(!isValid){
        cout<<"unsuccessful"<<endl;
    }
    else{
        int id = stoi(ID);
        cout<<"successful"<<endl;
        Student* s = new Student(id,name);
        AVLVect.push_back(id);

        if(root==nullptr){
            root = insertHelper(s, root);
            //cout<<"root"<<endl;
        }
        else{
            insertHelper(s, root);
        }

        AVLStudentVect.push_back(s);
    }
}

//recursivly goes from root to leaf to determine where to place new node
//calls balance helper to get balance factors of parent and child nodes
//calls the respoective rotation function if needed
Student* AVLTree::insertHelper(Student* s, Student* curr_){
    //recursive code used from insertIntoBST from Prog Quiz 4

    if(curr_==nullptr){
        curr_ = s;
        s->height = 0;
        s->parent = nullptr;
        //cout<<"root "<<s->id<<endl;
        //cout<<"root"<<endl;
        return curr_;
    }
    //cout<<s->id<<" " <<curr_->id<<endl;
    if(s->id > curr_->id){
        //cout<<"inserting right"<<endl;
        curr_->height++;
        curr_->parent = curr_;
        //cout<< "height "<<s->height<<" parent "<<s->parent->id<<endl;
        curr_->right = insertHelper(s, curr_->right);
    }
    else{
        //cout<<"inserting left"<<endl;
        curr_->height++;
        curr_->parent = curr_;
        //cout<< "height "<<curr_->height<<" parent "<<curr_->parent->id<<endl;
        curr_->left = insertHelper(s, curr_->left);
    }

    //int parentBalance = balanceHelper(curr_);
    if(balanceHelper(curr_)==-2 && balanceHelper(curr_->right)==-1){
        //cout<<"performing left rotation on "<<curr_->name<<endl;
        curr_ = leftRotation(curr_);
    }
    else if(balanceHelper(curr_)==2 && balanceHelper(curr_->left)==1){
        //cout<<"performing right rotation on "<<curr_->name<<endl;
        curr_ = rightRotation(curr_);
    }
    else if(balanceHelper(curr_)==2 && balanceHelper(curr_->left)==-1){
        //cout<<"performing left right rotation on "<<curr_->name<<endl;
        curr_ = leftRightRotation(curr_);
//        if(curr_ ==root){
//            root = curr_->left->right;
//        }
//        curr_->left = leftRotation(curr_->left);
        curr_ = rightRotation(curr_);
    }
    else if(balanceHelper(curr_)==-2 && balanceHelper(curr_->right)==1){
        //cout<<"performing right left rotation on "<<curr_->name<<endl;
        curr_ = rightLeftRotation(curr_);
//        if(curr_ ==root){
//            root = curr_->right->left;
//        }
//        curr_->right = leftRotation(curr_->right);
        curr_ = leftRotation(curr_);
    }

    //idea taken from the chart on the powerpoint:

    //parent-2 and child (parent->right)-1 ---> left rotation
    //parent +2 and child(parent->left) +1 ---> right rotation
    // parent +2 and child(parent->left)-1 ---> left right rotation
    //parent -2 and child(parent->right)+1 ---> right left rotation

    return curr_;
}

//check length of id, is alpha of name, check vector if id is repeated
// passes return value into insert
bool AVLTree::insertValid(string ID, string name){

    bool idGood = false;
    bool isUnique = true;
    bool nameGood = true;
    int countId = 0;
    int id = stoi(ID);

    for(int j=0; j<AVLVect.size();j++){
        if(AVLVect[j] == id){
            isUnique = false;
        }
    }

//    while(id!=0){
//        id /= 10;
//        countId++;
//    }
//    if(countId==8){
//        idGood = true;
//    }

    if(ID.length()==8){
        idGood = true;
    }


    for(int i=0; i<name.length();i++){
        if(!isalpha(name[i]) && !isspace(name[i])){
            nameGood = false;
        }
    }
   //cout<<"id "<<idGood<<" name "<<nameGood<<" unique "<<isUnique<<endl;
    if(idGood && nameGood && isUnique){
        return true;
    }
    else{
        return false;
    }

}

//recursively goes down left subtree and keeps track of the level count
int AVLTree::getLeftHeight(Student* curr) {
    //cout<<"at left"<<endl;
    int count = 0;
    while(curr->left!=nullptr){
        curr = curr->left;
        count++;
        //cout<<count<<endl;
    }
    //cout<<"left "<<count<<endl;
    return count;
}


//recursively goes down right subtree and keeps track of the level count
int AVLTree::getRightHeight(Student* curr) {
    //cout<<"at right"<<endl;
    int count = 0;
    while(curr->right!=nullptr){
        curr = curr->right;
        count++;
        //cout<<"right "<<count<<endl;
    }
    //cout<<"right "<<count<<endl;
    return count;
}

//recursivly goes down left and right subtree and keeps track of height
// returns the larger height+1
int AVLTree::totalBalance(Student *curr) {
    int left = 0;
    int right = 0;
    if(curr==nullptr){
        return 0;
    }
    else{
        left = totalBalance(curr->left);
        right = totalBalance((curr->right));
        if(left>=right){
            left++;
            //cout<<"left "<<left<<endl;
            return left;
        }
        //cout<<"right "<<right<<endl;
        right++;
        return right;

    }

//    int left  = getLeftHeight(curr);
//    int right  = getRightHeight(curr);
//
//    if(left>right){
//        left+= 1;
//    }
//    else{
//        right+=1;
//    }
//    cout<<"left "<<left<<" and right "<<right<<endl;
//    cout<<"total "<<left-right<<endl;
//    return (left-right);
}

//returns left balance - right balance to find the balance factor of the tree/subtree
int AVLTree::balanceHelper(Student *curr) {
    //cout<<"subtracted:"<<endl;
    //cout<<totalBalance(curr->left) - totalBalance(curr->right)<<endl;
    return totalBalance(curr->left) - totalBalance(curr->right);
}

//moves specified pointers to perform a left rotation on the current node
Student* AVLTree::leftRotation(Student *curr) {
    /*
     * assuming the order is 1, 2, 3
     *
     * Before:
     *  null<- 1 ->2
     *  null<- 2 ->3
     *  null<- 3 ->null
     *
     * After:
     *  null<- 1 ->null
     *  1<- 2 -> 3
     *  null<- 3 ->null
     *
     *  move 2's left pointer to 1, move 1's right pointer to null
     *  if current node is the root then make its right node the root;
     * */
    if(curr==root){
        root = curr->right;
    }
    Student* left = curr->right->left;
    Student* n = curr->right; //n = 2
    curr->right->left = curr;
    curr->right = left;
    return n;
}

//moves specified pointers to perform a right rotation on the current node
Student* AVLTree::rightRotation(Student *curr) {
    /*
     * assuming the order is 3, 2, 1
     *
     * Before:
     *  null<- 1 ->null
     *  1<- 2 ->null
     *  2<- 3 ->null
     *
     * After:
     *  null<- 1 ->null
     *  1<- 2 -> 3
     *  null<- 3 ->null
     *
     *  move 2's right pointer to 3, move 3's left pointer to null
     *  if current node is the root then make its left node the root;
     * */

    if(curr==root){
        root = curr->left;
    }
    Student* right = curr->left->right;
    Student* n = curr->left; //n = 2
    curr->left->right = curr;
    curr->left = right;
    return n;
}

//moves specified pointers to perform a left-right rotation on the current node
Student* AVLTree::leftRightRotation(Student *curr) {
    /*
     * assuming the order is 3, 1, 2
     *
     * Before:
     *  1<- 3 ->null
     *  null<- 2 ->null
     *  null<- 1 ->2
     *
     *
     * After:
     *  2<- 3 ->null
     *  1<- 2 ->null
     *  null<- 1 ->null
     *
     *  move 3's left pointer to 2, move 2's left pointer to 1, move 1's right pointer to null
     * */
    curr->height++;
    curr->left->right->height-=2;
    Student* n = curr->left; //n = 1
    curr->left = curr->left->right; //3's left = 2
    curr->left->left = n; //2's left = 1
    n->right = nullptr; //1's right = null
    return curr;
}

//moves specified pointers to perform a right-left rotation on the current node
Student* AVLTree::rightLeftRotation(Student *curr) {
    /*
     * assuming the order is 1, 3, 2
     *
     * Before:
     *  null<- 1 ->3
     *  null<- 2 ->null
     *  2<- 3 ->null
     *
     * After:
     *  null<- 1 ->2
     *  null<- 2 ->3
     *  null<- 3 ->null
     *
     *  move 2's right pointer to 3, move 1's right pointer to 2, move 3's left pointer to null
     *  if current node is the root then make its right node the root;
     * */

    Student* n = curr->right; //n = 3
    curr->right = curr->right->left; //1's right = 2
    curr->right->right = n; //2's right = 3
    n->left = nullptr; //3's left = null

    return curr;
}

//calls left and right height to find the maximum level of each tree path
//returns the highest level count +1
void AVLTree::printLevelCount() {
//    int left  = getLeftHeight(root);
//    int right  = getRightHeight(root);
//
//    if(left>right){
//        cout<<left+1<<endl;
//    }
//    else{
//        cout<<right+1<<endl;
//    }
    cout<< totalBalance(root);
}

//returns the root of the tree for easy access
Student* AVLTree::getRoot() {
    return root;
}

//recursively goes through the tree going down the left subtree first and then the right
Student* AVLTree::printPreOrder(Student* curr){
    if(curr==nullptr){
        cout<<curr->name;
        return curr;
    }
    cout<<curr->name;
    if(curr->left !=nullptr){
        cout<<", ";
        printPreOrder(curr->left);

    }
    if(curr->right != nullptr) {
        cout<<", ";
        printPreOrder(curr->right);

    }

    return curr;
}

//recursively goes through the tree going down the right subtree first and then the left
Student* AVLTree::printPostOrder(Student* curr){
    if(curr==nullptr){
        cout<<curr->name;
        return curr;
    }

    if(curr->left !=nullptr){
        printPostOrder(curr->left);
        cout<<", ";
    }

    if(curr->right != nullptr) {
        printPostOrder(curr->right);
        cout<<", ";
    }

    cout<<curr->name;
    return curr;
}

//sorts and then traverses through vector of ids to print inorder
//inorder print has all nodes outputted in a sorted way from left to right
Student* AVLTree::printInOrder(Student* curr){
//    sort(AVLVect.begin(),AVLVect.end());
//    for(int i=0; i<AVLStudentVect.size(); i++){
//        cout<<AVLStudentVect[i]->name;
//        if(AVLStudentVect[i]!=AVLStudentVect[AVLStudentVect.size()-1]){
//            cout<<", ";
//        }
//    }
//    cout<<endl;
//    return curr;

    sort(AVLVect.begin(),AVLVect.end());
    int end = AVLVect[AVLVect.size()-1];
    if(curr==nullptr){
        cout<<curr->name;
        if(curr->id!=end){
            cout<<", ";
        }
        return curr;
    }

    if(curr->left!=nullptr) {
        printInOrder(curr->left);
    }
    cout<<curr->name;
    if(curr->id!=end){
        cout<<", ";
    }
    if(curr->right!=nullptr) {

        printInOrder(curr->right);
    }

    return curr;

}

//traverses through student vector to find the specified id and print the name of the found object
void AVLTree::searchID(int findId) {
    bool found=false;
    for(int i=0; i<AVLStudentVect.size(); i++){
        if(AVLStudentVect[i]->id == findId){
            cout<<AVLStudentVect[i]->name<<endl;
            found = true;
        }
    }
    if(!found){
        cout<<"unsuccessful"<<endl;
    }
}

//does the same process as SearchId but returns the student vector found instead of printing it
Student* AVLTree::getSearchId(int findId) {
    bool found=false;
    for(int i=0; i<AVLStudentVect.size(); i++){
        if(AVLStudentVect[i]->id == findId){
            //cout<<AVLStudentVect[i]->name<<endl;
            found = true;
            cout<<"successful"<<endl;
            return AVLStudentVect[i];
        }
    }
    if(!found){
        cout<<"unsuccessful"<<endl;
    }
    return nullptr;
}

Student* AVLTree::getParentId(Student *curr) {
    for(int i=0; i<AVLStudentVect.size(); i++){
        if(AVLStudentVect[i]->left==curr || AVLStudentVect[i]->right==curr){
            return AVLStudentVect[i];
        }
    }
    return nullptr;
}

//traverses through student vector to find the specified name and print the id of the found object
void AVLTree::searchName(string findName) {
    bool found=false;
    int num = 0;
    vector<int> vect;

    for(int i=0; i<AVLStudentVect.size(); i++){
        if(AVLStudentVect[i]->name == findName){
            vect.push_back(AVLStudentVect[i]->id);
            found = true;
        }
    }
    if(!found){
        cout<<"unsuccessful"<<endl;
    }

    sort(vect.begin(),vect.end());
    for(int j=0; j<vect.size(); j++){
        cout<<vect[j]<<endl;
    }

//    if(curr==nullptr){
//        if(curr->name==findName){
//            cout<<curr->id;
//            cout<<endl;
//        }
//        return curr;
//    }
//    if(curr->name==findName){
//        cout<<curr->id;
//        cout<<endl;
//    }
//    if(curr->left !=nullptr){
//        searchName(findName,curr->left);
//
//    }
//    if(curr->right != nullptr) {
//        searchName(findName,curr->right);
//
//    }
//
//    return curr;
}

//checks if id exists in the tree by traversing the student vector
//if found then it calls remove finder
//prints out successful/unsuccessful
void AVLTree::removeId(int removedId) {
    bool found=false;
    for(int i=0; i<AVLStudentVect.size(); i++){
        if(AVLStudentVect[i]->id == removedId){
            found = true;
        }
    }
    if(!found){
        cout<<"unsuccessful"<<endl;
    }
    else{
        cout<<"successful"<<endl;
        removeIdFinder(root, removedId);
    }
}

//recursively loops through tree to find the specified id
//if found then it calls newRemove function on the id and its parent
Student* AVLTree::removeIdFinder(Student *curr, int removedId) {
    if(curr==nullptr){
        //remove func
        return curr;
    }

    if(curr->left != nullptr && curr->left->id == removedId){
        //cout<<"called remove helper helper on element "<<curr->name<<endl;
        //remove(curr, true);
        newRemove(curr->left, curr);
        return curr;
    }
    else if(curr->right != nullptr && curr->right->id == removedId){
        //cout<<"called remove helper helper on element "<<curr->name<<endl;
        newRemove(curr->right, curr);
        return curr;
    }
    else if(curr->id==removedId){
        //cout<<"removing root"<<endl;
        newRemove(root, root);
    }
    if(curr->right !=nullptr){
        removeIdFinder(curr->right, removedId);
    }
    if(curr->left != nullptr) {
        removeIdFinder(curr->left, removedId);
    }

    return curr;
}

//in order = sorted
//can find the node at n in AVLVect and return the int
//search id function to return student thats found
//function to return parent of the removed student
//remove that student
void AVLTree::removeInOrder(int n) {

    sort(AVLVect.begin(),AVLVect.end());
    Student* removed = getSearchId(AVLVect[n]);
    Student* parent;
    if(removed!=root){
        parent = getParentId(removed);
    }
    else{
        parent = root;
    }
    newRemove(removed, parent);
//    if(n==0){
//        Student* curr = root;
//        if(curr->left!=nullptr){
//            remove(curr,true);
//        }
//        else if(curr->right!=nullptr){
//            remove(curr, false);
//        }
//    }
//    else{
//        Student* curr = getSearchId(AVLVect[n]);
//        cout<<"curr "<<curr->name<<endl;
//
//
//
//        if(curr!=nullptr){
//            if(curr->left!=nullptr){
//                remove(curr,true);
//            }
//            else if(curr->right!=nullptr){
//                remove(curr, false);
//            }
//        }
//    }

    //remove(curr);

    //removeInOrderFinder(root,n,0);
}

//Student* AVLTree::removeInOrderFinder(Student *curr, int n, int currInt) {




//    if(curr==nullptr){
//        //remove func
//        return curr;
//    }
//
//    if(curr->left!=nullptr) {
//        removeInOrderFinder(curr->left,n,currInt);
//    }
//
//    currInt++;
//    if(currInt==n){
//        cout<<"called remove on element "<<curr->name<<endl;
//        //remove func
//        return curr;
//    }
//
//    if(curr->right!=nullptr) {
//        removeInOrderFinder(curr->right,n,currInt);
//    }
//
//    return curr;
//}

//checks if root is being removed and changes the root pointer
//removes id and student object from vectors
//checks if removed node has one, two, or no children and changes pointers accordingly
void AVLTree::newRemove(Student *removed, Student *parent) {

    //cout<<"removing "<<removed->name<<" whose parent is "<<parent->name<<endl;
//    UNCOMMENT TO REMOVE STUFF FROM VECTOR
    removeStudentVect(removed);
    removeIntVect(removed->id);
    //cout<<"removed from vects"<<endl;


    if(removed == root){
        //cout<<"removing root"<<endl;
        //MAKE NEW PARENT = ROOT
        if(removed->left ==nullptr && removed->right == nullptr) {
            //cout << "no children" << endl;
            root = nullptr;
            delete removed;
        }
        else if(removed->left==nullptr || removed->right == nullptr){
            //cout<<"one child"<<endl;
            if(removed->left!=nullptr){
                root = removed->left;
                removed->left = nullptr;
                delete removed;
            }
            else if(removed->right!=nullptr){
                root = removed->right;
                removed->right = nullptr;
                delete removed;
            }
        }
        else{
            //cout<<"two children"<<endl;
            Student* newChild = getNextInOrder(root);
            root = newChild;
            //cout<<"new root is "<<root->name<<endl;
            newChild->left = removed->left;
            if(removed->right==newChild){
                newChild->right = removed->right->right;
            }
            else{
                newChild->right = removed->right;
            }
            removed->right = nullptr;
            removed->left = nullptr;
            delete removed;
            //cout<<"successfully removed root"<<endl;
        }
    }
    else{
        if(removed->left ==nullptr && removed->right == nullptr){
            //cout<<"no children"<<endl;
            if(parent->right == removed){
                parent->right = nullptr;
            }
            else if(parent->left == removed){
                parent->left = nullptr;
            }
            delete removed;
        }
            //if 1 child- delete element, parent->left/right = child
        else if(removed->left==nullptr || removed->right == nullptr){
            //cout<<"one child"<<endl;
            if(parent->left==removed){
                if(removed->left!=nullptr){
                    parent->left = removed->left;
                    removed->left = nullptr;
                }
                else{
                    parent->left = removed->right;
                    removed->right = nullptr;
                }
            }
            else if(parent->right == removed){
                if(removed->left!=nullptr){
                    parent->right = removed->left;
                    removed->left = nullptr;
                }
                else{
                    parent->right = removed->right;
                    removed->right = nullptr;
                }
            }
            delete removed;
        }
        else{
            //cout<<"two children"<<endl;
            Student* newParent = getNextInOrder(removed);
            //cout<<newParent->name<<endl;
            if(parent->left==removed){
                if(removed->right==newParent){
                    parent->left = newParent;
                    newParent->left = removed->left;
                    removed->left=nullptr;
                    removed->right = nullptr;
                }
                else if(removed->right->left ==newParent){
                    parent->left = newParent;
                    newParent->left = removed->left;
                    newParent->right = removed->right;
                    removed->right->left = nullptr;
                    removed->right = nullptr;
                    removed->left = nullptr;
                }
            }
            else if(parent->right==removed){
                if(removed->right==newParent){
                    parent->right = newParent;
                    newParent->left = removed->left;
                    removed->left=nullptr;
                    removed->right = nullptr;
                }
                else if(removed->right->left ==newParent){
                    parent->right = newParent;
                    newParent->left = removed->left;
                    newParent->right = removed->right;
                    removed->right->left = nullptr;
                    removed->right = nullptr;
                    removed->left = nullptr;
                }
            }
            delete removed;
        }
    }



}

//old remove function that was scrapped
//doesn't account for the root
//too complicated keeping track of removed node's parent's left and right
//new remove just passes in the parent for easier process
void AVLTree::remove(Student *curr, bool isLeft) {
    //delete from student vect and id vect
    //delete student element
    //make destructor for student
    //cout<<"removing "<<curr->name<<"'s  next element"<<endl;
    Student* removed;

    if(curr==root){
        //implement
        removed = root;
        //cout<<"removing root in remove"<<endl;
    }
    else{
        if(isLeft){
            removed = curr->left;
        }
        else{
            removed = curr->right;
        }
    }

//    UNCOMMENT TO REMOVE STUFF FROM VECTOR
//    removeStudentVect(removed);
//    removeIntVect(removed->id);
//    cout<<"removed from vects"<<endl;

    //if no children- delete element, parent->left/right = null
    if(removed->left ==nullptr && removed->right == nullptr){
        //cout<<"no children"<<endl;
        if(isLeft){
            curr->left = nullptr;
        }
        else{
            curr->right = nullptr;
        }
        delete removed;
    }
    //if 1 child- delete element, parent->left/right = child
    else if(removed->left==nullptr || removed->right == nullptr){
        //cout<<"one child"<<endl;
        if(isLeft){
            if(removed->left!=nullptr){
                curr->left = removed->left;
            }
            else{
                curr->left = removed->right;
            }
            curr->right = nullptr;
        }
        else{
            if(removed->left!=nullptr){
                curr->right = removed->left;
            }
            else{
                curr->right = removed->right;
            }
            curr->right = nullptr;
        }
        delete removed;
    }
    else{
        //cout<<"two children"<<endl;
        //implement get next in order
        //go right and then all the way to the left and that the new parent
        Student* newParent = getNextInOrder(removed);
        //cout<<newParent->name<<endl;
        //cout<<"is left "<<isLeft<<endl;
        if(isLeft){
            //cout<<"made it to left if"<<endl;
            curr->left = newParent;
            newParent->left = removed->left;
            if(newParent != removed->right){
                newParent->right = removed->right;
            }
            else{
                newParent->right = nullptr;
            }
        }
        else{
            //cout<<"made it to right if"<<endl;
            curr->right = newParent;
            newParent->left = removed->left;
            if(newParent != removed->right){
                newParent->right = removed->right;
            }
            else{
                newParent->right = nullptr;
            }

        }
        delete removed;
    }

}

//next in order is to the right and then all the way to the left
//this function traverses ^^ to find next in order and returns the student object
Student* AVLTree::getNextInOrder(Student *curr) {
    curr = curr->right;
    if(curr->left==nullptr){
        return curr;
    }

    while(curr->left!=nullptr){
        curr= curr->left;
    }
    return curr;
}

//loops through student vector and removes specified student object
void AVLTree::removeStudentVect(Student *curr) {
    //cout<<"remove student vect"<<endl;
    for(int i=0; i<AVLStudentVect.size(); i++){
        Student* it = AVLStudentVect[i];
        if(it==curr){
            AVLStudentVect.erase(AVLStudentVect.begin()+i);
        }
    }
    //cout<<"removed "<<curr->name<<" from Student vect"<<endl;
}

//loops through id vector and removes specified id number
void AVLTree::removeIntVect(int curr) {
    for(int i=0; i<AVLVect.size(); i++){
        int it = AVLVect[i];
        if(it==curr){
            AVLVect.erase(AVLVect.begin()+i);
        }
    }
    //cout<<"removed "<<curr<<" from int vect"<<endl;
}

//same as printInOrder but adds the values to a vector instead of printing
//returns vector of values
vector<int> AVLTree::returnInOrder(){
    vector<int> returnedVect;
    sort(AVLVect.begin(),AVLVect.end());
    for(int i=0; i<AVLVect.size(); i++){
        returnedVect.push_back(AVLVect[i]);
    }
    return returnedVect;
}
