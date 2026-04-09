// greysun06 Coding 1 Spring 2026
// Vectors, Iterators, and Algorithms

#include <iostream>
#include <string>           // for getline()
#include <vector>           // for vectors and iterators
#include <algorithm>        // for find(), sort(), randum_shuffle()

using namespace std;

int main() {
    cout << "Let's learn about vectors!\n";

    string input;

    do {
        cout << "What would you like to do?\n";
        cout << "You can type 'quit', 'push', and 'find'.\n";

        getline(cin, input);        //get input from player

        if(input == "push") {
            cout << "Let's make our first vector from strings.\n";

            vector<string> names;

            // add some names with names.push_back
            names.push_back("Finn");
            names.push_back("Lady Rainicorn");
            names.push_back("Jake");
            names.push_back("The Lich");
            names.push_back("Lemongrab");

            cout << "Here are your names!\n";
            for(int i = 0; i < names.size(); i++) {
                cout << "\t" << names[i] << "\n";
            }

            cout << "There are " << names.size() << " names.\n\n";

            cout << *(names.end() - 1) << " is a dick. Let's gid rid of them.\n";

            names.pop_back();       // pop_back() removes the last element from the vector

            cout << "Here are your names!\n";
            for(int i = 0; i < names.size(); i++) {
                cout << "\t" << names[i] << "\n";
            }


        } // end of 'push'
        else if(input == "find") {
            cout << "Let's try to use the find algorithm.\n";

            // using a collection initializer to add favs at creation of vector.
            vector<string> favs = {"Star Wars", "Kill Bill", "Ponyo"};

            // building the iterator. it points to a spot in a vector
            vector<string>::iterator iter;

            cout << "Here are your favs!\n";
            for(int i = 0; i < favs.size(); i++) {
                cout << "\t" << favs[i] << "\n";
            }

            // make iter point at the virst element in the vector
            iter = favs.begin();

            // the astrisk is a "dereference operator"... so that we can get
                // the value that the iter is pointing at.
            cout << "iter is pointing at " << *iter << ".\n";

            iter += 1;

            cout << "Now iter is pointing at " << *iter << ".\n";

            cout << "What name would you lile to select?\n";
            getline(cin, input);
            // use the find algorithm
            iter = find(favs.begin(), favs.end(), "Ponyo");

            if(iter != favs.end()) {
                cout << "We've found " << *iter << "!\n";
                cout << "Would you like to change this fav?\n";
                getline(cin, input);
                if(input == "yes") {
                    cout << "What woud you like to change this fav to?\n";
                    getline(cin, input);

                    *iter = input;      // changing the fav
                }

                cout << "Here are your updated favs!\n";
                for(int i= 0; i < favs.size(); i++) {
                    cout << "\t" << favs[i] << "\n";
                }
            }
            else {
                cout << "We couldn't find that name.\n";
            }

        }
        else if(input == "quit") {
            cout << "Thanks for playing!\n";
            break;
        }

        else {
            cout << "I didn't recognize that command.\n";
        }
    } while(true);

    // create a new vector of strings

    return 0;
}