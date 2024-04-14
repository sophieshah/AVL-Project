//#include "catch.hpp"
//#define CATCH_CONFIG_MAIN
//#include <iostream>
//#include <vector>
//
//#include "C:\DSAProject1\src\AVLTree.h"
//
//TEST_CASE("Incorrect Commands", "[flag]"){
//    AVLTree avl;
//    avl.insert(123456789, "Sophie");
//    avl.insert(12345678, "S0phi3");
//    avl.insert(12345678, "12345678");
//    avl.insert(12345678, "Correct");
//    avl.insert(12345678, "Duplicate");
//    avl.insert(11111111, "hello_world");
//
//    vector<int> actual = avl.returnInOrder();
//    vector<int> expected = {12345678};
//    REQUIRE(expected.size() == actual.size());
//    REQUIRE(actual == expected);
//}
//
//TEST_CASE("Edge Cases", "[flag]"){
//    AVLTree avl;
//    avl.insert(11111111, "Sophie1");
//    avl.insert(22222222, "Sophie2");
//    avl.insert(33333333, "Sophie3");
//
//    avl.removeId(44444444);
//    avl.searchID(12345678);
//    avl.searchName("Sophie0");
//
//    vector<int> actual = avl.returnInOrder();
//    vector<int> expected = {11111111, 22222222, 33333333};
//    REQUIRE(expected.size() == actual.size());
//    REQUIRE(actual == expected);
//}
//
//TEST_CASE("Delete with no children", "[deletion]"){
//    AVLTree avl;
//    avl.insert(11111111, "Sophie1");
//    avl.insert(22222222, "Sophie2");
//    avl.insert(33333333, "Sophie3");
//
//    avl.removeId(33333333);
//
//    vector<int> actual = avl.returnInOrder();
//    vector<int> expected = {11111111, 22222222};
//    REQUIRE(expected.size() == actual.size());
//    REQUIRE(actual == expected);
//}
//
//TEST_CASE("Delete with one child", "[deletion]"){
//    AVLTree avl;
//    avl.insert(11111111, "Sophie1");
//    avl.insert(22222222, "Sophie2");
//    avl.insert(33333333, "Sophie3");
//    avl.insert(44444444, "Sophie4");
//
//    avl.removeId(33333333);
//
//    vector<int> actual = avl.returnInOrder();
//    vector<int> expected = {11111111, 22222222, 44444444};
//    REQUIRE(expected.size() == actual.size());
//    REQUIRE(actual == expected);
//}
//
//TEST_CASE("Delete with two children", "[deletion]"){
//    AVLTree avl;
//    avl.insert(11111111, "Sophie1");
//    avl.insert(22222222, "Sophie2");
//    avl.insert(33333333, "Sophie3");
//    avl.insert(44444444, "Sophie4");
//    avl.insert(55555555, "Sophie5");
//
//    avl.removeId(44444444);
//
//    vector<int> actual = avl.returnInOrder();
//    vector<int> expected = {11111111, 22222222, 33333333, 55555555};
//    REQUIRE(expected.size() == actual.size());
//    REQUIRE(actual == expected);
//}
//
//TEST_CASE("Left rotation", "[rotation]"){
//    AVLTree avl;
//    avl.insert(11111111, "Sophie1");
//    avl.insert(22222222, "Sophie2");
//    avl.insert(33333333, "Sophie3");
//
//    vector<int> actual = avl.returnInOrder();
//    vector<int> expected = {11111111, 22222222, 33333333};
//    REQUIRE(expected.size() == actual.size());
//    REQUIRE(actual == expected);
//}
//
//TEST_CASE("Right rotation", "[rotation]"){
//    AVLTree avl;
//    avl.insert(33333333, "Sophie3");
//    avl.insert(22222222, "Sophie2");
//    avl.insert(11111111, "Sophie1");
//
//    vector<int> actual = avl.returnInOrder();
//    vector<int> expected = {11111111, 22222222, 33333333};
//    REQUIRE(expected.size() == actual.size());
//    REQUIRE(actual == expected);
//}
//
//TEST_CASE("Left-Right rotation", "[rotation]"){
//    AVLTree avl;
//    avl.insert(33333333, "Sophie3");
//    avl.insert(11111111, "Sophie1");
//    avl.insert(22222222, "Sophie2");
//
//    vector<int> actual = avl.returnInOrder();
//    vector<int> expected = {11111111, 22222222, 33333333};
//    REQUIRE(expected.size() == actual.size());
//    REQUIRE(actual == expected);
//}
//
//TEST_CASE("Right-Left rotation", "[rotation]"){
//    AVLTree avl;
//    avl.insert(11111111, "Sophie1");
//    avl.insert(33333333, "Sophie3");
//    avl.insert(22222222, "Sophie2");
//
//    vector<int> actual = avl.returnInOrder();
//    vector<int> expected = {11111111, 22222222, 33333333};
//    REQUIRE(expected.size() == actual.size());
//    REQUIRE(actual == expected);
//}
//
//TEST_CASE("Inserting/Removing 100 Nodes", "[insert/remove]"){
//    AVLTree avl;
//    int id = 11111111;
//    string name = "a";
//    vector<int> insertInts;
//    insertInts.push_back(11111111);
//    avl.insert(id, name);
//    for(int i=0; i<99; i++){
//        avl.insert(id+1, name+"a");
//        insertInts.push_back(id+1);
//    }
//
//    avl.removeId(11111112);
//    avl.removeId(11111120);
//    avl.removeId(11111209);
//    avl.removeId(11111210);
//    avl.removeId(11111111);
//
//    for(auto it = insertInts.begin(); it!=insertInts.end(); it++){
//        if(*it==11111112){
//            insertInts.erase(it);
//        }
//        else if(*it==11111120){
//            insertInts.erase(it);
//        }
//        else if(*it==11111209){
//            insertInts.erase(it);
//        }
//        else if(*it==11111210){
//            insertInts.erase(it);
//        }
//        else if(*it==11111111){
//            insertInts.erase(it);
//        }
//    }
//
//    vector<int> actual = avl.returnInOrder();
//    vector<int> expected = insertInts;
//    REQUIRE(expected.size() == actual.size());
//    REQUIRE(actual == expected);
//}
