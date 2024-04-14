//
// Created by Sophie Shah on 2/7/2024.
//
#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
public:
    int id;
    string name;
    int height;
    Student* left;
    Student* right;
    Student* parent;

    Student();
    Student(int id, string name);
    ~Student();
};