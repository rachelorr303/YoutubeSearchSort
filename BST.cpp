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

void BST::insertByViews(Node* insert, Node *curr) {
    if(curr==nullptr) {
        curr = insert;
        return;
    }
    else if(insert->views <= curr->views) {
        insertByViews(insert, curr->left);
    }
    else if(insert->views > curr->views) {
        insertByViews(insert, curr->right);
    }
}

Node* BST::searchTitle(string &title, int &views, Node *curr) {
    Node* temp;
    if (curr == nullptr) {
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
        //print function
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
    int hour;
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
            getline(stream, data, ':');
            try {
                hour = stoi(data);
                if(5 <= hour && hour <= 12) {
                    curr->time = "morning";
                }
                else if(13 <= hour && hour <= 17) {
                    curr->time = "afternoon";
                }
                else if((18 <= hour && hour <= 23) || (0 <= hour && hour <= 4)) {
                    curr->time = "night";
                }
            }
            catch(exception &err) {
                cout << "Failed to convert time of day to an int." << endl;
            }
            getline(stream, data, ','); //move on from time of day section

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
            if(searchTitle(curr->title, curr->views, root) == nullptr) { //node doesn't exist in tree
                insertByViews(curr, root);
                //delete curr;
            }
        }
        file.close();
    }
}


