#ifndef NEXT_MOVES_H
#define NEXT_MOVES_H

#include "commonlib.h"
#include "soldier.h"
#include "cannon.h"

tuple<vector<coord>,vector<coord> > create_th_list();
vector<MOVE> next_moves(vector<CANNON> cannon_list, vector<coord> soldier_list, vector<coord> opp_soldier_list, bool black);

#endif
