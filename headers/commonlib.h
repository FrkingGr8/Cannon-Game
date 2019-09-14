#ifndef COMMON_H
#define COMMON_H
#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>

using namespace std;

struct coord{
  int x,y;
};

class Node{
    private:
        vector<vector<int> > board_config;
    public:
        vector<Node*> list;

        void SetBoard(vector<vector<int> > temp){
            board_config = temp;
        }

        vector<vector<int> > Get_board(){return board_config;}

};

typedef tuple<coord,coord,coord> CANNON;
typedef tuple<char,int,int,char,int,int> MOVE;

bool contains(coord ele, vector<coord> list);
vector<coord> moves_filter(vector<coord> moves, vector<coord> soldier_list, int n = 8, int m = 8);

#endif
