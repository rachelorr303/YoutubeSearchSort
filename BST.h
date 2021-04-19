#pragma once
#include "Node.h"

class BST {
private:
    int avgStat(Node*);
public:
    BST();
    Node *root;
    vector<Node*> vids;
    Node* insert(string, string, string, string, string, string, int, int, int, int, Node*);
    //bool searchTitle(string, Node*);
    void getStats(vector<Node*> group);
    void searchTitleMenu(string, Node*);
    void searchKey(string, Node*);
    void searchByViewRange(int, int, Node*);
    void searchChannel(string, Node*);
    void printInfo(Node*);
    Node* readFile();
    ifstream file;
};

