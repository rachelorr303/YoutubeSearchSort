#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <chrono>
using namespace std;
using namespace std::chrono;
#pragma once

class Node {
public:
    string trending;
    string title;
    string channel;
    string published;
    string time;
    string day;
    int views;
    int likes;
    int dislikes;
    int comments;
    Node *left;
    Node *right;
    Node();
    Node(string trend, string tile, string chan, string pub, string tm, string da, int v, int ls, int dls, int cc) : trending(trend), title(tile), channel(chan), published(pub), time(tm), day(da), views(v), likes(ls), dislikes(dls), comments(cc), left(nullptr), right(nullptr) {}
};

