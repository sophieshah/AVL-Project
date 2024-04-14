//
// Created by Sophie Shah on 2/7/2024.
//

#include <iostream>
#include <string>
#include <vector>
#include "Student.h"

using namespace std;

//constructor for student object without given id and name
Student::Student() {
    left = nullptr;
    right = nullptr;
    parent  = nullptr;
    height = 0;
    name = "";
    id = 0;
}

//constructor for student object passing in id and name
Student::Student(int id, string name) {
    this->id = id;
    this->name = name;
    this->height = 0;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
}

//destructor for student object
Student::~Student(){
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
}

