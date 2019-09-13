#ifndef CANNON_H
#define CANNON_H
#include "commonlib.h"

vector<MOVE> cannon_shot(vector<CANNON> cannon_list,vector<coord> soldier_list, vector<coord> opp_soldier_list);
// vector<coord> moves_filter(vector<coord> moves, vector<coord> soldier_list, int n, int m);
// vector<coord> soldier_moves(coord soldier, vector<coord> op_soldier_list, bool black); //black = 1 if black else white

#endif
