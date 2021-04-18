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
        cout << "Title not found." << endl;
        return nullptr;
    }
    else if(node->title == t)
        return node;
    else if(v < node->views)
        return searchTitle(t, v, node->left);
    else
        return searchTitle(t, v, node->right);
}

// Search for student by id
// Return true if found
void AvlTree::searchWord(string key, Node* node, vector<Node*>& all){
    if(node == nullptr)
        return;
    else if(node->title.find(key) != string::npos) {
        all.push_back(node);
    }
    searchWord(key, node->left, all);
    searchWord(key, node->right, all);
}

void AvlTree::searchChannel(string chan, Node* node, vector<Node*>& all) {
    if(node == nullptr)
        return;
    else if(node->channel == chan)
        all.push_back(node);
    searchChannel(chan, node->left, all);
    searchChannel(chan, node->right, all);
}

// Insert node with name and id into tree
// Balance if necessary

Node* AvlTree::insertViews(string trend, string title_, string chan, string pub, int t, string d, long v, long l, long dl, int c, vector<string> tag, Node* rootNode){
    //insert, assign BF, balance
    if(searchTitle(title_, v, rootNode) != nullptr) { // if id already exists
        cout << "unsuccessful" << endl;
        return rootNode;
    }

    Node* insertion = new Node(trend, title_, chan, pub, t, d, v, l, dl, c, tag);

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

Node* AvlTree::insertLikes(string trend, string title_, string chan, string pub, int t, string d, long v, long l, long dl, int c, vector<string> tag, Node* rootNode) {
    Node* insertion = new Node(trend, title_, chan, pub, t, d, v, l, dl, c, tag);

    if(root == nullptr)
        root = insertion;

    if(rootNode == nullptr) {
        cout << "successful" << endl;
        return insertion;
    }
    else if (l/dl < rootNode->ratio) {
        rootNode->left = insertLikes(trend, title_, chan, pub, t, d, v, l, dl, c, tag, rootNode->left);
    }
    else if (l/dl > rootNode->ratio)
        rootNode->right = insertLikes(trend, title_, chan, pub, t, d, v, l, dl, c, tag, rootNode->right);

    // BALANCE
    int BF = findBF(rootNode);
    if (BF > 1 && l/dl < rootNode->left->ratio) // left left
        return rightRotation(rootNode);
    if (BF < -1 && l/dl > rootNode->right->ratio) // right right
        return leftRotation(rootNode);
    if (BF > 1 && l/dl > rootNode->left->ratio) { // left right
        rootNode->left = leftRotation(rootNode->left);
        return rightRotation(rootNode);
    }
    if (BF < -1 && l/dl < rootNode->right->ratio) { // right left
        rootNode->right = rightRotation(rootNode->right);
        return leftRotation(rootNode);
    }
    return rootNode;
}


Node* AvlTree::insertCom(string trend, string title_, string chan, string pub, int t, string d, long v, long l, long dl, int c, vector<string> tag, Node* rootNode) {
    Node* insertion = new Node(trend, title_, chan, pub, t, d, v, l, dl, c, tag);

    if(root == nullptr)
        root = insertion;

    if(rootNode == nullptr) {
        cout << "successful" << endl;
        return insertion;
    }
    else if (c < rootNode->comments) {
        rootNode->left = insertCom(trend, title_, chan, pub, t, d, v, l, dl, c, tag, rootNode->left);
    }
    else if (c > rootNode->comments)
        rootNode->right = insertCom(trend, title_, chan, pub, t, d, v, l, dl, c, tag, rootNode->right);

    // BALANCE
    int BF = findBF(rootNode);
    if (BF > 1 && c < rootNode->left->comments) // left left
        return rightRotation(rootNode);
    if (BF < -1 && c > rootNode->right->comments) // right right
        return leftRotation(rootNode);
    if (BF > 1 && c > rootNode->left->comments) { // left right
        rootNode->left = leftRotation(rootNode->left);
        return rightRotation(rootNode);
    }
    if (BF < -1 && c < rootNode->right->comments) { // right left
        rootNode->right = rightRotation(rootNode->right);
        return leftRotation(rootNode);
    }
    return rootNode;
}


AvlTree::AvlTree() {
    root = nullptr;
}

