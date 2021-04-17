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
    int tags;
    int views;
    int likes;
    int dislikes;
    int comments;
    Node *left;
    Node *right;
    Node();
    Node(string trend, string tile, string chan, string pub, int tm, string da, int tgs, int v, int ls, int dls, int cc) : trending(trend), title(tile), channel(chan), published(pub), time(tm), day(da), tags(tgs), views(v), likes(ls), dislikes(dls), comments(cc) {}
};

Node::Node() {
    trending = "";
    title = "";
    channel = "";
    published = "";
    time = 0;
    day = "";
    tags = 0;
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
    Node* insert(string trend, string title, string chan, string pub, int time, string day, int tags, int v, int ls, int dls, int cc, Node* curr);
    Node* searchTitle(string title, int v, Node*);
    vector<Node*> searchByViews(int views, Node*);
    vector<Node*> searchChannel(string chan, Node*);
};

BST::BST() {
    root = nullptr;
}

int BST::getDislikeRatio(Node *curr) {
    int ratio = curr->likes/curr->dislikes;
    return ratio;
}

Node *
BST::insert(string trend, string title, string chan, string pub, int time, string day, int tags, int v, int ls, int dls,
            int cc, Node* curr) {
    if(searchTitle(title, v, curr) == nullptr) {
        if(curr == nullptr) { //current node is empty or its root of tree
            curr = new Node(trend, title, chan, pub, time, day, tags, v, ls, dls, cc);
            return curr;
        }
        else if(curr->views > v){ //store new node in left subtree
            curr->left = insert(trend, title, chan, pub, time, day, tags, v, ls, dls, cc, curr->left);
        }
        else if(curr->views < v){ //store new node in right subtree
            curr->right = insert(trend, title, chan, pub, time, day, tags, v, ls, dls, cc, curr->right);
        }
    }
    return curr;
}

Node* BST::searchTitle(string title, int views, Node *curr) {
    Node* temp = new Node();
    if (curr == nullptr) {
        cout << "Title not found." << endl;
        return nullptr;
    }
    else if(curr->title==title) { //if current node's name is equal to searched name
        temp = curr;
    }
    else if(curr->views > views) {
        return searchTitle(title, views, curr->left);
    }
    else {
        return searchTitle(title, views, curr->right);
    }
    return temp;
}

vector<Node*> BST::searchChannel(string chan, Node *curr) {
    if(curr == nullptr) {
        return chanVids; //make sure to clear chanVids before using it again
    }
    else if(curr->channel==chan) {
        chanVids.push_back(curr);
    }
    else {
        searchChannel(chan, curr->left);
        searchChannel(chan, curr->right);
    }
    return chanVids;
}

vector<Node*> BST::searchByViews(int maxViews, Node *curr) {
    if(curr == nullptr) {
        return viewsRange;
    }
    else if(curr->views < maxViews) {
        chanVids.push_back(curr);
    }
    else {
        searchByViews(maxViews, curr->left);
        searchByViews(maxViews, curr->right);
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
