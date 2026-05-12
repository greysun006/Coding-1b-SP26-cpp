// greysun06 Coding 1 Spring 2026
// Classes Assignment

#include <iostream>
#include <string>
#include <vector>
#include <ctime>            // for random numbers
#include <cstdlib>          // for random numbers
#include <algorithm>        // for random_shuffle
#include <fstream>

using namespace std;

// this is a global vector, visible in all functions.
vector<string> names;

void read(vector<string>& vec, string path = "names.txt") {
    vec.clear();
    string line;
    ifstream readFile(path);          // opens the file
    if(readFile.is_open()) {
        cout << "The file is open.\n";
        while(getline(readFile, line)) {
            vec.push_back(line);
        }
    }
    else {
        cout << "Couldn't open that file.\n";
    }

    // after we're done with the file, close it!!
    readFile.close();

}

class slime {
private:
    string name;
    int health;
    int damage;
    int hunger;

public:
    // default constructor
    slime(string givenName, int givenHealth, int givenDamage, int givenHunger) {
        cout << "A new slime has been formed.\n";
        name = givenName;
        // names[rand() % names.size()] + " Slime";
        health = givenHealth;
        // rand() % 4 + 4;
        damage = givenDamage;
        // rand() % 3 + 3;
        hunger = givenHunger;
        // 0;
    }

    void hello() {
        cout << "I'm " << name << ", with " << health << " health ";
        cout << "and " << damage << " damage.\n";
        cout << "My hunger level is at " << hunger << ".\n";
    }

    // attack another slime
    // return true if opponent health <= 0
    bool attack(slime& opponent) {
        opponent.health -= damage;
        cout << name << " has done " << damage << " damage to ";
        cout << opponent.name << "!\n";

        if(opponent.health <= 0) {
            return true;
        }
        else {
            return false;
        }
    }

    string getName() {
        return name;
    }
    int getHealth() {
        return health;
    }
    int getDamage() {
        return damage;
    }
    int getHunger() {
        return hunger;
    }

    void setName(string givenName) {
        name = givenName;
    }
    void setHealth(int givenHealth) {
        health = givenHealth;
    }
    void setDamage(int givenDamage) {
        damage = givenDamage;
    }
    void setHunger(int givenHunger) {
        hunger = givenHunger;
    }
};

// class bossSlime : public slime {
// private:
//     int damageMultiplier = 3;
//     int healthMultiplier = 3;

// public:
//     // constructor for boss
//     bossSlime(string givenName, int givenHealth, int givenDamage, int givenHunger, int givenDamageMultiplier, int givenHealthMultiplier) {
//         // should inherit health
//         // should inherit the cout statement
//         name = givenName;
//         damage = givenDamage * givenDamageMultiplier;
//         health = givenHealth * givenHealthMultiplier;
//     }

//     // very straightforward to 'override' a function in the parent class
//     bool attack(slime& opponent) {
//         cout << "This is a boss attack!\n";
//         opponent.health -= damage;
//         cout << name << " has done " << damage << " damage to ";
//         cout << opponent.name << "!\n";
//         if(opponent.health <= 0) {
//             return true;
//         }
//         else {
//             return false;
//         }
//     }

//     void taunt() {
//         cout << "I will crush your bones with my slime!\n";
//     }

//     int getDamageMultiplier() {
//         return damageMultiplier;
//     }
//     int getHealthMultiplier() {
//         return healthMultiplier;
//     }

//     void setDamageMultiplier(int givenDamageMultiplier) {
//         damageMultiplier = givenDamageMultiplier;
//     }
//     void setHealthMultiplier(int givenHealthMultiplier) {
//         healthMultiplier = givenHealthMultiplier
//     }
// };

int main() {
    // read(names, names.txt);

    srand(time(0));

    read(names);

    string input;

    slime player(names[rand() % names.size()] + " Slime", rand() % 3 + 3, rand() % 4 + 4, 0);

    slime enemy(names[rand() % names.size()] + " Slime", rand() % 3 + 3, rand() % 4 + 4, 0);
    // bossSlime boss(names[rand() % names.size()] + " Slime", rand() % 3 + 3, rand() % 4 + 4, 0, 3, 3);

    cout << "Welcome to Slime Battles!\n";
    do {
    
    // Say commands
    cout << "You can create, name, feed, train and battle slimes!\n";
    cout << "Please enter a command. You can type 'name', 'feed', 'train', 'listen', 'battle', and 'end'.\n";

    getline(cin, input);

    // Name slime
    // else if "name"
    if(input == "name") {
        cout << "What would you like to name your slime?\n";

        // get player input
        getline(cin, input);

        // set slime name as player input
        player.setName(input);
    }

    // Train slime
    else if(input == "train") {
        if(player.getHunger() >= 10) {
            cout << player.getName() << " is too hungry to train!\n";
        }
        else if(player.getHunger() >= 5) {
            cout << player.getName() << " is getting hungry.\n";
            player.setHealth(player.getHealth() + 1);
            player.setDamage(player.getDamage() + 1);
            player.setHunger(player.getHunger() + 2);
        }
        else {
            cout << player.getName() << " is training hard!\n";
            player.setHealth(player.getHealth() + 2);
            player.setDamage(player.getDamage() + 2);
            player.setHunger(player.getHunger() + 1);
        }
    }

    // Feed slime
    else if(input == "feed") {
        if(player.getHunger() <= 0) {
            cout << player.getName() << " is completely full!\n";
        }
        cout << player.getName() << " is at " << player.getHunger() << " hunger level.\n";
        player.setHealth(player.getHealth() - player.getDamage());
        player.setHunger(player.getHunger() - 2);
    }

    // Listen to slime
    else if(input == "listen") {
        player.hello();
    }

    // Battle slime
    else if(input == "battle") {
        // enemy.setName(Timothy);
        cout << player.getName() << " is fighting " << enemy.getName() << "!\n";

        while(player.getHealth() > 0 && enemy.getHealth() > 0) {
         if(player.attack(enemy)) {
            cout << "RKO! OUT OF NOWHERE!!\n";
            cout << enemy.getName() << " has been defeated by ";
            cout << player.getName() << ".\n";
         }
         else {
             if(enemy.attack(player)) {
                cout << "Here comes " << enemy.getName() << " with a STEEL CHAIR!!\n";
                cout << player.getName() << " has been defeated by ";
                cout << enemy.getName() << ".\n";
             }
         }
     }
    }

    // End program
    else if(input == "end") {
        break;
    }

    // Unrecognized input
    else {
        cout << "I didn't recognize that input.\n";
    }

    // create a slime
    // slime gerald;
    // gerald.name = "Gerald";
    // gerald.hello();

    // bossSlime destroyer;
    // destroyer.name = "Destroyer";
    // destroyer.hello();
    // destroyer.taunt();

    // cout << "Gerald is feeling cheeky... \n";
    // gerald.attack(destroyer);

    // cout << "Destroyer is enraged!\n";
    // if(destroyer.attack(gerald)) {
    //     cout << "Gerald is no more. DED.\n";
    // }


    // create a vector of slimes
    // then pick two to fight
    // global variables

    // create a new vector of slimes with a size of 6.
    // vector<slime> sludge(6);

    // cout << "Here's our sludge of slimes:\n\n";
    // for(auto& slime : sludge) {
    //     cout << slime.name << "\n";
    // }

    // random_shuffle(sludge.begin(), sludge.end());

    // auto& a = sludge[0];        // a is equal to the first slime
    // auto& b = sludge[1];        // b is equal to the second slime

    // cout << a.name << " is fighting " << b.name << "!!!\n\n";

    // while(a.health > 0 && b.health > 0) {
    //     if(a.attack(b)) {
    //         cout << "RKO! OUT OF NOWHERE!!\n";
    //         cout << b.name << " has been defeated by ";
    //         cout << a.name << ".\n";
    //     }
    //     else {
    //         if(b.attack(a)) {
    //             cout << "Here comes " << b.name << " with a STEEL CHAIR!!\n";
    //             cout << a.name << " has been defeated by ";
    //             cout << b.name << ".\n";
    //         }
    //     }
    // }
    } while(true);
    return 0;
}