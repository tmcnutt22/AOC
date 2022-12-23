#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <string>

using namespace std;

int main (void) {
    string input = "input.txt";
    fstream newFile(input);
    string line;
    int total = 0;
    int lines = 0;
    unordered_set<char> set;
    unordered_map<char, int> map;
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
    
    while(getline(newFile, line)) {
        int len = line.length();
        lines++;
        
        //create the set with 1st half
        for (int i = 0; i < len / 2; ++i) {
            set.insert(line[i]);
        }

        //iterate 2nd half and find the match
        for (int i = len / 2; i < len; ++i) {
            if (set.count(line[i]) > 0) {
                cout << "i = " << i << ", repeated char is : " << line[i] << endl;
                total += map[line[i]];
                break;
            }
        }
        set.clear();
    }

    cout << "Total: " << total << endl;
    return 0;
}
