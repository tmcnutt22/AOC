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
    map['X'] = "rock";
    map['Y'] = "paper";
    map['Z'] = "scissors";

    unordered_map<string, int> map2;
    map2["rock"] = 1;
    map2["paper"] = 2;
    map2["scissors"] = 3;

    int total = 0;
    while (getline(newFile, line)) {
        char c1 = line[0];
        char c2 = line[2];
        if (map.at(c1) == map.at(c2)) {
            total += 3; //3 for tie
        } else if (c1 == 'A' && c2 == 'Z') {
            //rock > scissors
            //loss += 0;
        } else if (c1 == 'A') {
            //has to be rock < paper
            total += 6; //for win
        } else if (c1 == 'B' && c2 == 'X') {
            //paper > rock
        } else if (c1 == 'B') {
            //paper < scissors
            total += 6;
        } else if (c1 == 'C' && c2 == 'Y') {
        } else {
            total += 6;
        }
        total += map2.at(map.at(c2));
    }

    cout << "Total: " << total << endl;
    return 0;
}



