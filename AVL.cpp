#include "AVL.h"

int AvlTree::findLevels(Node* rootNode) {
    if (rootNode == nullptr)
        return 0;
    else if (rootNode->left == nullptr && rootNode->right == nullptr)
        return 1;
    else {
        int leftHeight = findLevels(rootNode->left);
        int rightHeight = findLevels(rootNode->right);

        if (leftHeight >= rightHeight)
            return (leftHeight + 1);
        else
            return (rightHeight + 1);
    }
}

int AvlTree::findBF(Node *rootNode) {
    int BF = 0;
    int leftHeight = findLevels(rootNode->left);
    int rightHeight = findLevels(rootNode->right);
    BF = leftHeight - rightHeight;
    return BF;
}

Node* AvlTree::leftRotation(Node* node) {
    Node* newNode = node->right;
    node->right = newNode->left;
    newNode->left = node;
    return newNode;
}

Node* AvlTree::rightRotation(Node* node) {
    Node* newNode = node->left;
    node->left = newNode->right;
    newNode->right = node;
    return newNode;
}

void AvlTree::searchTitle(string t, Node* node, bool& found) {
    if(node == nullptr) {
        //cout << "Title not found" << endl;
        return;
    }
    else if(node->title == t) {
        printInfo(node);
        found = true;
    }
    searchTitle(t, node->left, found);
    searchTitle(t, node->right, found);
}

void AvlTree::searchWord(string key, Node* node){
    if(node == nullptr)
        return;
    else if(node->title.find(key) != string::npos) {
        keywords.push_back(node);
    }
    searchWord(key, node->left);
    searchWord(key, node->right);
}

void AvlTree::searchChannel(string chan, Node* node) {
    if(node == nullptr)
        return;
    else if(node->channel == chan)
        channels.push_back(node);
    searchChannel(chan, node->left);
    searchChannel(chan, node->right);
}

void AvlTree::searchViews(int max, int min, Node* node) {
    if(node == nullptr)
        return;
    else if(node->views < max && node->views > min)
        ranges.push_back(node);
    searchViews(max, min, node->left);
    searchViews(max, min, node->right);
}

Node* AvlTree::insertViews(string trend, string title_, string chan, string pub, string t, string d, long v, long l, long dl, int c, Node* rootNode){
    bool found = false;
    searchTitle(title_, rootNode, found);
    if(found) { // check if title already exists
        cout << "Video already exists" << endl;
        return rootNode;
    }

    Node* insertion = new Node(trend, title_, chan, pub, t, d, v, l, dl, c);

    if(root == nullptr)
        root = insertion;

    if(rootNode == nullptr) {
        cout << "successful" << endl;
        return insertion;
    }
    else if (v < rootNode->views) { // should i do <= ??
        rootNode->left = insertViews(trend, title_, chan, pub, t, d, v, l, dl, c, rootNode->left);
    }
    else if (v > rootNode->views)
        rootNode->right = insertViews(trend, title_, chan, pub, t, d, v, l, dl, c, rootNode->right);

    // BALANCE
    int BF = findBF(rootNode);
    if (BF > 1 && v < rootNode->left->views) // left left
        return rightRotation(rootNode);
    if (BF < -1 && v > rootNode->right->views) // right right
        return leftRotation(rootNode);
    if (BF > 1 && v > rootNode->left->views) { // left right
        rootNode->left = leftRotation(rootNode->left);
        return rightRotation(rootNode);
    }
    if (BF < -1 && v < rootNode->right->views) { // right left
        rootNode->right = rightRotation(rootNode->right);
        return leftRotation(rootNode);
    }
    return rootNode;
}



void AvlTree::printInfo(Node* node) {
    string newT = "";
    newT = node->trending.substr(3, 2) + "/" + node->trending.substr(6, 2) + "/" + node->trending.substr(0, 2);
    string newP = "";
    if(node->published.length() == 10)
        newP = node->published.substr(0, 6) + node->published.substr(8, 2);

    cout << node->title << " published by " << node->channel << endl;
    cout << "Views: " << node->views << endl;
    cout << "Likes: " << node->likes << endl;
    cout << "Dislikes: " << node->dislikes << endl;
    cout << "Number of comments: " << node->comments << endl;
    if(node->published.length() < 10) {
        cout << "Published: " << node->day << " " << node->time << ", " << node->published << endl; // need to format
    }
    else
        cout << "Published: " << node->day << " " << node->time << ", " << newP << endl;
    cout << "Trending on: " << newT << endl;
}

void AvlTree::getStats(vector<Node*> group) {
    cout << "Stats for " << group.size() << " videos:" << endl;
    int avgViews = 0;
    int avgLikes = 0;
    int avgDislikes = 0;
    int avgComments = 0;
    unordered_map<string, int> dow;
    unordered_map<string, int> tod;
    for(int i = 0; i < group.size(); i++) {
        avgViews += group[i]->views;
        avgLikes += group[i]->likes;
        avgDislikes += group[i]->dislikes;
        avgComments += group[i]->comments;
        ++dow[group[i]->day];
        ++tod[group[i]->time];
    }
    avgViews = avgViews/ group.size();
    cout << "Average views: " << avgViews << endl;

    avgLikes = avgLikes / group.size();
    cout << "Average likes: " << avgLikes << endl;

    avgDislikes = avgDislikes / group.size();
    cout << "Average dislikes: " << avgDislikes << endl;

    cout << "Like to dislike ratio: " << avgLikes/avgDislikes << endl;

    avgComments = avgComments / group.size();
    cout << "Average comments: " << avgComments << endl;

    int max = 0;
    string maxKey;
    for(auto iter = dow.begin(); iter != dow.end(); iter++) {
        if(iter->second > max) {
            maxKey = iter->first;
            max = iter->second;
        }
    }
    cout << "Most common day of the week to post: " << maxKey << endl;

    max = 0;
    maxKey = "";
    for(auto iter2 = tod.begin(); iter2 != tod.end(); iter2++) {
        if(iter2->second > max) {
            maxKey = iter2->first;
            max = iter2->second;
        }
    }
    cout << "Most common time of day to post: " << maxKey << endl;
}

AvlTree::AvlTree() {
    root = nullptr;
}
