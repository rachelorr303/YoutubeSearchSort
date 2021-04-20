#include <iostream>
#include <string>
#include "BST.h"
#include "AVL.h"

int main() {
    BST bstObj;
    AvlTree avlObj;
    int input;
    int max, min;
    string search;


    cout << "Welcome to the Viral Video-inator!" << endl;
    cout << "Please select one of the options below." << endl;
    cout << "1. Build the AVL and Binary Search Tree to store the dataset." << endl;
    cout << "2. Exit program." << endl;
    cin >> input;
    if(input==1) {
        auto start1 = high_resolution_clock::now();
        avlObj.file.open("/Users/moniquehuang/CLionProjects/BST/youtube.tsv");
        avlObj.root = avlObj.readFile();
        auto stop1 = high_resolution_clock::now();
        auto time1 = duration_cast<microseconds>(stop1-start1);
        cout << "Time taken to build the AVL Tree: " << time1.count() << " microseconds." << endl;
        cout << endl;

        auto start2 = high_resolution_clock::now();
        bstObj.file.open("/Users/moniquehuang/CLionProjects/BST/youtube.tsv");
        bstObj.root = bstObj.readFile();
        auto stop2 = high_resolution_clock::now();
        auto time2 = duration_cast<microseconds>(stop2-start2);
        cout << "Time taken to build the Binary Search Tree: " << time2.count() << " microseconds." << endl;
        cout << endl;
    }
    if(input==2) {
        return 0;
    }

    do {
        cout << "Please select one of the options below. Searches are case sensitive." << endl;
        cout << "1. Search by video title" << endl;
        cout << "2. Search by key word" << endl;
        cout << "3. Search by channel" << endl;
        cout << "4. Search for videos within a view range" << endl;
        cout << "5. Exit" << endl;

        cin >> input;
        if(input==1) {
            cout << "Enter video title: ";
            cout << endl;
            getline(cin >> ws, search);
            cout << "AVL Tree Search: " << endl;
            auto start1 = high_resolution_clock::now();
            avlObj.searchTitle(search, avlObj.root);
            auto stop1 = high_resolution_clock::now();
            auto time1 = duration_cast<microseconds>(stop1 - start1);
            cout << "Time taken to search the title: " << time1.count() << " microseconds." << endl;
            cout << endl;

            cout << "Binary Tree Search: " << endl;
            auto start2 = high_resolution_clock::now();
            bstObj.searchTitle(search, bstObj.root);
            auto stop2 = high_resolution_clock::now();
            auto time2 = duration_cast<microseconds>(stop2 - start2);
            cout << "Time taken to search the title: " << time2.count() << " microseconds." << endl;
            cout << endl;
        }
        else if(input==2) {
            cout << "Enter keyword: ";
            getline(cin >> ws, search);
            cout << endl;
            cout << "AVL Tree Search: " << endl;
            auto start1 = high_resolution_clock::now();
            avlObj.searchWord(search, avlObj.root);
            if (!avlObj.vids.empty()) {
                avlObj.getStats(avlObj.vids);
                avlObj.vids.clear();
            } else {
                cout << "No videos were found with " << search << " in the title." << endl;
            }
            auto stop1 = high_resolution_clock::now();
            auto time1 = duration_cast<microseconds>(stop1-start1);
            cout << "Time taken to search the keyword: " << time1.count() << " microseconds." << endl;
            cout << endl;

            cout << "Binary Tree Search: " << endl;
            auto start2 = high_resolution_clock::now();
            bstObj.searchKey(search, bstObj.root);
            if (!bstObj.vids.empty()) {
                bstObj.getStats(bstObj.vids);
                bstObj.vids.clear();
            } else {
                cout << "No videos were found with " << search << " in the title." << endl;
            }
            auto stop2 = high_resolution_clock::now();
            auto time2 = duration_cast<microseconds>(stop2 - start2);
            cout << "Time taken to search the keyword: " << time2.count() << " microseconds." << endl;

            cout << endl;
        }
        else if(input==3) {
            cout << "Enter channel name: ";
            getline(cin >> ws, search);
            cout << endl;
            cout << "AVL Tree Search: " << endl;
            auto start1 = high_resolution_clock::now();
            avlObj.searchChannel(search, avlObj.root);
            if (!avlObj.vids.empty()) {
                avlObj.getStats(avlObj.vids);
                avlObj.vids.clear();
            } else {
                cout << "No channels were found under the name " << search << "." << endl;
            }
            auto stop1 = high_resolution_clock::now();
            auto time1 = duration_cast<microseconds>(stop1-start1);
            cout << "Time taken to search the channel name: " << time1.count() << " microseconds." << endl;
            cout << endl;

            cout << "Binary Tree Search: " << endl;
            auto start2 = high_resolution_clock::now();
            bstObj.searchChannel(search, bstObj.root);
            if (!bstObj.vids.empty()) {
                bstObj.getStats(bstObj.vids);
                bstObj.vids.clear();
            } else {
                cout << "No channels were found under the name " << search << "." << endl;
            }
            auto stop2 = high_resolution_clock::now();
            auto time2 = duration_cast<microseconds>(stop2 - start2);
            cout << "Time taken to search the channel name: " << time2.count() << " microseconds." << endl;
            cout << endl;
        }
        else if(input==4) {
            cout << "Input the maximum view count: ";
            cin >> max;
            cout << "Input the minimum view count: ";
            cin >> min;
            cout << endl;
            cout << "AVL Tree Search: " << endl;
            auto start1 = high_resolution_clock::now();
            avlObj.searchViews(min, max, avlObj.root);
            if (!avlObj.vids.empty()) {
                avlObj.getStats(avlObj.vids);
                avlObj.vids.clear();
            } else {
                cout << "No videos are within the range " << min << " and " << max << "." << endl;
            }
            auto stop1 = high_resolution_clock::now();
            auto time1 = duration_cast<microseconds>(stop1-start1);
            cout << "Time taken to search the view range: " << time1.count() << " microseconds." << endl;
            cout << endl;

            cout << "Binary Tree Search: " << endl;
            auto start2 = high_resolution_clock::now();
            bstObj.searchViews(min, max, bstObj.root);
            if (!bstObj.vids.empty()) {
                bstObj.getStats(bstObj.vids);
                bstObj.vids.clear();
            } else {
                cout << "No videos are within the range " << min << " and " << max << "." << endl;
            }
            auto stop2 = high_resolution_clock::now();
            auto time2 = duration_cast<microseconds>(stop2 - start2);
            cout << "Time taken to search the view range: " << time2.count() << " microseconds." << endl;
            cout << endl;
        }
        else if(input==5) {
            cout << "Goodbye!" << endl;
            return 0;
        }
        else {
            cout << "Invalid input." << endl;
        }
    }
    while(input !=5);


    return 0;
}
