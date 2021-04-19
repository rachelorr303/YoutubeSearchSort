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
    do {
        cout << "Welcome to the Viral Video-inator!" << endl;
        cout << "Please select one of the options below. Searches are case sensitive." << endl;
        cout << "1. Search by video title" << endl;
        cout << "2. Search by key word" << endl;
        cout << "3. Search by channel" << endl;
        cout << "4. Search for videos within a view range" << endl;
        cout << "5. Exit" << endl;

        cin >> input;
        switch (input) {
            case 1:
                getline(cin >> ws, search);
                bstObj.searchTitleMenu(search, bstObj.root);
                break;
            case 2:
                getline(cin >> ws, search);
                bstObj.searchKey(search, bstObj.root);
                break;
            case 3:
                getline(cin >> ws, search);
                bstObj.searchChannel(search, bstObj.root);
                break;
            case 4:
                cout << "Do not use commas." << endl;
                cout << "Input the maximum view count: ";
                cin >> max;
                cout << "Input the minimum view count: ";
                cin >> min;
                bstObj.searchByViewRange(min, max, bstObj.root);
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
