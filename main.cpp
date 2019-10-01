#include <sstream>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include "gengraph.h"
class graph{
public:
    graph(int dimention){
        this->x = dimention;
        getdata(x);
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
        vector<int> parent(99, 10);
        vector<int> cost = {99,99,99,99,99,99,99,99,99,99};
        //stack<int> stack;
        queue<int> stack;
        stack.push(startNode);
        cost[startNode] = 0;

        while(!stack.empty()){
            std::cout <<"+++ cost array +++" << std::endl;
            for(int i=0;i<cost.size();i++){
                std::cout << cost[i] << " ";
            } std::cout << std::endl << "+++++++++++++++++"<<  std::endl;

            int current = stack.top();
            stack.pop();

            if (current != targetNode){
                for(int i =0;i<x;i++){
                    std::cout << data[i][current] << std::endl;
                    if(data[i][current] > 0){
                        if(cost[i] > (cost[current] + data[i][current])){
                            cost[i] = (cost[current] + data[i][current]);
                            parent[i] = current;
                            stack.push(i);
                        }
                    }
                }
            }
        }
        //display final
        std::stack<uint32_t> finalPath;
        finalPath.push(targetNode);
        int index = targetNode;
        while (index != startNode)
        {
            finalPath.push(parent[index]);
            index = parent[index];
        }

// Print path
        std::cout << "Optimal Path: ";
        while (!finalPath.empty())
        {
            std::cout << finalPath.top() << " ";
            finalPath.pop();
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
    int data[10][10];

};

int main(){
    graph g(10);
    g.displayGraph();
    g.DFS(0,9);

}