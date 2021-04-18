#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node{

public:
    string trending;
    string title;
    string channel;
    string published;
    int time; // just the hour
    string day;
    long views;
    long likes;
    long dislikes;
    float ratio;
    int comments;
    vector<string> tags;
    Node* left;
    Node* right;

    Node();
    Node(string trend, string title_, string chan, string pub, int t, string d, long v, long l, long dl, int c, vector<string> tag);
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
    ratio = 0;
    comments = 0;
    left = nullptr;
    right = nullptr;
}

Node::Node(string trend, string title_, string chan, string pub, int t, string d, long v, long l, long dl, int c, vector<string> tag) {
    trending = trend;
    title = title_;
    channel = chan;
    published = pub;
    time = t;
    day = d;
    views = v;
    likes = l;
    dislikes = dl;
    ratio = l/dl;
    comments = c;
    for(int i = 0; i < tag.size(); i++)
        tags.push_back(tag[i]);
    left = nullptr;
    right = nullptr;
}

class AvlTree {

public:
    Node* root;
    AvlTree();
    Node* insertViews(string trend, string title_, string chan, string pub, int t, string d, long v, long l, long dl, int c, vector<string> tag, Node* root);
    Node* insertLikes(string trend, string title_, string chan, string pub, int t, string d, long v, long l, long dl, int c, vector<string> tag, Node* root);
    Node* insertCom(string trend, string title_, string chan, string pub, int t, string d, long v, long l, long dl, int c, vector<string> tag, Node* root);
    Node* searchTitle(string t, int v, Node* node);
    void searchWord(string key, Node* node, vector<Node*>& all);
    void searchChannel(string chan, Node* node, vector<Node*>& all);
    int findLevels(Node* rootNode);
    int findBF(Node* rootNode);
    Node* leftRotation(Node* node);
    Node* rightRotation(Node* node);
};