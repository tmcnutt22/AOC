#include <iostream>

int main () {
    std::string hello = "hello\n";
    std::cout << "Str len: " << hello.length() << std::endl;
    std::cout << "String: " << hello << std::endl;
    hello[hello.length() - 1] = '\0';
    std::cout << "New str len: " << hello.length() << std::endl;
    std::cout << "String: " << hello << std::endl;
    return 0;
}
