#ifndef NEXT_MOVES
#define NEXT_MOVES
#include "commonlib.h"

bool contains(coord ele, vector<coord> list);
vector<coord> moves_filter(vector<coord> moves, vector<coord> soldier_list, int n, int m);
vector<MOVE> coord_to_move(coord soldier, vector<coord> moves);
vector<coord> soldier_moves(coord soldier, vector<coord> op_soldier_list, bool black); //black = 1 if black else white
vector<MOVE> next_moves(vector<CANNON> cannon_list, int** board, vector<coord> soldier_list, vector<coord> opp_soldier_list, bool black);


#endif
