#include <sstream>
#include <iostream>
#include <stack>
#include <vector>
#include "gengraph.h"
class graph{
public:
    graph(int x){
        getdata(x);
        x = 10;
        std::cout << "DIMENSION " << x << std::endl;

        //int visited[];
        stack<int> s;
        std::stringstream row;
        std:: ifstream file("data.txt");
        for(int i=0;i<x;i++){
            for(int j=0;j<x;j++){
                file >> data[j][i];
            }
        }
    }

    void displayGraph(){
        for(int i=0;i<x;i++){
            for(int j=0;j<x;j++){
                std::cout << data[j][i] << " ";
                //std::cout << "test " << std::endl;
            }
            std::cout << std::endl;
        }
    }
private:
    int x;
    int data[50][50];

};

int main(){

    graph g(5);
   g.displayGraph();
}