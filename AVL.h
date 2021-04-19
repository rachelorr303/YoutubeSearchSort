#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "Node.h"
using namespace std;

class AvlTree {

public:
    Node* root;
    vector<Node*> keywords;
    vector<Node*> channels;
    vector<Node*> ranges;
    AvlTree();
    Node* insertViews(string trend, string title_, string chan, string pub, string t, string d, long v, long l, long dl, int c, Node* root);
    void searchTitle(string t, Node* node, bool& found);
    void searchWord(string key, Node* node);
    void searchChannel(string chan, Node* node);
    void searchViews(int max, int min, Node* node);
    int findLevels(Node* rootNode);
    int findBF(Node* rootNode);
    Node* leftRotation(Node* node);
    Node* rightRotation(Node* node);
    void printInfo(Node* node);
    void getStats(vector<Node*> group);
};
