#include "Evaluation.h"

int Eval(vector<vector<int> > board, tuple<vector<CANNON>, vector<CANNON> > cannon_list, int type){
    int ans = 0;
    vector<coord> Black_S_list = Soldiers_list(1, board);
    vector<coord> White_S_list = Soldiers_list(-1, board);

    vector<CANNON> White_C_list = get<0>(cannon_list);
    vector<CANNON> Black_C_list = get<1>(cannon_list);

    int no_of_soldier, no_of_enemy_soldier;  //done
    int no_of_cannon, oppn_no_of_cannon; //done
    int oppn_town, town;  //done
    int oppn_soldier_from_town, soldier_from_town; //done
    int soldier_from_oppn_town, oppn_soldier_from_oppn_town;//done
    int oppn_blocked_cannon, blocked_cannon;
    int total_moves_possible, oppn_total_moves_possible;

    int a = Black_C_list.size();
    int b = White_C_list.size();

    int c = White_S_list.size();
    int d = Black_S_list.size();

    tuple<int, int> t1 = townhall_dist(Black_S_list, board); 
    tuple<int, int> t2 = townhall_dist(White_S_list, board);

    if(type == 1){//Black 
        no_of_soldier = d;
        no_of_enemy_soldier = c;
        
        no_of_cannon = a;
        oppn_no_of_cannon = b;
        
        town = abs(board[7][1]/2) + abs(board[7][3]/2) + abs(board[7][5]/2) + abs(board[7][7]/2);
        oppn_town = abs(board[0][0]/2) + abs(board[0][2]/2) + abs(board[0][4]/2) + abs(board[0][6]/2);
        
        oppn_soldier_from_town = get<1>(t2);
        soldier_from_town = get<0>(t1);

        soldier_from_oppn_town = get<1>(t1);
        oppn_soldier_from_oppn_town = get<0>(t2);

    }else{//White
        no_of_enemy_soldier = d;
        no_of_soldier = c;
        
        oppn_no_of_cannon = a;
        no_of_cannon = b;
        
        oppn_town = abs(board[7][1]/2) + abs(board[7][3]/2) + abs(board[7][5]/2) + abs(board[7][7]/2);
        town = abs(board[0][0]/2) + abs(board[0][2]/2) + abs(board[0][4]/2) + abs(board[0][6]/2);
        
        oppn_soldier_from_town = get<1>(t1);
        soldier_from_town = get<0>(t2);

        soldier_from_oppn_town = get<1>(t2);
        oppn_soldier_from_oppn_town = get<0>(t1);
        }

    return ans;

}

tuple<int, int> townhall_dist(vector<coord> Soldiers_list, vector<vector<int> > board){
    tuple<int, int> ans;
    int type = board[Soldiers_list[0].y][Soldiers_list[0].x];
    int self = 0, oppn = 0;

    for(int i = 0; i<Soldiers_list.size(); i++){
        int x = Soldiers_list[i].y;
        int y = Soldiers_list[i].x;
        if(type>0){
            self = self + abs(7-x);
            oppn = oppn + abs(x);

            //Self          
            if(board[7][1]==2){
                self = abs(1-y) + self;
            }
            if(board[7][3] == 2){
                self = abs(3-y) + self;
            }
            if(board[7][3] == 2){
                self = abs(5-y) + self;
            }
            if(board[7][5] == 2){
                self = abs(7-y) + self;
            }

            //Oppn
            if(board[0][0] == -2){
                oppn = oppn + abs(y);
            }
            if(board[0][2] == -2){
                oppn = oppn + abs(2-y);
            }
            if(board[0][4] == -2){
                oppn = oppn + abs(4-y);
            }
            if(board[0][6] == -2){
                oppn = oppn + abs(6-y);
            }

        }else{//White is the type of soldier
            oppn = oppn + abs(x-7);
            self = self + abs(x);
            //oppn          
            if(board[7][1]==2){
                oppn = oppn + abs(1-y);
            }
            if(board[7][3] == 2){
                oppn = oppn + abs(3-y);
            }
            if(board[7][3] == 2){
                oppn = oppn + abs(5-y);
            }
            if(board[7][5] == 2){
                oppn = oppn + abs(7-y);
            }

            //self
            if(board[0][0] == -2){
                self = self + abs(0-y);
            }
            if(board[0][2] == -2){
                self = self + abs(2-y);
            }
            if(board[0][4] == -2){
                self = self + abs(4-y);
            }
            if(board[0][6] == -2){
                self = self + abs(6-y);
            }
        }
    }
    ans = make_tuple(self, oppn);
    return ans;
}
