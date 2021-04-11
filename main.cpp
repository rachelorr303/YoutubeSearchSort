#include <iostream>
#include <string>

using namespace std;

int main()
{   
    string userInput;
    
    cout << "Hello World!" << endl;
    cout << "Welcome to the Viral Video-inator!" << endl;
    cout << "Please select one of the following options: " << endl;
    cout << "1. Channel Search" << endl << "2. Video Search" << endl << "3. Most popular publishing days of the week" << endl;
    cout << "4. Most popular publishing time frame" << endl << "Exit" << endl;
    
    cin >> userInput;
    
    while(userInput != "Exit"){
    
        if(userInput == "1"){
            //channel search
            
        }
        else if(userInput == "2"){
            //video search
            
        }
        else if(userInput == "3"){
            //most popular publishing days
            
        }
        else if(userInput == "4"){
            //most popular publishing time frame
            
        }
        else if(userInput == "Exit"){
            cout << "Exiting program" << endl;
        }
        else{
            cout << "Please enter appropriate input in the form of an integer" << endl;
        }
   }
    
    return 0;
}
