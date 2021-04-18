#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    string trending;
    string title;
    string channel;
    string published;
    int time;
    string day;
    vector<string> tags;
    int views;
    int likes;
    int dislikes;
    int comments;
    Node *left;
    Node *right;
    Node();
    Node(string trend, string tile, string chan, string pub, int tm, string da, vector<string> tgs, int v, int ls, int dls, int cc) : trending(trend), title(tile), channel(chan), published(pub), time(tm), day(da), tags(tgs), views(v), likes(ls), dislikes(dls), comments(cc) {}
};
