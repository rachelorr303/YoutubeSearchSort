#include <iostream>
#include <string>
#include "BST.h"
#include "AVL.h"

int main() {
    BST bstObj;
    AvlTree avlObj;
    int input;
    int max, min;

    avlObj.file.open("/Users/moniquehuang/CLionProjects/BST/youtube.tsv");
    avlObj.root = avlObj.readFile();
    //bstObj.file.open("/Users/moniquehuang/CLionProjects/BST/youtube.tsv");
    //bstObj.root = bstObj.readFile();
    string search;

    cout << "Welcome to the Viral Video-inator!" << endl;
    do {
        cout << "Please select one of the options below. Searches are case sensitive." << endl;
        cout << "1. Search by video title" << endl;
        cout << "2. Search by key word" << endl;
        cout << "3. Search by channel" << endl;
        cout << "4. Search for videos within a view range" << endl;
        cout << "5. Exit" << endl;

        cin >> input;
        switch (input) {
            case 1:
                cout << "Enter video title: ";
                getline(cin >> ws, search);
                cout << "AVL Tree Search: " << endl;
                avlObj.searchTitle(search, avlObj.root);
                //cout << "Binary Tree Search: " << endl;
                //bstObj.searchTitle(search, bstObj.root);
                break;
            case 2:
                cout << "Enter keyword: ";
                getline(cin >> ws, search);
                cout << "AVL Tree search: " << endl;
                avlObj.searchWord(search, avlObj.root);
                //bstObj.searchKey(search, bstObj.root);
                if(!avlObj.vids.empty()) {
                    avlObj.getStats(avlObj.vids);
                    avlObj.vids.clear();
                }
                else {
                    cout << "No videos were found with " << search << " in the title." << endl;
                }
                /*if(!bstObj.vids.empty()) {
                    bstObj.getStats(bstObj.vids);
                    bstObj.vids.clear();
                }
                else {
                    cout << "No videos were found with " << search << " in the title." << endl;
                }*/
                cout << endl;
                break;
            case 3:
                cout << "Enter channel name: ";
                getline(cin >> ws, search);
                avlObj.searchChannel(search, avlObj.root);
                //bstObj.searchChannel(search, bstObj.root);
                if(!avlObj.vids.empty()) {
                    avlObj.getStats(avlObj.vids);
                    avlObj.vids.clear();
                }
                else {
                    cout << "No channels were found under the name " << search << "." << endl;
                }
                cout << endl;
                break;
            case 4:
                cout << "Input the maximum view count: ";
                cin >> max;
                cout << "Input the minimum view count: ";
                cin >> min;
                avlObj.searchViews(max, min, avlObj.root);
                if(!avlObj.vids.empty()) {
                    avlObj.getStats(avlObj.vids);
                    avlObj.vids.clear();
                }
                else {
                    cout << "No videos are within the range " << min << " and " << max << "." << endl;
                }
                /*bstObj.searchByViewRange(min, max, bstObj.root);
                if(!bstObj.vids.empty()) {
                    bstObj.getStats(bstObj.vids);
                    bstObj.vids.clear();
                }
                else {
                    cout << "No videos are within the range " << min << " and " << max << "." << endl;
                }*/
                cout << endl;
                break;
            case 5:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                return 0;
        }
    }
    while(input !=5);
    
    auto start = high_resolution_clock::now();
    //code
    auto stop = high_resolution_clock::now();
    auto time = duration_cast<microseconds>(stop-start);
    cout << "Time taken to insert: " << time.count() << " microseconds" << endl;


    return 0;
}
