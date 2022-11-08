#pragma once
#include "random"
#include <iostream>
#include <string.h>
class Tree
{
private:
    class Node
    {
    private:
        Node* children[3];
        char value;
        void node_show(Tree* tr,int dep,int offset,int center);
        void inner_add(std::string* s,Tree* tr);
    public:
        Node();
        Node(const int);
        ~Node();
        friend class Tree;
    };
    static int tag;
    static const int ch_count;
    const int depth;
    const int breadth;
    char** screen;
    Node* root;
public:
    void scr_update();
    int nodes_with_children;
    void create_tree(const int dep);
    void create_node(const int dep,const int max_dep,Tree* tr,Node* n,int offset,int center);
    static Node* random_node(const int dep,const int max_dep);
    void create_random_tree(const int dep);
    std::string inner_search();
    void show();
    Tree(int depth, int breadth);
    ~Tree();
};


