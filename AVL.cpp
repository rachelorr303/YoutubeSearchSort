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

Node* AvlTree::searchTitle(string t, int v, Node* node){
    if(node == nullptr) {
        return nullptr;
    }
    else if(node->title == t)
        return node;
    else if(v < node->views)
        return searchTitle(t, v, node->left);
    else
        return searchTitle(t, v, node->right);
}

void AvlTree::searchTitle2(string t, Node* node) {
    if(node == nullptr)
        return;
    else if(node->title == t) {
        printInfo(node);
    }
    searchTitle2(t, node->left);
    searchTitle2(t, node->right);
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

Node* AvlTree::insertViews(string trend, string title_, string chan, string pub, string t, string d, long v, long l, long dl, int c, vector<string> tag, Node* rootNode){
    if(searchTitle(title_, v, rootNode) != nullptr) { // check if title already exists
        cout << "unsuccessful" << endl;
        return rootNode;
    }

    Node* insertion = new Node(trend, title_, chan, pub, t, d, v, l, dl, c);

    if(root == nullptr)
        root = insertion;

    if(rootNode == nullptr) {
        cout << "successful" << endl;
        return insertion;
    }
    else if (v < rootNode->views) {
        rootNode->left = insertViews(trend, title_, chan, pub, t, d, v, l, dl, c, tag, rootNode->left);
    }
    else if (v > rootNode->views)
        rootNode->right = insertViews(trend, title_, chan, pub, t, d, v, l, dl, c, tag, rootNode->right);

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
    newT = node->trending.substr(5, 2) + "/" + node->trending.substr(8, 2) + "/" + node->trending.substr(2, 2);
    string newP = "";
    newP = node->published.substr(6,2) + "/" + node->published.substr(3, 2) + "/" + node->published.substr(0, 2);

    cout << node->title << " published by " << node->channel << endl;
    cout << "Views: " << node->views << endl;
    cout << "Likes: " << node->likes << endl;
    cout << "Dislikes: " << node->dislikes << endl;
    cout << "Number of comments: " << node->comments << endl;
    cout << "Published: " << node->day << " " << node->time << ", " << newP << endl; // need to format
    cout << "Trending on: " << newT << endl;
}


AvlTree::AvlTree() {
    root = nullptr;
}

