#include <iostream>
#include <tuple>
#include <algorithm>

using namespace std;
struct coord{
  int x,y;
};

typedef tuple<coord,coord,coord> CANNON;
typedef tuple<char,coord,char,coord> MOVE;
