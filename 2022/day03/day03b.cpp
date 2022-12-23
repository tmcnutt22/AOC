#include <iostream>
#include <fstream>
#include <string>

int main (void) {

    std::string input = "input.txt";
    std::fstream newFile(input);
    std::string strArray[100];
    std::string line;
    int index = 0;
    while (getline(newFile, line)) {
        strArray[index++] = line;
    }
    for (int i = 0; i < 100; i++) {
        std::cout << strArray[i] << std::endl;
    }

    return 0;
}

