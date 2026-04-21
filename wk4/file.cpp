// greysun06 Coding 1 Spring 2026
// Writing to and reading from files

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;


void read(string path = "save.txt") {
    string line;
    ifstream readFile(path);          // input file stream
    if(readFile.is_open()) {
        cout << "The file is open.\n";
        while(getline(readFile, line)) {
            cout << line << endl;
        }
    }
    else {
        cout << "Couldn't open that file.\n";
    }

    // after we're done with the file, close it!!
    readFile.close();
}

void read(vector<string>& vec, string path = "save.txt") {
    string line;
    ifstream readFile(path);          // input file stream
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

void write(vector<string>& vec, string path = "save.txt") {
    cout << "Starting write() function.\n";
    ofstream writeFile(path);

    if(writeFile.is_open()) {
        for(int i = 0; i < vec.size(); i++) {
            writeFile << vec[i] << endl;
        }
    }
    else {
        cout << "Couldn't open new writeFile.\n";
    }

    writeFile.close();
    cout << "end of write() function.\n";
}

int main() {
    cout << "Let's write to a file!\n";
    vector<string> favs;
    string input = "asdf";

    string path = "save.txt";

    cout << "What file would you like to open?\ntype 'no' to use default.\n";
    getline(cin, input);
    if(input != "no") {
        path = input;           // this let's us open different files!!!       
    }

    read(path);                     // show the current names
    read(favs, path);                 // add the names to the vector

    cout << "What names would you like?\n";
    cout << "enter an empty line to stop.\n";


    while(input != "") {
        cout << "> ";
        getline(cin, input);
        if(input == "") {
            break;          // stop before we add "" to the vector
        }
        // send to file
        // writeFile << input << endl;
        favs.push_back(input);
    }

    // now call the write function and send it our favs vector
    write(favs, path);

    return 0;
}