
#include <iostream>
#include <fstream>
#include <istream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;


int main()
{
    cout << "This is the basic parsing info" << endl;
    
    //this is where we open the file, made sure it is in csv comma deliminated format
    ifstream file;
    file.open("YouTubeData.csv", ios::in );


    //basic variables
    string header;
    string singleLine;
    string delimiter = ",";
    vector<string> vidID;
    vector<string> trendingDate;
    vector<string> title;
    vector<string> channelTitle;
    vector<string> categoryID;
    vector<string> pubishDate;
    vector<string> timeFrame;
    vector<string> dayOfWeek;
    vector<string> country;
    vector<string> tags;
    vector<string> views;
    vector<string> likes;
    vector<string> dislikes;
    vector<string> commentsNum;
    vector<string> commentsDisabled;
    vector<string> ratingsDisabled;
    vector<string> vidErrorRemoved;



    if (file.is_open()) {
        cout << "opened file" << endl;
        
        //reading the header
        getline(file, header);
        
        //go through all the data and add it to the vectors
        while (getline(file, singleLine)) {
            vidID.push_back(singleLine.substr(0, singleLine.find(delimiter)));
            singleLine.erase(0, singleLine.find(delimiter) + delimiter.length());

            trendingDate.push_back(singleLine.substr(0, singleLine.find(delimiter)));
            singleLine.erase(0, singleLine.find(delimiter) + delimiter.length());
            
            title.push_back(singleLine.substr(0, singleLine.find(delimiter)));
            singleLine.erase(0, singleLine.find(delimiter) + delimiter.length());
            
            channelTitle.push_back(singleLine.substr(0, singleLine.find(delimiter)));
            singleLine.erase(0, singleLine.find(delimiter) + delimiter.length());

            categoryID.push_back(singleLine.substr(0, singleLine.find(delimiter)));
            singleLine.erase(0, singleLine.find(delimiter) + delimiter.length());

            pubishDate.push_back(singleLine.substr(0, singleLine.find(delimiter)));
            singleLine.erase(0, singleLine.find(delimiter) + delimiter.length());

            timeFrame.push_back(singleLine.substr(0, singleLine.find(delimiter)));
            singleLine.erase(0, singleLine.find(delimiter) + delimiter.length());

            dayOfWeek.push_back(singleLine.substr(0, singleLine.find(delimiter)));
            singleLine.erase(0, singleLine.find(delimiter) + delimiter.length());

            country.push_back(singleLine.substr(0, singleLine.find(delimiter)));
            singleLine.erase(0, singleLine.find(delimiter) + delimiter.length());

            tags.push_back(singleLine.substr(0, singleLine.find(delimiter)));
            singleLine.erase(0, singleLine.find(delimiter) + delimiter.length());

            views.push_back(singleLine.substr(0, singleLine.find(delimiter)));
            singleLine.erase(0, singleLine.find(delimiter) + delimiter.length());

            likes.push_back(singleLine.substr(0, singleLine.find(delimiter)));
            singleLine.erase(0, singleLine.find(delimiter) + delimiter.length());

            dislikes.push_back(singleLine.substr(0, singleLine.find(delimiter)));
            singleLine.erase(0, singleLine.find(delimiter) + delimiter.length());

            commentsNum.push_back(singleLine.substr(0, singleLine.find(delimiter)));
            singleLine.erase(0, singleLine.find(delimiter) + delimiter.length());

            commentsDisabled.push_back(singleLine.substr(0, singleLine.find(delimiter)));
            singleLine.erase(0, singleLine.find(delimiter) + delimiter.length());

            ratingsDisabled.push_back(singleLine.substr(0, singleLine.find(delimiter)));
            singleLine.erase(0, singleLine.find(delimiter) + delimiter.length());

            vidErrorRemoved.push_back(singleLine.substr(0, singleLine.find(delimiter)));
            singleLine.erase(0, singleLine.find(delimiter) + delimiter.length());
        }
        //after exiting this loop, the vectors should be completely full with all of the data from YouTubeData
        file.close();
    }


}
