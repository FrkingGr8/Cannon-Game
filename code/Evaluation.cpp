#include "commonlib.h"
#include "cannon_list.h"

int Eval(vector<vector<int> > board, tuple<vector<CANNON>, vector<CANNON> > cannon_list, int type){
    vector<coord> Black_S_list = Soldiers_list(1, board);
    vector<coord> White_S_list = Soldiers_list(-1, board);

    vector<CANNON> White_C_list = get<0>(cannon_list);
    vector<CANNON> Black_C_list = get<1>(cannon_list);

    int no_of_soldier, no_of_enemy_soldier;
    int no_of_cannon, oppn_no_of_cannon;
    int oppn_soldier_from_town, soldier_from_town;
    int soldier_from_oppn_town, oppn_soldier_from_oppn_town;
    int oppn_town, town;
    int oppn_blocked_cannon, blocked_cannon;
    int total_moves_possible, oppn_total_moves_possible;

    int a = Black_C_list.size();
    int b = White_C_list.size();

    int c = White_S_list.size();
    int d = Black_S_list.size();

    if(type == 1){
        no_of_soldier = d;
        no_of_enemy_soldier = c;
        no_of_cannon = a;
        oppn_no_of_cannon = b;
        town = abs(board[7][1]/2) + abs(board[7][3]/2) + abs(board[7][5]/2) + abs(board[7][7]/2);
        oppn_town = abs(board[0][0]/2) + abs(board[0][2]/2) + abs(board[0][4]/2) + abs(board[0][6]/2);
    }else{
        no_of_enemy_soldier = d;
        no_of_soldier = c;
        oppn_no_of_cannon = a;
        no_of_cannon = b;
        oppn_town = abs(board[7][1]/2) + abs(board[7][3]/2) + abs(board[7][5]/2) + abs(board[7][7]/2);
        town = abs(board[0][0]/2) + abs(board[0][2]/2) + abs(board[0][4]/2) + abs(board[0][6]/2);
    }

}
