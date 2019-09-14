#ifndef CANNON_LIST_H
#define CANNON_LIST_H

#include "commonlib.h"

vector<vector<int> > initialise();
tuple<vector<CANNON>, vector<CANNON> > Update(vector<vector<int> >);
vector<CANNON> Get_list(int, vector<vector<int> >);
vector<vector<int> > Update_board(MOVE, vector<vector<int> >);
vector<coord> Soldiers_list(int, vector<vector<int> >);
bool Search(vector<CANNON>, CANNON);

void print_board(vector<vector<int> >);
void print_cannon(vector<CANNON>);
void print_soldier(vector<coord>);

#endif
