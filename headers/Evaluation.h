#ifndef EVALUATION_H
#define EVALUATION_H

#include "commonlib.h"
#include "cannon_list.h"
#include "cannon.h"

int Eval(vector<vector<int> > board, tuple<vector<CANNON>, vector<CANNON> > cannon_list, int type);
int blocked_cannon(vector<coord>soldier_list,vector<coord>opp_soldier_list,vector<CANNON>cannon_list);



#endif
