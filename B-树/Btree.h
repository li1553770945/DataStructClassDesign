#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <qlabel.h>
#include <QtWidgets/QApplication>
class BTreeNode :public QLabel{
public:
    int* keys;
    int t;//key的个数
    BTreeNode** C;
    int n;//叶子的个数
    bool leaf;
    int x, y;
    int occupy_width;
    BTreeNode(int _t, bool _leaf);
    int find_key(int k);
    void insert(int k);
    void split_child(int i, BTreeNode* y);
    void deletion(int k);
    void remove_from_leaf(int index);
    void remove_from_non_leaf(int index);
    int getPredecessor(int index);
    int getSuccessor(int index);
    void fill(int index);
    void borrowFromPrev(int index);
    void borrowFromNext(int index);
    void merge(int index);
    BTreeNode* search(int k);
    friend class BTree;
};
class BTree {
public:
    BTreeNode* root;
    int t;
    BTree(int _t);
    void insertion(int k);
    void deletion(int k);
    BTreeNode* search(int k);
};