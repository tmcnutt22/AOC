#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

int main (void) {
    std::string input = "input.txt";
    std::fstream newFile(input);
    std::vector<std::string> list;
    std::string line;
    std::unordered_map<char, int> map;
    int total = 0;
    //create the unordered_map
    map['a'] = 1;
    map['b'] = 2;
    map['c'] = 3;
    map['d'] = 4;
    map['e'] = 5;
    map['f'] = 6;
    map['g'] = 7;
    map['h'] = 8;
    map['i'] = 9;
    map['j'] = 10;
    map['k'] = 11;
    map['l'] = 12;
    map['m'] = 13;
    map['n'] = 14;
    map['o'] = 15;
    map['p'] = 16;
    map['q'] = 17;
    map['r'] = 18;
    map['s'] = 19;
    map['t'] = 20;
    map['u'] = 21;
    map['v'] = 22;
    map['w'] = 23;
    map['x'] = 24;
    map['y'] = 25;
    map['z'] = 26;
    map['A'] = 27;
    map['B'] = 28;
    map['C'] = 29;
    map['D'] = 30;
    map['E'] = 31;
    map['F'] = 32;
    map['G'] = 33;
    map['H'] = 34;
    map['I'] = 35;
    map['J'] = 36;
    map['K'] = 37;
    map['L'] = 38;
    map['M'] = 39;
    map['N'] = 40;
    map['O'] = 41;
    map['P'] = 42;
    map['Q'] = 43;
    map['R'] = 44;
    map['S'] = 45;
    map['T'] = 46;
    map['U'] = 47;
    map['V'] = 48;
    map['W'] = 49;
    map['X'] = 50;
    map['Y'] = 51;
    map['Z'] = 52;

    while (getline(newFile, line)) {
        list.push_back(line);
    }

    for (int i = 0; i < list.size(); i += 3) {
        //add all chars from index i
        std::unordered_set<char> set1;
        std::string s1 = list.at(i);
        for (int j = 0; j < s1.length(); j++) {
            set1.insert(s1[j]);
        }
        //create a list for any char that occurs in both
        std::unordered_set<char> set2;
        std::string s2 = list.at(i + 1);
        for (int k = 0; k < s2.length(); k++) {
            char c = s2[k];
            if (set1.count(c) != 0) {
                set2.insert(c);
            }
        }
        //iterate the last string (i + 2) and return the value from the map
        std::string s3 = list.at(i + 2);
        for (int l = 0; l < s3.length(); l++) {
            char c3 = s3[l];
            if (set2.count(c3) != 0) {
                total += map[c3]; 
                break;
            }
        }
    }

    std::cout << "Total: " << total << std::endl;
    return 0;
}

