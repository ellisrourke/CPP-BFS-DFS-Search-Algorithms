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
        //getdata(x);

        data = new int*[x];

        for(int i = 0; i < x; ++i) {
            data[i] = new int[x];
        }

        std::cout << "DIMENSION " << x << std::endl;

        std::stringstream row;
        std:: ifstream file("data.txt");
        for(int i=0;i<x;i++){
            for(int j=0;j<x;j++){
                file >> data[j][i];
            }
        }
    }

    ~graph(){
        for(int i = 0; i < x; ++i) {
            delete [] data[i];
        }
        delete [] data;
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

    void DFS(const int startNode,const int targetNode){
        vector<int> parent(x, 99999999);
        vector<int> cost(x, 999999999);
        stack<int> stack;
        //queue<int> stack;
        stack.push(startNode);
        cost[startNode] = 0;

        while(!stack.empty()){


            int current = stack.top();
            //int current = stack.front();
            stack.pop();

            if (current != targetNode){
                for(int i =0;i<x;i++){
                    //std::cout << data[i][current] << std::endl;
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
        std::stack<int> finalPath;
        vector<int> myList;
        finalPath.push(targetNode);
        int index = targetNode;
        while (index != startNode)
        {
            finalPath.push(parent[index]);
            index = parent[index];
        }

        // Print path
        std::cout << "Depth first search Path: ";
        while (!finalPath.empty())
        {
            std::cout << finalPath.top() << " ";
            //myList.push_back(finalPath.top());
            finalPath.pop();
        }
    }


    void BFS(const int startNode,const int targetNode){
        vector<int> parent(x, 99999999);
        vector<int> cost(x, 999999999);
        queue<int> stack;
        stack.push(startNode);
        cost[startNode] = 0;
        int totalCost = 0;
        int hops = 0;
        int nodesPopped = 0;

        while(!stack.empty()){
            int current = stack.front();
            //int current = stack.front();
            stack.pop();
            nodesPopped++;

            if (current != targetNode){
                for(int i =0;i<x;i++){
                    //std::cout << data[i][current] << std::endl;
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
        std::stack<int> finalPath;
        finalPath.push(targetNode);
        int index = targetNode;
        while (index != startNode)
        {
            totalCost += data[parent[index]][index];
            finalPath.push(parent[index]);
            index = parent[index];
            //totalCost += cost[index];

            hops++;
        }

        // Print path
        std::cout << "Breadth first search Path: ";
        while (!finalPath.empty())
        {
            std::cout << finalPath.top() << " ";
            //myList.push_back(finalPath.top());
            finalPath.pop();
        }

        std::cout << std::endl;
        std::cout << "Total hops " << hops << std::endl;
        std::cout << "Total nodes popped " << nodesPopped << std::endl;
        std::cout << "Total cost " << totalCost << std::endl;


    }

    void displayRow(int row){
        for(int j=0;j<x;j++){
            std::cout << data[j][row] << " ";
            //std::cout << "test " << std::endl;
        }
        std::cout << std::endl;
    }



private:
    int x;
    //int data[25][25];
    int** data;

};



int main(){
    int dim;
    int search =2;
    std::cout << "Enter Dimension: ";
    std::cin >> dim;
    graph g(dim);
    //std::cout << "Enter Destination: ";
    //std::cin >> search;

    g.displayGraph();
    //g.DFS(11,search);
    g.BFS(10,search);


}