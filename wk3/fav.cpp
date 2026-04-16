// greysun06 Coding 1 Spring 2026
// Fav Games Assignment

// Create a .cpp program that will allow the user to
// 'add' a game
// 'edit' a game
// 'remove' a game
// 'show' all games (sorted)
// 'quit'.

// use vectors and iterators and algorithms to do so.
// use pseudocode to organize your thoughts.
// show the available commands to the user
    // at the top of each loop.
// the games do not need tot save between launches of the program.
// the user should type the command they want to use as a word

// Due Monday Night, April 20th
// turning in a .cpp file to blackboard.

#include <iostream>
#include <string>           // for getline()
#include <vector>           // for vectors and iterators
#include <algorithm>        // for find(), sort(), randum_shuffle()

using namespace std;

int main() {
    cout << "Let's see your favorite games!\n";

    // empty vector<string>
    vector<string> favGames;

    string input;

    // do while loop
    do {
        // give users options to do something
        cout << "What would you like to do?\n";
        cout << "You can type 'add', 'edit', 'remove', 'show', and 'quit'.\n";

        getline(cin, input);        //get input from player

        // 'add' a game if()
        if (input == "add") {
            // ask the player what they want to add
            cout << "What game would you like to add?\n";
            // get player input
            getline(cin, input);
            // add player input to list
            favGames.push_back(input);
        }
        // 'edit' a game else if()
        else of (input == "edit") {
            // get list of inputed games
            cout << "Here are the current games in your list:\n";
            
            // choose a game
            // input new game
            // change the list

        }
        // 'quit'. else if() w/ break;
        else if(input == "quit") {
            cout << "Thanks for playing!\n";
            break;
        }

        // command not recognized else
        else {
            cout << "I didn't recognize that command.\n";
        }
    } while(true);

        // 'remove' a game else if()
        // 'show' all games (sorted) else if()

    return 0;
}