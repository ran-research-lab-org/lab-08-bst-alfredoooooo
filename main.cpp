// Alfredo F. Frontera Del Valle
// Lab 08
// 801-21-1568

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "BinarySearchTree.hpp"

TEST_CASE("Testing insert and contains") {
    BinarySearchTree<int> tree;
    
    CHECK(tree.toInorderStr() == "");
    
    tree.insert(8);
    CHECK(tree.contains(8) == true);
    CHECK(tree.toInorderStr() == "8");
    
    tree.insert(3);
    tree.insert(10);
    tree.insert(1);
    tree.insert(6);
    CHECK(tree.toInorderStr() == "1 3 6 8 10");
    CHECK(tree.contains(6) == true);
    CHECK(tree.contains(99) == false);
}

TEST_CASE("Testing remove") {
    BinarySearchTree<int> tree;
    tree.insert(8);
    tree.insert(3);
    tree.insert(10);
    tree.insert(1);
    
    tree.remove(1);
    CHECK(tree.contains(1) == false);
    CHECK(tree.toInorderStr() == "3 8 10");
}

TEST_CASE("Testing BFT - Tree A") {
    BinarySearchTree<int> tree;
    
    tree.insert(8);
    tree.insert(3);
    tree.insert(10);
    tree.insert(1);
    tree.insert(6);
    tree.insert(14);
    tree.insert(4);
    tree.insert(7);
    tree.insert(13);
    
    CHECK(tree.BFT() == "[[8],[3,10],[1,6,14],[4,7,13]]");
}

TEST_CASE("Testing BFT - Tree B") {
    BinarySearchTree<int> tree;
    
    tree.insert(6);
    tree.insert(2);
    tree.insert(8);
    tree.insert(7);
    tree.insert(9);
    
    CHECK(tree.BFT() == "[[6],[2,8],[7,9]]");
}

TEST_CASE("Testing BFT - Empty tree") {
    BinarySearchTree<int> tree;
    CHECK(tree.BFT() == "[]");
}