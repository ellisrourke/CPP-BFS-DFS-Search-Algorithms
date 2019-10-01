#include <sstream>
#include <iostream>
#include <stack>
#include <vector>
#include "gengraph.h"
class graph{
public:
    graph(int dimention){
        this->x = dimention;
        //getdata(x);
        std::cout << "DIMENSION " << x << std::endl;

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

    void DFS(int startNode,int targetNode){
        vector<int> parent;
        vector<int> cost = {99,99,99,99,99};
        stack<int> stack;
        stack.push(startNode);
        cost[startNode] = 0;

        while(!stack.empty()){
            for(int i=0;i<stack.size();i++){
                std::cout << stack.top() << " ";
            } std::cout <<" test" << std::endl;

            int current = stack.top();
            stack.pop();

            if (current != targetNode){
                for(int i =0;i<x;i++){
                    if(data[i][current] > 0){
                        if(cost[i] > (cost[current] + cost[i])){
                            cost[i] = (cost[current] + cost[i]);
                            parent[i] = current;
                            stack.push(i);
                        }
                    }
                }
            }
        }
    }

    void displayRow(){
            for(int j=0;j<x;j++){
                std::cout << data[j][0] << " ";
                //std::cout << "test " << std::endl;
            }
            std::cout << std::endl;
        }



private:
    int x;
    int data[5][5];

};

int main(){
    graph g(5);
    g.displayGraph();
    g.DFS(0,4);

}