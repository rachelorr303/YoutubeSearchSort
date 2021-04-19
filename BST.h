#pragma once
#include "Node.h"

class BST {
private:
    int getDislikeRatio(Node*);
public:
    BST();
    Node *root;
    vector<Node*> keyVids;
    vector<Node*> chanVids;
    vector<Node*> viewsRange;
    Node* insert(string, string, string, string, string, string, int, int, int, int, Node*);
    //bool searchTitle(string, Node*);
    void searchTitleMenu(string, Node*);
    void searchKey(string, Node*);
    void searchByViewRange(int, int, Node*);
    void searchChannel(string, Node*);
    void printInfo(Node*);
    Node* readFile();
    ifstream file;
};

