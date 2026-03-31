// greysun06 Coding 1 Spring 2026
// Variables and Logic

// compile with the Developer Command Prompt
// 'cl /EHsc main.cpp' is what you type to compile
// 'main' or 'main.exe' to run the program.

#include <iostream>
using namespace std;

int main() {
    cout << "Let's learn about variables and logic!\n";

    // declaring and defining variables
    int playerAge = -1;
    string playerName = "Darth Vader";
    float happinessPercent = 0.61f;
    bool keepPlaying = true;

    // just like a branch in unreal engine
    // if (the test is true) run this code.
    if(playerAge == -1) {
        cout << "How old are you?\n";
        cin >> playerAge;

        if(playerAge <= 12) {
            cout << "I'm sorry, this game is for grownups!\n";
            return 0;       // quit the game early
        }
        else {
            cout << "Wow, " <<playerAge << " years, you're really old!\n";
        }
    } //end of if(playerAge)

    if(playerName == "Darth Vader") {
        cout << "Is your name " << playerName << "?\n";
        string input;       // create a new string variable to keep track of user input
        cin >> input;       // get the user input

        // the OR operator '||' means that if any test evaluates to true, the if statement is true.
        if(input == "yes" || input == "Yes" || input == "YES") {
            cout << "Well, that's concenient! \n";
        }
        else {
            cout << "Oh! Well, what is your name?\n";
            cin >> playerName;
        }

        cout << "Hello " << playerName << ".\n";
    } // end of if(playerName)

    bool debug = false;     // turn this on to debug the program

    // the AND operator '&&' requires that all tests are true.
    if(playerAge == 19 && playerName == "Grayson") {
        debug += true;
        cout << "Hello Creator. Debug mode is ON.\n";

    } // end of if(age && name)

    if(debug == true) {
        cout << "\n\tDEBUG MODE\n\n";
        cout << "playerAge = " << playerAge << ".\n";
        cout << "playerName = " << playerName << ".\n";
        cout << "happinessPercent = " << happinessPercent << ".\n";
        cout << "keepPlaying = " <<keepPlaying << ".\n";
    }

    return 0;
} // end of main()