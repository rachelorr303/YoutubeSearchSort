#include <iostream>
#include <iomanip>
#include <string>
#include "BST.h"

int main() {
    BST bstObj;

    int input;
    int max, min;
    string search = "";
    do {
        cout << "Welcome to the Viral Video-inator!" << endl;
        cout << "Please select one of the options below. Searches are case sensitive" << endl;
        cout << "1. Search by video title" << endl;
        cout << "2. Search by key word" << endl;
        cout << "3. Search by channel" << endl;
        cout << "4. Search for videos within a view range" << endl;
        cout << "5. Exit" << endl;

        cin >> input;
        switch (input) {
            case 1:
                cin >> search;
                bstObj.searchTitle(search, bstObj.root);
                break;
            case 2:
                cin >> search;
                bstObj.searchKey(search, bstObj.root);
                break;
            case 3:
                cin >> search;
                bstObj.searchChannel(search,bstObj.root);
                break;
            case 4:
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
