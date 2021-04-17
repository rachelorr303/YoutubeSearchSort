#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    string trending;
    string title;
    string channel;
    string published;
    int time;
    string day;
    vector<string> tags;
    int views;
    int likes;
    int dislikes;
    int comments;
    Node *left;
    Node *right;
    Node();
    Node(string trend, string tile, string chan, string pub, int tm, string da, vector<string> tgs, int v, int ls, int dls, int cc) : trending(trend), title(tile), channel(chan), published(pub), time(tm), day(da), tags(tgs), views(v), likes(ls), dislikes(dls), comments(cc) {}
};

Node::Node() {
    trending = "";
    title = "";
    channel = "";
    published = "";
    time = 0;
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
    vector<Node*> chanVids;
    vector<Node*> viewsRange;
    Node* insertByViews(string, string, string, string, int, string, vector<string>, int, int, int, int, Node*);
    Node* insertByLikes(string, string, string, string, int, string, vector<string>, int, int, int, int, Node*);
    Node* insertByComments(string, string, string, string, int, string, vector<string>, int, int, int, int, Node*);
    Node* searchTitle(string title, int v, Node*);
    vector<Node*> searchByViews(int views, Node*);
    vector<Node*> searchChannel(string chan, Node*);
};

