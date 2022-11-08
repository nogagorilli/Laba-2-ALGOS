#include <iostream>
#include "Tree.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    string buff;
    srand(time(0));
    Tree a(20,150);

    cout << "1 - Random tree\n2-create tree\nYOUR ANSWER: ";
    cin >>buff;
    if(buff[0] == '2'){
        a.create_tree(5);
    }else{
        a.create_random_tree(5);
        system("cls");
    }
    a.show();
    buff = a.inner_search();
    cout<<"Search list: " << buff<<endl;
    cout<<"Count of nodes with children: " << a.nodes_with_children<<endl;
    return 0;
}
