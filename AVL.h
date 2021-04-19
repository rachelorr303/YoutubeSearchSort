#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <fstream>
#include "Node.h"
using namespace std;

class AvlTree {

public:
    Node* root;
    vector<Node*> keywords;
    vector<Node*> channels;
    vector<Node*> ranges;
    ifstream file;
    AvlTree();
    Node* insertViews(string trend, string title_, string chan, string pub, string t, string d, long v, long l, long dl, int c, Node* root);
    bool titleExist(string t, Node* node);
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
    void readFile();
};
