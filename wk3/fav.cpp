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
    vector<string> favGames = {"Breath of the Wild", "Ready or Not", "Space Marine 2"};

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
        else if (input == "edit") {
            // get list of inputed games
            cout << "Here are the current games in your list:\n";
            // building the iterator. it points to a spot in a vector
            vector<string>::iterator iter;

            cout << "Here are your favorite games.\n";
            for(int i = 0; i < favGames.size(); i++) {
                cout << "\t" << favGames[i] << "\n";
            }

            // make iter point at the virst element in the vector
            iter = favGames.begin();

            // choose a game
            cout << "What name would you like to select?\n";
            getline(cin, input);
            // use the find algorithm
            iter = find(favGames.begin(), favGames.end(), input);

            if(iter != favGames.end()) {
                cout << "We've found " << *iter << "!\n";
                cout << "Would you like to change this game?\n";
                getline(cin, input);
                // input new game
                if(input == "yes") {
                    cout << "What woud you like to change this game to?\n";
                    getline(cin, input);

                    *iter = input;      // changing the fav
                }
                // change the list
                cout << "Here are your updated favs!\n";
                for(int i= 0; i < favGames.size(); i++) {
                    cout << "\t" << favGames[i] << "\n";
                }
            }
            else {
                cout << "We couldn't find that name.\n";
            }
        }
        else if(input == "remove") {
            sort(favGames.begin(), favGames.end());
            cout << "Here are your favorite games!\n";
            for(int i = 0; i < favGames.size(); i++) {
                cout << favGames[i] << endl;
            }

            cout << "What game would you like to remove from this list?\n";
            getline(cin, input);

            auto iter = find(favGames.begin(), favGames.end(), input);

            if(iter != favGames.end()) {
                cout << "We've found that name. Removing now.\n";
                favGames.erase(iter);       // remove the element the iter is pointing at
            }
            
            cout << "Here are your favorite games!\n";
            for(int i = 0; i < favGames.size(); i++) {
                cout << favGames[i] << endl;
            }
        }
        else if(input == "show") {
            // sort games
            sort(favGames.begin(), favGames.end());
             cout << "Here are your favorite games!\n";
            // list games
            for(int i = 0; i < favGames.size(); i++) {
                cout << favGames[i] << endl;
            }
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