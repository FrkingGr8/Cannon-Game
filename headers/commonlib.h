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
