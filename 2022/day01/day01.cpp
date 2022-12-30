//
//  main.cpp
//  AOC_2022
//
//  Created by thomas mcnutt on 12/5/22.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <chrono>

int main(int argc, const char * argv[]) {
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    std::vector<int> list1;
    std::string input = "input.txt";
    std::fstream newFile(input);
    std::string line;
    
    int runningCount = 0;
    while (std::getline(newFile, line)) {
        if (line == "") {
            list1.push_back(runningCount);
            runningCount = 0;
        } else {
            int curr = std::stoi(line);
            runningCount += curr;
        }
    }
    if (runningCount > 0) {
        list1.push_back(runningCount);
    }
    
    std::priority_queue<int, std::vector<int>, std::greater<int> > minHeap;
    int max_size = 3;
    for (int i = 0; i < list1.size(); i++) {
        minHeap.push(list1.at(i));
        if (minHeap.size() > max_size) {
            minHeap.pop();
        }
    }

    int t3cals = 0;
    while(!minHeap.empty()) {
        t3cals += minHeap.top();
        minHeap.pop();
    }
    std::chrono::high_resolution_clock::time_point stop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double> >(stop - start);
    std::cout << "Elf: " << t3cals << std::endl;
    std::cout << time_span.count() << std::endl;
    return 0;
}
