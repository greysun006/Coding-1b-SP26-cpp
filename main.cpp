// greysun06 Coding 1 Spring 2026
// My first C++ Program

#include <iostream>         // in out stream, for sending texts to the console.
#include <string>           // for playerName

using namespace std;        // so we don't have to type "std::" all the time.

// here is where we start the program
int main() {
    // variables at the top is best practice.
    string playerName;      // variables use camelCase

    // ask the player for their name
    cout << "What is your name, player? ";

    // assign whatever the player types as the value of playerName
    cin >> playerName;

    // greet the player by name
    cout << "Hello " <<playerName << "." << endl;

    // user Control+slash to comment out lines
    // cout << "Hello World!" << endl;             // cout = console out, endl = end line

    return 0;               // end the program
}