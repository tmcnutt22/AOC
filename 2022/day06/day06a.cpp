#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
#include <unordered_map>

int get_index(std::unordered_map<char, int> map, std::string line, int str_len) {
    int len = -1;
    int max_len = 3;
    int left = 0;

    for (int right = 0; right < line.length(); right++) {
        
    }
    return len;
}

int main() {
    std::unordered_map<char, int> map;
    std::string line;
    std::string input = "input.txt";
    std::fstream newFile(input);
    int val = 0;
    while(getline(newFile, line)) {
        int str_len = line.length();
        val = get_index(map, line, str_len);
    }

    return val;
}
