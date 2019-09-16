#include "commonlib.h"
#include "cannon_list.h"

int Eval(vector<vector<int> > board, tuple<vector<CANNON>, vector<CANNON> > cannon_list){
    vector<coord> Black_S_list = Soldiers_list(1, board);
    vector<coord> White_S_list = Soldiers_list(-1, board);

    vector<CANNON> White_C_list = get<0>(cannon_list);
    vector<CANNON> Black_C_list = get<1>(cannon_list);

}