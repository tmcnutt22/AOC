#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(void) {
    std::string input = "input.txt";
    std::fstream newFile(input);
    std::string line;
    std::vector<std::string> list;
    //split by ,
    while(getline(newFile, line)) {
        list.push_back(line);
    }
    /*
    //print the input vector
    for (int i = 0; i < list.size(); i++) { 
        std::cout << list.at(i) << std::endl;
    }
    */
    //split by ','
    std::vector <std::string> list2;
    char delim = ',';
    for (int i = 0; i < list.size(); i++) {
        std::string temp = list.at(i);
        std::size_t index = temp.find(delim);
        list2.push_back(temp.substr(0, index));
        list2.push_back(temp.substr(index + 1, temp.length()));
    }
    //split by -
    std::vector <int> list_of_ints;
    for (std::size_t i = 0; i < list2.size(); i++) {
        std::string temp = list2.at(i);
        std::size_t index = temp.find("-");
        if (index != std::string::npos) {
            std::string s1 = temp.substr(0, index);
            std::string s2 = temp.substr(index + 1, temp.length());
            /*
            std::cout << "S1 val: " << s1 << std::endl;
            std::cout << "S2 val: " << s2 << std::endl;
            */
            list_of_ints.push_back(std::stoi(s1));
            list_of_ints.push_back(std::stoi(s2));
        }

    }
    //check for the overlap
    int over_lapping = 0;
    int len = list_of_ints.size();
    for (int i = 0; i < len; i += 4) {
        int elf_1_start = list_of_ints.at(i); 
        int elf_1_end = list_of_ints.at(i + 1); 
        int elf_2_start = list_of_ints.at(i + 2); 
        int elf_2_end = list_of_ints.at(i + 3); 
        if (((elf_2_start >= elf_1_start) && (elf_2_end <= elf_1_end)) ||
            ((elf_2_start <= elf_1_start) && (elf_2_end >= elf_1_end))
            ) {
            over_lapping++;
        }
    }
    std::cout <<"Num of completely overlapping elves: " << over_lapping << std::endl;
    
    //check for any overlap
    int any_overlap = 0;
    for (int i = 0; i < list_of_ints.size(); i += 4) {
        int elf_1_start = list_of_ints.at(i); 
        int elf_1_end = list_of_ints.at(i + 1); 
        int elf_2_start = list_of_ints.at(i + 2); 
        int elf_2_end = list_of_ints.at(i + 3); 
        if ((elf_2_start >= elf_1_start && elf_2_start < elf_1_end) ||
            (elf_1_start >= elf_2_start && elf_1_start < elf_2_end) ||
            (elf_2_end <= elf_1_end && elf_2_end >= elf_1_start) ||
            (elf_1_end <= elf_2_end && elf_1_end >= elf_2_start)
            ) {
            any_overlap++;
        }
    }

    std::cout <<"Num of any overlapping elves: " << any_overlap << std::endl;

    return 0;
}

