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


typedef tuple<coord,coord,coord> CANNON;
typedef tuple<char,int,int,char,int,int> MOVE;

bool contains(coord ele, vector<coord> list);
vector<coord> moves_filter(vector<coord> moves, vector<coord> soldier_list, int n = 8, int m = 8);

#endif
