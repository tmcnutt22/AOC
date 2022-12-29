#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string line;
    std::string input = "input.txt";
    std::fstream newFile(input);
    
    while(getline(newFile, line)) {
        std::cout << line << std::endl;
    }
    
    return 0;
}
