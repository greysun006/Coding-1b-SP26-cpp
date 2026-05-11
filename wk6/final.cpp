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
vector<string> names = {"Steve", "Walter", "Betty", "Gavin"};

// void read(vector<string>& vec, string path = "names.txt") {
//     string line;
//     ifstream readFile(path);          // input file stream
//     if(readFile.is_open()) {
//         cout << "The file is open.\n";
//         while(getline(readFile, line)) {
//             vec.push_back(line);
//         }
//     }
//     else {
//         cout << "Couldn't open that file.\n";
//     }

//     // after we're done with the file, close it!!
//     readFile.close();

// }

class baseSlime {
private:
    string name;
    int health;
    int damage;
    int hunger;

public:
    // default constructor
    baseSlime(string givenName, int givenHealth, int givenDamage, int givenHunger) {
        cout << "A new slime has been formed.\n";
        name = givenName;
        // names[rand() % names.size()] + " Slime";
        health = givenHealth;
        // rand() % 4 + 4;
        damage = givenDamage;
        // rand() % 3 + 3;
        hunger = givenHunger;
        // 0;
        hello();
    }

    // slime() {
    //     name = "ROB";
    //     health = 5;
    //     damage = 5;
    //     hunger = 5;
    //     hello();
    // }

    void hello() {
        cout << "I'm " << name << ", with " << health << " health ";
        cout << "and " << damage << " damage.\n";
        cout << "My hunger level is at " << hunger << ".\n";
    }

    // attack another slime
    // return true if opponent health <= 0
    bool attack(baseSlime& opponent) {
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

class bossSlime : public baseSlime {
private:
    int damageMultiplier = 3;
    int healthMultiplier = 3;

public:
    // constructor for boss
    bossSlime(string givenName, int givenHealth, int givenDamage, int givenHunger, int givenDamageMultiplier, int givenHealthMultiplier) {
        // should inherit health
        // should inherit the cout statement
        name = givenName;
        damage = givenDamage * givenDamageMultiplier;
        health = givenHealth * givenHealthMultiplier;
    }

    // very straightforward to 'override' a function in the parent class
    bool attack(baseSlime& opponent) {
        cout << "This is a boss attack!\n";
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

    void taunt() {
        cout << "I will crush your bones with my slime!\n";
    }

    int getDamageMultiplier() {
        return damageMultiplier;
    }
    int getHealthMultiplier() {
        return healthMultiplier;
    }

    void setDamageMultiplier(int givenDamageMultiplier) {
        damageMultiplier = givenDamageMultiplier;
    }
    void setHealthMultiplier(int givenHealthMultiplier) {
        healthMultiplier = givenHealthMultiplier
    }
};

int main() {
    // read(names, names.txt);

    srand(time(0));

    string input;

    slime rob;

    baseSlime player(names[rand() % names.size()] + " Slime", rand() % 3 + 3, rand() % 4 + 4, 0);

    bossSlime boss(names[rand() % names.size()] + " Slime", rand() % 3 + 3, rand() % 4 + 4, 0, 3, 3);

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
        player.name = input;
    }

    // Train slime
    else if(input == "train") {
        if(player.hunger >= 10) {
            cout << player.name << " is too hungry to train!\n";
        }
        else if(player.hunger >= 5) {
            cout << player.name << " is getting hungry.\n";
            player.health += 1;
            player.damage += 1;
            player.hunger += 2;
        }
        else {
            cout << player.name << " is training hard!\n";
            player.health += 2;
            player.damage += 2;
            player.hunger += 1;
        }
    }

    // Feed slime
    else if(input == "feed") {
        cout << player.name << " is at " << player.hunger << " hunger level.\n";

        player.hunger += -2;
    }

    // Listen to slime
    else if(input == "listen") {
        player.hello();
    }

    // Battle slime
    else if(input == "battle") {
        boss.name = "Destroyer";
        cout << player.name << " is fighting " << boss.name << "!\n";
        boss.taunt();

        while(player.health > 0 && boss.health > 0) {
         if(player.attack(boss)) {
            cout << "RKO! OUT OF NOWHERE!!\n";
            cout << boss.name << " has been defeated by ";
            cout << player.name << ".\n";
         }
         else {
             if(boss.attack(player)) {
                cout << "Here comes " << boss.name << " with a STEEL CHAIR!!\n";
                cout << player.name << " has been defeated by ";
                cout << boss.name << ".\n";
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
    // baseSlime gerald;
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
    // vector<baseSlime> sludge(6);

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