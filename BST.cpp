//
// Created by Monique Huang on 4/17/21.
//

#include "BST.h"

BST::BST() {
    root = nullptr;
}

void BST::getStats(vector<Node*> group) {
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

 Node* BST::insert(string trend, string title, string chan, string pub, string time, string day, int views, int likes, int dislikes, int comments, Node *curr) {
    if(curr==nullptr) {
        curr = new Node(trend, title, chan, pub, time, day, views, likes, dislikes, comments);
    }
    else if(curr->title == title && curr->channel == chan) {
        Node* temp = new Node(trend, title, chan, pub, time, day, views, likes, dislikes, comments);
        curr = temp;
    }
    else if(views <= curr->views) {
        curr->left = insert(trend, title, chan, pub, time, day, views, likes, dislikes, comments, curr->left);
    }
    else if(views >= curr->views) {
        curr->right = insert(trend, title, chan, pub, time, day, views, likes, dislikes, comments, curr->right);
    }
    return curr;
}

void BST::searchTitleMenu(string title, Node *curr) {
    if (curr == nullptr) {
        return;
    }
    if(curr->title==title) {
        printInfo(curr);
    }
    searchTitleMenu(title, curr->left);
    searchTitleMenu(title, curr->right);
}

void BST::searchKey(string key, Node *curr) {
    if(curr == nullptr) {
        return;
    }
    if(curr->title.find(key) != string::npos) {
        vids.push_back(curr);
        printInfo(curr);
    }
    searchKey(key, curr->left);
    searchKey(key, curr->right);
}


void BST::searchChannel(string chan, Node *curr) {
    if(curr == nullptr) {
        return; //make sure to clear chanVids before using it again
    }
    if(curr->channel==chan) {
        vids.push_back(curr);
        printInfo(curr);
    }
    searchChannel(chan, curr->left);
    searchChannel(chan, curr->right);
}

void BST::searchByViewRange(int min, int max, Node *curr) {
    if (curr == nullptr) {
        return;
    }
    if (min <= curr->views && curr->views < max) {
        vids.push_back(curr);
    }
    searchByViewRange(min, max, curr->left);
    searchByViewRange(min, max, curr->right);
}

void BST::printInfo(Node* node) {
    //year, day, month to month, day, year
    string newT = "";
    newT = node->trending.substr(6, 2) + "/" + node->trending.substr(3, 2) + "/20" + node->trending.substr(0, 2);
    //day, month, year to month, day, year
    string newP = "";
    newP = node->published.substr(3,2) + "/" + node->published.substr(0, 2) + "/" + node->published.substr(6, 4);

    cout << node->title << " published by " << node->channel << endl;
    cout << "Views: " << node->views << endl;
    cout << "Likes: " << node->likes << endl;
    cout << "Dislikes: " << node->dislikes << endl;
    cout << "Number of comments: " << node->comments << endl;
    cout << "Published: " << node->day << " " << node->time << ", " << newP << endl; // need to format
    cout << "Trending on: " << newT << endl;
    cout << endl;
}

Node* BST::readFile() {
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
        cout << "Could not open file youtube.csv." << endl;
    }
    if(file.is_open()) {
        getline(file, read); //get rid of title line
        while(!file.fail() && i < 20) {
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
            root = insert(trending, title, channel, published, time, day, views, likes, dislikes, comments, root);
            i++;
        }
        file.close();
    }
    return root;
}


