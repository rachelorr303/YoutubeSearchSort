#pragma once
#include "Node.h"
using namespace std;

class AvlTree {

public:
    Node* root;
    vector<Node*> vids;
    ifstream file;
    AvlTree();
    Node* insertViews(string trend, string title_, string chan, string pub, string t, string d, long v, long l, long dl, int c, Node* root);
    bool titleExist(string title_, Node* node);
    void searchTitle(string t, Node* node);
    void searchWord(string key, Node* node);
    void searchChannel(string chan, Node* node);
    void searchViews(int min, int max, Node* node);
    int findLevels(Node* rootNode);
    int findBF(Node* rootNode);
    Node* leftRotation(Node* node);
    Node* rightRotation(Node* node);
    void printInfo(Node* node);
    void getStats(vector<Node*> group);
    Node* readFile();
};