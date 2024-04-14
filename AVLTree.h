//
// Created by Sophie Shah on 2/7/2024.
//
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Student.h"

using namespace std;

class AVLTree {
private:
    vector<int> AVLVect;
    vector<Student*> AVLStudentVect;
    Student* root;
    int treeHeight;
public:
    AVLTree();
    ~AVLTree();
    Student* getRoot();
    void insert(string ID, string name);
    bool insertValid(string ID, string name);
    Student* insertHelper(Student* s, Student* curr_);
    int getLeftHeight(Student* curr);
    int getRightHeight(Student* curr);
    int totalBalance(Student* curr);
    int balanceHelper(Student* curr);
    Student* leftRotation(Student* curr);
    Student* rightRotation(Student* curr);
    Student* leftRightRotation(Student* curr);
    Student* rightLeftRotation(Student* curr);
    void printLevelCount();
    Student* printPreOrder(Student* curr);
    Student* printPostOrder(Student* curr);
    Student* printInOrder(Student* curr);
    void searchID(int findId);
    void searchName(string findName);
    Student* getSearchId(int findId);
    Student* getParentId(Student* curr);
    void removeId(int removedId);
    Student* removeIdFinder(Student* curr, int removedId);
    void remove(Student* curr, bool isLeft);
    void newRemove(Student* removed, Student* parent);
    void removeInOrder(int n);
    Student* getNextInOrder(Student* curr);
    //Student* removeInOrderFinder(Student* curr, int n, int currInt);
    void removeStudentVect(Student* curr);
    void removeIntVect(int curr);
    vector<int> returnInOrder();

};
