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

void AvlTree::searchTitle(string t, Node* node) {
    if(node == nullptr) {
        //cout << "Title not found" << endl;
        return;
    }
    if(node->title == t) {
        printInfo(node);
    }
    searchTitle(t, node->left);
    searchTitle(t, node->right);
}

void AvlTree::searchWord(string key, Node* node){
    if(node == nullptr)
        return;
    else if(node->title.find(key) != string::npos) {
        vids.push_back(node);
    }
    searchWord(key, node->left);
    searchWord(key, node->right);
}

void AvlTree::searchChannel(string chan, Node* node) {
    if(node == nullptr)
        return;
    else if(node->channel == chan)
        vids.push_back(node);
    searchChannel(chan, node->left);
    searchChannel(chan, node->right);
}

void AvlTree::searchViews(int min, int max, Node* node) {
    if(node == nullptr)
        return;
    else if(node->views < max && node->views > min)
        vids.push_back(node);
    searchViews(max, min, node->left);
    searchViews(max, min, node->right);
}

bool AvlTree::titleExist(string title_, Node* node) {
    if(node == nullptr)
        return false;
    if(node->title == title_)
        return true;
    bool res1 = titleExist(title_, node->left);
    if(res1)
        return true;
    return titleExist(title_, node->right);
}

Node* AvlTree::insertViews(string trend, string title_, string chan, string pub, string t, string d, long v, long l, long dl, int c, Node* rootNode){
    //bool found = false;
    //searchTitle(title_, rootNode, found);
    if(titleExist(title_, rootNode)) { // check if title already exists
        //cout << "Video already exists" << endl;
        return rootNode;
    }
    if(rootNode == nullptr) {
        //cout << "successful" << endl;
        return new Node(trend, title_, chan, pub, t, d, v, l, dl, c);;
    }
    if (v <= rootNode->views) { // should i do <= ??
        rootNode->left = insertViews(trend, title_, chan, pub, t, d, v, l, dl, c, rootNode->left);
    }
    else
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
    cout << "\n" << endl;
}

void AvlTree::getStats(vector<Node*> group) {
    cout << "Stats for " << group.size() << " videos:" << endl;
    long avgViews = 0;
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

    cout << "Like to dislike ratio: " << avgLikes/avgDislikes << ":1" << endl;

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

Node* AvlTree::readFile() {
    string read;
    string data;
    string trending;
    string title;
    string channel;
    string published;
    string time;
    string day;
    int views = 0;
    int likes = 0;
    int dislikes = 0;
    int comments = 0;
    int hour;
    int i = 1;
    if(!file.is_open()) {
        cout << "Could not open file youtube.tsv." << endl;
    }
    if(file.is_open()) {
        getline(file, read); //get rid of title line
        while(!file.fail() && i < 100000) {
            getline(file, read);
            istringstream stream(read);

            //Trending date
            getline(stream, data, '\t');
            trending = data;

            //Title
            getline(stream, data, '\t');
            title = data;

            //Channel Name
            getline(stream, data, '\t');
            channel = data;

            //Published date
            getline(stream, data, '\t');
            published = data;

            //Time frame
            getline(stream, data, ':');
            try {
                hour = stoi(data);
                if(5 <= hour && hour <= 12) {
                    time = "morning";
                }
                else if(13 <= hour && hour <= 17) {
                    time = "afternoon";
                }
                else if((18 <= hour && hour <= 23) || (0 <= hour && hour <= 4)) {
                    time = "night";
                }
            }
            catch(exception &err) {
                cout << i << endl;
                cout << "Failed to convert time of day to an int." << endl;
            }

            getline(stream, data, '\t'); //move on from time of day section

            //Published day
            getline(stream, data, '\t');
            day = data;

            //views
            getline(stream, data, '\t');
            try {
                views = stoi(data);
            }
            catch(exception &err) {
                cout << i << endl;
                cout << "Failed to convert views to an int." << endl;
            }

            //likes
            getline(stream, data, '\t');
            try {
                likes = stoi(data);
            }
            catch(exception &err) {
                cout << i << endl;
                cout << "Failed to convert likes to an int." << endl;
            }

            //dislikes
            getline(stream, data, '\t');
            try {
                dislikes = stoi(data);
            }
            catch(exception &err) {
                cout << i << endl;
                cout << "Failed to convert dislikes to an int." << endl;
            }

            //comments
            getline(stream, data, '\t');
            try {
                comments = stoi(data);
            }
            catch(exception &err) {
                cout << i << endl;
                cout << "Failed to convert comments to an int." << endl;
            }

            //insertion here
            root = insertViews(trending, title, channel, published, time, day, views, likes, dislikes, comments, root);
            i++;
        }
        file.close();
    }
    return root;
}