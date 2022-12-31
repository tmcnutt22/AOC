#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <stack>
#include <vector>

void parse_command(std::string command, int buffer[]) {
    //parse by space
    std::string delim = " ";
    std::size_t pos = command.find(delim);
    int index = 0;
    while (pos != std::string::npos){
        std::size_t end = command.find(delim, pos+1) != std::string::npos ? command.find(delim, pos+1) : command.length();
        std::string str = command.substr(pos, command.find(delim, pos + 1));
        try {
            int temp_int = std::stoi(str);
            buffer[index] = temp_int;
            //std::cout << buffer[index] << std::endl;
            index++;
        } catch(const std::invalid_argument& ia) {
            //std::cerr << "Invalid argument\n";
        }
        pos = command.find(delim, pos + 1);
    }
}

void process_line(int buffer[], std::stack <char> stackArr[]) {
    int num_to_move = buffer[0];
    int from_index = buffer[1] - 1;
    int to_index = buffer[2] - 1;

    std::stack<char> temp_stack;
    for (int i = 0; i < num_to_move; i++) {
        char *temp = new char;
        *temp = stackArr[from_index].top();
        stackArr[from_index].pop();
        temp_stack.push(*temp);
        delete(temp);
    }
    while (!temp_stack.empty()) {
        stackArr[to_index].push(temp_stack.top());
        temp_stack.pop();
    }
}

void create_stack(std::stack <char> stackArr[]) {
    //1
    stackArr[0].push('S');
    stackArr[0].push('M');
    stackArr[0].push('R');
    stackArr[0].push('N');
    stackArr[0].push('W');
    stackArr[0].push('J');
    stackArr[0].push('V');
    stackArr[0].push('T');
    //2
    stackArr[1].push('B');
    stackArr[1].push('W');
    stackArr[1].push('D');
    stackArr[1].push('J');
    stackArr[1].push('Q');
    stackArr[1].push('P');
    stackArr[1].push('C');
    stackArr[1].push('V');
    //3
    stackArr[2].push('B');
    stackArr[2].push('J');
    stackArr[2].push('F');
    stackArr[2].push('H');
    stackArr[2].push('D');
    stackArr[2].push('R');
    stackArr[2].push('P');
    //4
    stackArr[3].push('F');
    stackArr[3].push('R');
    stackArr[3].push('P');
    stackArr[3].push('B');
    stackArr[3].push('M');
    stackArr[3].push('N');
    stackArr[3].push('D');
    //5
    stackArr[4].push('H');
    stackArr[4].push('V');
    stackArr[4].push('R');
    stackArr[4].push('P');
    stackArr[4].push('T');
    stackArr[4].push('B');
    //6
    stackArr[5].push('C');
    stackArr[5].push('B');
    stackArr[5].push('P');
    stackArr[5].push('T');
    //7
    stackArr[6].push('B');
    stackArr[6].push('J');
    stackArr[6].push('R');
    stackArr[6].push('P');
    stackArr[6].push('L');
    //8
    stackArr[7].push('N');
    stackArr[7].push('C');
    stackArr[7].push('S');
    stackArr[7].push('L');
    stackArr[7].push('T');
    stackArr[7].push('Z');
    stackArr[7].push('B');
    stackArr[7].push('W');
    //9
    stackArr[8].push('L');
    stackArr[8].push('S');
    stackArr[8].push('G');
}

int main() {
    //array of stacks to be used
    std::stack <char> stackArr[9];
    create_stack(stackArr);
    
    
    //parse input
    std::string input = "input.txt";
    std::fstream newFile(input);
    std::string line;
    std::vector<std::string> input_vector;
    //read input
    while(getline(newFile, line)) {
        input_vector.push_back(line);
    }

    int index = 0;
    while(index < input_vector.size()) {
        int buffer[3];
        std::string command = input_vector.at(index);
        parse_command(command, buffer);
        process_line(buffer, stackArr); 
        index++;
    }
    //print result
    std::cout << "Top of each stack: "; 
    for (int i = 0; i < 9; i++) {
        std::cout << stackArr[i].top();
    }
    std::cout <<'\n';
    return 0;
}

