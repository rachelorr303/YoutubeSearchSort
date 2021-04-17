//
// Created by Monique Huang on 4/17/21.
//

#include "BST.h"

BST::BST() {
    root = nullptr;
}

int BST::getDislikeRatio(Node *curr) {
    int ratio = curr->likes/curr->dislikes;
    return ratio;
}

Node *
BST::insertByViews(string trend, string title, string chan, string pub, int time, string day, vector<string> tags, int v, int ls, int dls,
            int cc, Node* curr) {
    if(searchTitle(title, v, curr) == nullptr) {
        if(curr == nullptr) { //current node is empty or its root of tree
            curr = new Node(trend, title, chan, pub, time, day, tags, v, ls, dls, cc);
            return curr;
        }
        else if(curr->views > v){ //store new node in left subtree
            curr->left = insertByViews(trend, title, chan, pub, time, day, tags, v, ls, dls, cc, curr->left);
        }
        else if(curr->views < v){ //store new node in right subtree
            curr->right = insertByViews(trend, title, chan, pub, time, day, tags, v, ls, dls, cc, curr->right);
        }
    }
    return curr;
}

Node *
BST::insertByLikes(string trend, string title, string chan, string pub, int time, string day, vector<string> tags, int v, int ls, int dls,
                   int cc, Node* curr) {
    if(searchTitle(title, v, curr) == nullptr) {
        if(curr == nullptr) { //current node is empty or its root of tree
            curr = new Node(trend, title, chan, pub, time, day, tags, v, ls, dls, cc);
            return curr;
        }
        else if(curr->likes > ls){ //store new node in left subtree
            curr->left = insertByLikes(trend, title, chan, pub, time, day, tags, v, ls, dls, cc, curr->left);
        }
        else if(curr->likes < ls){ //store new node in right subtree
            curr->right = insertByLikes(trend, title, chan, pub, time, day, tags, v, ls, dls, cc, curr->right);
        }
    }
    return curr;
}

Node *
BST::insertByComments(string trend, string title, string chan, string pub, int time, string day, vector<string> tags, int v, int ls, int dls,
                   int cc, Node* curr) {
    if(searchTitle(title, v, curr) == nullptr) {
        if(curr == nullptr) { //current node is empty or its root of tree
            curr = new Node(trend, title, chan, pub, time, day, tags, v, ls, dls, cc);
            return curr;
        }
        else if(curr->likes > ls){ //store new node in left subtree
            curr->left = insertByComments(trend, title, chan, pub, time, day, tags, v, ls, dls, cc, curr->left);
        }
        else if(curr->likes < ls){ //store new node in right subtree
            curr->right = insertByComments(trend, title, chan, pub, time, day, tags, v, ls, dls, cc, curr->right);
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

