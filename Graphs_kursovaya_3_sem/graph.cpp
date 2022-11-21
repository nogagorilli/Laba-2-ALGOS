#include "graph.h"


const float PI = 3.14;

Graph::Graph(int len,int w,int h)
{
    adjacency.resize(len);
    for(auto i = 0;i<len;++i) adjacency[i].resize(len);
    lengths.resize(len);
    for(auto j = 0;j<len;++j) lengths[j] = -1;
    marks.reserve(len);
    nodes.reserve(len);
    length = len;

    WIDTH = w;
    HEIGHT = h;

    //screen->resize(HEIGHT);
    screen.resize(HEIGHT);
    for(auto i = 0;i<HEIGHT;++i){
        screen[i].resize(WIDTH);
        for(auto j = 0;j<WIDTH;++j){
            screen[i][j] = '.';
            //screen[i].resize(WIDTH);
        }
    }
}

void Graph::random_graph()
{
    int k;
    for(auto i = 0;i<length;++i) marks.push_back(0);
    for(auto i = 0;i<length;++i) nodes.push_back('A'+i);

    for(int i = 0;i<length;++i){
        lengths[i] = -1;

    }

    for(int i = 0;i<length;++i){
        for(int j = 0;j<length;++j){
            if((rand()%4 == 0) && (i != j)){
                k = rand()%99+1;
                adjacency[i][j] = k;
                adjacency[j][i] = k;
            }else{
                adjacency[i][j] = -1;
                adjacency[j][i] = -1;
            }
        }
    }
}

void Graph::show()
{
    std::cout << " |";
    for(int i = 0;i<length;++i) std::cout <<" " <<(char)('A' + i) << "|";
    std::cout << "\n";
    for(int i = 0;i<length;++i){
        //for(auto j = *i.begin;j!= *i.end;++j) std::cout << j << " ";
        std::cout <<(char)('A' + i) << "|";
        for(int j = 0;j<length;++j){
            if(adjacency[i][j] != -1){
                if(adjacency[i][j] <=9) std::cout <<" ";
                std::cout  <<std::right<< adjacency[i][j] << "|";
            }else{
                std::cout  <<"  |";
            }
        }
        std::cout << "\n";
    }

    draw_graph();

    for(auto i = 0;i <HEIGHT;++i){
        for(auto j = 0;j <WIDTH;++j) std::cout <<screen[i][j];
        std::cout << "\n";
    }

}

void Graph::find_lengths(char vertex)
{
    int first,second,mn,go;
    for(int i = 0;i<length;++i){
        marks[i] = 0;
        lengths[i] = -1;

    }

    for(int i = 0;i<length;++i){
        if(nodes[i] == vertex){
            lengths[i] = 0;
        }
    }

    go = 1;
    while(go){
        first = -1;
        second = -1;
        go = 0;
        mn = 100000000;
        for(int i = 0;i<length;++i){
            if((lengths[i]<mn) &&(marks[i] == 0)&&(lengths[i] != -1)){
                go = 1;
                first = i;
                mn = lengths[i];
            }
        }

        if(first != -1) marks[first] = 1;

        if(first != -1){
            for(second = 0;second<length;++second){
                if(adjacency[first][second] != -1){
                    if((lengths[second] >lengths[first] + adjacency[first][second])||(lengths[second] == -1)){
                        lengths[second] = lengths[first] + adjacency[first][second];
                    }
                }
            }
        }
    }
}

std::string Graph::recreate_path(char last_vertex){
    std::string ret;
    int num, cur,l,go;
    num = last_vertex-'A';
    if(num <0 ||num>=length){
        ret = "NO SUCH ELEMENT";
    }else{
        if(lengths[num] == -1){
            ret = "NO SUCH PATH";
        }else{
            cur = num;
            ret = "";
            ret +="Length: ";
            ret+=std::to_string(lengths[num]);
            ret+= " Path: ";
            l = lengths[num];
            while(l != 0){
                ret += ('A'+cur);
                ret +='-';
                go = 1;
                for(int i = 0;i<length&&go;++i){
                    if((adjacency[i][cur] != -1)&&(lengths[cur]-lengths[i] == adjacency[i][cur])){
                        cur = i;
                        go = 0;
                        l = lengths[i];
                    }
                }
            }
            ret +=('A'+cur);
        }
    }
    return ret;
}

void Graph::fill_graph()
{
    int collumn;
    for(auto i = 0;i<length;++i) marks.push_back(0);
    for(auto i = 0;i<length;++i) nodes.push_back('A'+i);

    for(int i = 0;i<length;++i){
        lengths[i] = -1;

    }
    std::string buffer;
    std::cout << "Enter matrix of a graph of size " <<length<< "x" << length << ":\n";
    for(int i = 0;i<length;++i){
        std::cin >> buffer;

        for(int j = 0,collumn = 0;j<=buffer.size()&&collumn < length;++j,++collumn){
            if(((buffer[j]-'0') >= 0) &&((buffer[j]-'0') <= 9)){
                std::cout << buffer[j]-'0'<< "\n";
                adjacency[i][collumn] = buffer[j]-'0';
                adjacency[collumn][i] = buffer[j]-'0';
            }else{
                adjacency[i][collumn] = -1;
                adjacency[collumn][i] = -1;
            }

        }
        for(collumn;collumn <length;collumn++){
            adjacency[i][collumn] = -1;
            adjacency[collumn][i] = -1;
        }
    }
}

void Graph::draw_graph()
{
    int h1,w1,h2,w2,dh,dw;
    for(auto i = 0;i<HEIGHT;++i){

        for(auto j = 0;j<WIDTH;++j){
            screen[i][j] = ' ';
            //screen[i].resize(WIDTH);
        }
    }
    for(int i = 0;i<length;++i){
        screen[HEIGHT/2 + ((float)HEIGHT-1)/2*std::sin(PI*2/length*i)][WIDTH/2 + ((float)WIDTH-1)/2*std::cos(PI*2/length*i)] = 'A' + i;
    }
    for(int i = 0;i<length;++i){
        for(int j = i+1;j<length;++j){
            if(adjacency[i][j] != -1){
                h1 = HEIGHT/2 + ((float)HEIGHT-1)/2*std::sin(PI*2/length*i);
                w1 = WIDTH/2 + ((float)WIDTH-1)/2*std::cos(PI*2/length*i);

                h2 = HEIGHT/2 + ((float)HEIGHT-1)/2*std::sin(PI*2/length*j);
                w2 = WIDTH/2 + ((float)WIDTH-1)/2*std::cos(PI*2/length*j);
                if(h1>h2){
                    std::swap(h1,h2);
                    std::swap(w1,w2);
                }
                dh = abs(h2-h1);
                dw = w2-w1;
                if(abs(dh) > abs(dw)){
                    for(int k = 1;k<dh-1;k++) screen[h1+k][w1+(int)((float)dw*(float)k/(float)dh)] = '.';
                }else{
                    if(dw>0){
                        for(int k = 1;k<dw-1;k++) screen[h1+(int)((float)dh*(float)k/(float)dw)][w1+k] = '.';
                    }else{
                        for(int k = 1;k<abs(dw)-1;k++) screen[h1+(int)((float)dh*(float)k/(float)abs(dw))][w1-k] = '.';
                    }
                }
                screen[(h1+h2)/2][(w1+w2)/2] = '0' + adjacency[i][j]/10;
                screen[(h1+h2)/2][(w1+w2)/2+1] = '0' + adjacency[i][j]%10;

            }

        }
    }
}

