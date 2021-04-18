#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class Node {
public:
    string trending;
    string title;
    string channel;
    string published;
    string time;
    string day;
    int views;
    int likes;
    int dislikes;
    int comments;
    Node *left;
    Node *right;
    Node();
    Node(string trend, string tile, string chan, string pub, string tm, string da, int v, int ls, int dls, int cc) : trending(trend), title(tile), channel(chan), published(pub), time(tm), day(da), views(v), likes(ls), dislikes(dls), comments(cc) {}
};

Node::Node() {
    trending = "";
    title = "";
    channel = "";
    published = "";
    time = "";
    day = "";
    views = 0;
    likes = 0;
    dislikes = 0;
    comments = 0;
    left = nullptr;
    right = nullptr;
}

class BST {
private:
    int getDislikeRatio(Node*);
public:
    BST();
    Node *root;
    vector<Node*> keyVids;
    vector<Node*> chanVids;
    vector<Node*> viewsRange;
    Node* insertByViews(string&, string&, string&, string&, int&, string&, int&, int&, int&, int&, Node*);
    Node* searchTitle(string&, int&, Node*);
    void searchTitle(string&, Node*);
    void searchKey(string&, Node*);
    void searchByViewRange(int&, int&, Node*);
    void searchChannel(string&, Node*);
    void readFile();
    ifstream file;
};

