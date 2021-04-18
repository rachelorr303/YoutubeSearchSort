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
BST::insertByViews(string &trend, string &title, string &chan, string &pub, int &time, string &day, int &v, int &ls, int &dls,
            int &cc, Node* curr) {
    if(searchTitle(title, v, curr) == nullptr) {
        if(curr == nullptr) { //current node is empty or its root of tree
            curr = new Node(trend, title, chan, pub, time, day, v, ls, dls, cc);
            return curr;
        }
        else if(curr->views > v){ //store new node in left subtree
            curr->left = insertByViews(trend, title, chan, pub, time, day, v, ls, dls, cc, curr->left);
        }
        else if(curr->views < v){ //store new node in right subtree
            curr->right = insertByViews(trend, title, chan, pub, time, day, v, ls, dls, cc, curr->right);
        }
    }
    return curr;
}

Node* BST::searchTitle(string &title, int &views, Node *curr) {
    Node* temp;
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

void BST::searchTitle(string &title, Node * curr) {
    string temp;
    if (curr == nullptr) {
        return;
    }
    if(curr->title.compare(title)==0) {

    }
    else {
        searchTitle(title, curr->left);
        searchTitle(title, curr->right);
    }

}

void BST::searchKey(string &key, Node *curr) {
    if(curr == nullptr) {
        return;
    }
    else if(curr->title.find(key) != string::npos) {

    }
}


void BST::searchChannel(string &chan, Node *curr) {
    if(curr == nullptr) {
        return; //make sure to clear chanVids before using it again
    }
    else if(curr->channel==chan) {
        chanVids.push_back(curr);
    }
    else {
        searchChannel(chan, curr->left);
        searchChannel(chan, curr->right);
    }
}

void BST::searchByViewRange(int &min, int &max, Node *curr) {
    if (curr == nullptr) {
        return;
    } else if (min <= curr->views && curr->views < max) {
        viewsRange.push_back(curr);
    } else {
        searchByViewRange(min, max, curr->left);
        searchByViewRange(min, max, curr->right);
    }
}

void BST::readFile() {
    string read;
    string data;
    Node *curr = new Node();
    if(!file.is_open()) {
        cout << "Could not open file youtube.csv." << endl;
    }
    if(file.is_open()) {
        getline(file, read); //get rid of title line
        while(!file.fail()) {
            getline(file, read);
            istringstream stream(read);

            //Trending date
            getline(stream, data, ',');
            curr->trending = data;

            //Title
            getline(stream, data, ',');
            curr->title = data;

            //Channel Name
            getline(stream, data, ',');
            curr->channel = data;

            //Published date
            getline(stream, data, ',');
            curr->published = data;

            //Time frame
            getline(stream, data, ',');
            curr->time = data;

            //Published day
            getline(stream, data, ',');
            curr->day = data;

            //views
            getline(stream, data, ',');
            try {
                curr->views = stoi(data);
            }
            catch(exception &err) {
                cout << "Failed to convert views to an int." << endl;
            }

            //likes
            getline(stream, data, ',');
            try {
                curr->likes = stoi(data);
            }
            catch(exception &err) {
                cout << "Failed to convert likes to an int." << endl;
            }

            //dislikes
            getline(stream, data, ',');
            try {
                curr->dislikes = stoi(data);
            }
            catch(exception &err) {
                cout << "Failed to convert dislikes to an int." << endl;
            }

            //comments
            getline(stream, data, ',');
            try {
                curr->comments = stoi(data);
            }
            catch(exception &err) {
                cout << "Failed to convert comments to an int." << endl;
            }

            //insertion here
        }
        file.close();
    }
}


