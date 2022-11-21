#pragma once
#include <vector>
#include <string.h>
#include <random>
#include <iostream>
#include <cmath>

class Graph
{
private:
    std::vector<std::vector<int>> adjacency;
    std::vector<int> lengths;
    std::vector<int> marks;
    std::vector<char> nodes;
    int length;
    int HEIGHT;
    int WIDTH;
    std::vector<std::vector<char>> screen;
public:
    Graph(int length,int width,int height);
    void random_graph();
    void fill_graph();
    void find_lengths(char first_vertex);
    std::string recreate_path(char last_vertex);
    void draw_graph();
    void show();
};
