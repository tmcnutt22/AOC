//AoC Day2

#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <string>
using namespace std;

int main(void) {
    string input = "input.txt";
    fstream newFile(input);
    string line;
    unordered_map<char, string> map;
    map['A'] = "rock";
    map['B'] = "paper";
    map['C'] = "scissors";
    map['X'] = "lose";
    map['Y'] = "draw";
    map['Z'] = "win";

    unordered_map<string, int> map2;
    map2["rock"] = 1;
    map2["paper"] = 2;
    map2["scissors"] = 3;

    int total = 0;
    while (getline(newFile, line)) {
        char c1 = line[0];
        char c2 = line[2];
        
        if (c2 == 'X') {
            //0 for loss
            if (c1 == 'A') {
                total += 3;
            } else if (c1 == 'B') {
                total += 1;
            } else {
                total += 2;
            }
            
        } else if (c2 == 'Y') {
            //3 for draw
            total += 3;
            total += map2.at(map.at(c1));
        } else if (c2 == 'Z') {
            //6 for win
            total += 6;
            if (c1 == 'A') {
                //c1 rock c2 paper
                total += 2;
            } else if (c1 == 'B') {
                //c1 paper c2 scissors
                total += 3;
            } else {
                total += 1;
            }

        }
    }

    cout << "Total: " << total << endl;
    return 0;
}



