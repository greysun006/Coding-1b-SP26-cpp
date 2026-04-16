// greysun06 Coding 1 Spring 2026
// Functions


#include <iostream>
#include <string>
#include <cstdlib>          // for rand() and srand()
#include <ctime>            // 
#include <vector>

using namespace std;


// declaring and defining a new function
// the return type is void, which means it returns NOTHING
// the name of the function is "sayHello"
// the input parameters go in the parenthesis.... this function doesn't have any.
// then the code goes between the {curly braces}!
// call this function in main by typing 'sayHello();'
void sayHello() {
    cout << "Hello!\n";
}

void doAddition(int firstNum, int secondNum) {
    cout << "Our first number is " << firstNum << ".\n";
    cout << "Our second number is " << secondNum << ".\n";
    cout << "Together they make  " << firstNum + secondNum << ".\n";
}

// don't forget to include <cstdlib> and <ctime>
// this function will return an integer
int dieRoll(int sides = 6) {
    return rand() % sides + 1;
}

// create a function
// return type is bool
// name is askYesNo
// no input parameters (for now)
bool askYesNo(string question = "Do you want to keep playing?") {
    while(true) {
        cout << question << " ('yes'/'no')\n";
        string input;
        getline(cin, input);

        if(input == "yes") {
        return true;
        }
        else if(input == "no") {
        return false;
        }
        else {
        cout << "I did not understand. Please type 'yes' or 'no'.\n";
        }
    }
}

// variable scope
// global variables
// passing by reference
// #include <vector>

void showVec(vector<string>& vec) {
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }
}

// create a reference with an ampersand(&) next to the variable type
// int& number or string& name;

// references let us edit the original.
void addStringToVec(vector<string>& vec) {
    cout << "What name would you like to add?\n";
    string input;
    getline(cin, input);

    vec.push_back(input);

    // showVec(vec);       // the added name exists here.
}

int main() {
    srand(time(0));             // seed the random number generator
    vector<string> names = {"Finn", "Jake", "Marceline", "BMO", "Princess Bubblegum"};


    cout << "Finally, functions!\n";

    sayHello();

    doAddition(14, 3);

    cout << "Let's roll the dice! Our first number is " << dieRoll(6) << ".\n";

    doAddition(dieRoll(100), dieRoll(100));
    doAddition(dieRoll(), dieRoll(222));
    
    // call the askYesNo() function, and it will return true or false.
    if(askYesNo()) {
        cout << "Let's start the next level!\n";
    }
    else {
        cout << "Thanks for playing!\n";
        return 0;
    }

    if(askYesNo("Do you like Adventure Time?")) {
        cout << "Awesome! I do too!\n";
    }
    else {
        cout << "Oh, that's too bad.\n";
        return 0;
    }

    // calling the showVec() function and sending it our vector of names
    showVec(names);

    addStringToVec(names);      // try to add a string to our names vector

    showVec(names);             // notice that it DOESNT add the string to our names vector.

    return 0;
}