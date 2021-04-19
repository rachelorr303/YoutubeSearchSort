#include <iostream>
#include <string>
#include "BST.h"

int main() {
    BST bstObj;
    int input;
    int max, min;

    bstObj.file.open("/Users/moniquehuang/CLionProjects/BST/youtube.tsv");
    bstObj.root = bstObj.readFile();
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
                bstObj.searchTitleMenu(search, bstObj.root);
                break;
            case 2:
                cout << "Enter keyword: ";
                getline(cin >> ws, search);
                bstObj.searchKey(search, bstObj.root);
                if(!bstObj.vids.empty()) {
                    bstObj.getStats(bstObj.vids);
                    bstObj.vids.clear();
                }
                else {
                    cout << "No videos were found with " << search << " in the title." << endl;
                }
                cout << endl;
                break;
            case 3:
                cout << "Enter channel name: ";
                getline(cin >> ws, search);
                bstObj.searchChannel(search, bstObj.root);
                if(!bstObj.vids.empty()) {
                    bstObj.getStats(bstObj.vids);
                    bstObj.vids.clear();
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
                bstObj.searchByViewRange(min, max, bstObj.root);
                if(!bstObj.vids.empty()) {
                    bstObj.getStats(bstObj.vids);
                    bstObj.vids.clear();
                }
                else {
                    cout << "No videos are within the range " << min << " and " << max << "." << endl;
                }
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


    return 0;
}
