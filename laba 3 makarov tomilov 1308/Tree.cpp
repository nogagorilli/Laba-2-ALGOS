#include "Tree.h"

const int Tree::ch_count = 3;
int Tree::tag = 0;
Tree::Node::Node()
{
    int i;
    for(i = 0;i<ch_count;i++){
        children[i] = nullptr;
    }
}

Tree::Node::Node(const int val)
{
    int i;
    for(i = 0;i<ch_count;i++){
        children[i] = nullptr;
    }
    value = val;
}

Tree::Node::~Node()
{
    int i;
    for(i = 0;i<ch_count;i++){
        if(children[i] != nullptr){
            delete children[i];
        }
    }
    //std::cout << "delete node " << value <<std::endl;
}

Tree::Tree(int dep,int br):depth(dep),breadth(br)
{
    int i,j;
    root = nullptr;
    screen = new char*[depth];
    for(i = 0;i<depth;i++){
        screen[i] = new char[breadth+1];


        for(j = 0;j<breadth;j++) screen[i][j] = ' ';
        screen[i][j] = 0;
    }
    nodes_with_children = 0;
}

Tree::~Tree()
{
    int i;
    for(i = 0;i<depth;i++){
        delete[] screen[i];
    }
    delete[] screen;
    delete root;
    //std::cout << "delete tree\n";
}

Tree::Node* Tree::random_node(const int dep,const int max_dep)
{
    Node* ret = nullptr;
    int i;
    if((rand()%6>1 &&dep < max_dep)||dep == 0){
        ret = new Node;
    }else ret = nullptr;
    if(ret != nullptr){
        for(i = 0;i<ch_count;i++){
            ret->children[i] = random_node(dep+1,max_dep);
        }
        if(tag <26){
            ret->value = 'a' + (tag++)%26;
        }else{
            ret->value = 'A' + (tag++)%26;
        }
    }
    return ret;
}

void Tree::create_random_tree(const int dep)
{
    delete root;
    root = nullptr;
    root = random_node(0,dep);
}

void Tree::show()
{
    scr_update();
    int i;
    for(i = 0;i<depth;i++){
        std::cout << screen[i]<<std::endl;
    }
}

void Tree::Node::node_show(Tree* tr,int dep,int offset,int center)
{
    int i,j,up,down;
    tr->screen[dep][center] = value;
    for(i = 0;i<Tree::ch_count;i++){
        if(children[i] != nullptr){
            up = center;
            down = center-offset+offset*i;
            for(j = 0;j<3;j++){
                tr->screen[dep+j+1][center - ((up-down)*j)/3] = '.';
            }
            children[i]->node_show(tr,dep+4,offset/3,center-offset+offset*i);
        }
    }
}

void Tree::scr_update()
{
    if(root != nullptr) root ->node_show(this,0,breadth/3-2,breadth/2);
}

std::string Tree::inner_search()
{
    std::string ret;
    ret = "";
    nodes_with_children = 0;
    if(root != nullptr) root->inner_add(&ret,this);
    return ret;
}

void Tree::Node::inner_add(std::string* s,Tree* tr)
{
    int cntr,i,show,a;
    cntr = 0;
    show = 1;
    a = 1;
    for(i = 0;i<Tree::ch_count;i++){
        if(children[i] != nullptr){
            if(cntr == 1){
                if(children[0] !=nullptr||children[1] !=nullptr||children[2] !=nullptr){
                    tr->nodes_with_children++;
                    //std::cout <<value<<tr->nodes_with_children<<" ";
                }
                *s+=value;
                *s +="_";
                show = 0;
            }
            cntr++;
            children[i]->inner_add(s,tr);
        }
    }
    if(show){
        if(children[0] !=nullptr||children[1] !=nullptr||children[2] !=nullptr){
            tr->nodes_with_children++;
            //std::cout <<value<<tr->nodes_with_children<<" ";
        }
        *s+=value;
        *s +="_";
    }
}




void Tree::create_node(const int dep,const int max_dep,Tree* tr,Node* n,int offset,int center)
{
    int i;
    std::string buffer;
    if(dep <max_dep){
        for(i = 0;i<ch_count;i++){
            buffer = "-000";
            system("cls");
            screen[dep*4][center-offset+offset*i] = '|';
            show();
            screen[dep*4][center-offset+offset*i] = ' ';
            std::cout << "Enter node(type '-' if you don't want this node to exist): ";
            std::cin >>buffer;
            if(buffer[0] != '-'){
                n->children[i] = new Node;
                n->children[i]->value = buffer[0];
                if(n->children[i] != nullptr)create_node(dep+1,max_dep,tr,n->children[i],offset/3,center-offset+offset*i);

            }
        }
    }
}

void Tree::create_tree(const int dep)
{
    Node* ret = nullptr;
    int i;
    std::string buffer;
    buffer = "-000";
    delete root;
    root = nullptr;
    system("cls");
    screen[0][breadth/2] = '|';
    show();
    screen[0][breadth/2] = ' ';
    std::cout << "Enter node(type '-' if you don't want this node to exist): ";
    std::cin >>buffer;
    if(buffer[0] != '-'){
        root = new Node;
        root ->value = buffer[0];

        create_node(1,dep,this,root,breadth/3-2,breadth/2);
    }else root = nullptr;
    system("cls");
}
