
#include <iostream>
#include <vector>
#include <sstream>


int main(){
std::cout << "TESTING " << std::endl;
    int x = atoi(__argv[1]);
    std::cout << "DIMENSION" << x << std::endl;

    int data[x][x];
    int i=0;
    std::string row;
    while (std::getline(std::cin, row)) {
        //std::cout << row << std::endl;
        for(int j=0;j<x;j++){
            std::cin >> data[i][j];
        }
               //std::cout << name << subject << grade << std::endl;
    }

    for(int z=0;z<x;z++){
        std::cout << data[0][z] << " ";
    }
}