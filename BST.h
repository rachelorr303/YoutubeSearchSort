#pragma once
#include "Node.h"

class BST {
private:
    Node* insert(string, string, string, string, string, string, int, int, int, int, Node*);
public:
    BST();
    Node *root;
    vector<Node*> vids;
    bool titleExist(string title, Node* node);
    void getStats(vector<Node*> group);
    void searchTitle(string, Node*);
    void searchKey(string, Node*);
    void searchViews(int, int, Node*);
    void searchChannel(string, Node*);
    void printInfo(Node*);
    Node* readFile();
    ifstream file;
};

