#include <iostream>
#include <vector>
#include "graph.h"
#include <time.h>
using namespace std;

int main()
{
    int len;
    string buffer;
    std::cout << "Count of vertexes: ";
    std::cin >> buffer;
    len = stoi(buffer);
    if(len>=26) len = 25;
    Graph g(len,100,50);
    std::cout << "Do you want to fill the graph yourselves or to create a random graph?\n1 - fill the graph\n2 - create a random graph\nYOUR ANSWER: ";
    std::cin >> buffer;
    if(buffer[0] == '1'){
        g.fill_graph();
    }else{
        g.random_graph();
    }
    g.show();
    while(true){
        std::cout << "First vertex: ";
        std::cin >> buffer;
        g.find_lengths(buffer[0]);
        std::cout << "Second vertex: ";
        std::cin >> buffer;
        buffer = g.recreate_path(buffer[0]);
        std::cout << buffer << "\n";
    }
    return 0;
}
