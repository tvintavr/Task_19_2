#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    std::string filePath;
    std::cout << "Enter path: ";
    std::getline(std::cin, filePath);
    
    std::ifstream file(filePath, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Cannot open" << std::endl;
        return 1;
    }
    
    std::vector<char> buffer(20);
    while (file.read(buffer.data(), buffer.size())) {
        std::cout.write(buffer.data(), file.gcount());
    }
    std::cout.write(buffer.data(), file.gcount());
    
    file.close();
}