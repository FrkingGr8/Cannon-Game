#include "Evaluation.h"


float Eval(vector<vector<int> > board,  int type){
    float ans = 0;
    tuple<vector<CANNON>, vector<CANNON> > cannon_list = Update(board);
    int w1, w2, w3, w4, w5, w6, w7, w8, w9, w10, w11, w12;
    w1 = 2;
    w2 = -4;
    
    w3 = 3;
    w4 = -6;
    
    w5 = 50;
    w6 = -50;
    
    w7 = -200;
    w8 = 100;
    
    w9 = -200;
    w10 = 100;
    
    w11 = 5;
    w12 = -4;

    vector<coord> Black_S_list = Soldiers_list(1, board);
    vector<coord> White_S_list = Soldiers_list(-1, board);

    vector<CANNON> White_C_list = get<0>(cannon_list);
    vector<CANNON> Black_C_list = get<1>(cannon_list);

    int no_of_soldier, no_of_enemy_soldier;  //done
    int no_of_cannon, oppn_no_of_cannon; //done
    int oppn_town, town;  //done
    float oppn_soldier_from_town, soldier_from_town; //done
    float soldier_from_oppn_town, oppn_soldier_from_oppn_town;//done
    int oppn_blocked_cannon, blocked_cannon1; //done
    //int total_moves_possible, oppn_total_moves_possible;

    int a = Black_C_list.size();
    int b = White_C_list.size();

    int c = White_S_list.size();
    int d = Black_S_list.size();

    tuple<int, int> t1 = townhall_dist(Black_S_list, board); 
    tuple<int, int> t2 = townhall_dist(White_S_list, board);

    int e = blocked_cannon(Black_S_list, White_C_list);
    int f = blocked_cannon(White_S_list, Black_C_list);


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

        blocked_cannon1 = f;
        oppn_blocked_cannon = e; 

        oppn_soldier_from_town = (float)(1/oppn_soldier_from_town);
        soldier_from_town = (float)(1/soldier_from_town);
        soldier_from_oppn_town = (float)(1/soldier_from_oppn_town);
        oppn_soldier_from_oppn_town = (float)(1/oppn_soldier_from_oppn_town);


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

        blocked_cannon1 = e;
        oppn_blocked_cannon = f;

        oppn_soldier_from_town = (float)(1/oppn_soldier_from_town);
        soldier_from_town = (float)(1/soldier_from_town);
        soldier_from_oppn_town = (float)(1/soldier_from_oppn_town);
        oppn_soldier_from_oppn_town = (float)(1/oppn_soldier_from_oppn_town);


        }   
    
    ans = (float)(w1*no_of_soldier) + (float)(w2*no_of_enemy_soldier);
    ans = (float)(ans) + (float)(w3*no_of_cannon) + (float)(w4*oppn_no_of_cannon);
    ans = (float)(ans) + (float)(w5*town) + (float)(w6*oppn_town);
    // ans = (float)(ans) + (float)(w7*oppn_soldier_from_town) + (float)(w8*soldier_from_town);
    ans = (float)(ans) + (float)(w9*oppn_soldier_from_oppn_town) + (float)(w10*oppn_soldier_from_oppn_town);
    ans = (float)(ans) + (float)(w11*oppn_blocked_cannon) + (float)(w12*blocked_cannon1);
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


int blocked_cannon(vector<coord>opp_soldier_list,vector<CANNON>cannon_list){
  int number=0;
  vector<coord> blocked_positions;
  for (int j = 0; j< cannon_list.size(); j++){
    CANNON curr_cannon = cannon_list[j];
    coord mid_ele = get<1>(curr_cannon);
    int orie = orientation(curr_cannon);
    if (orie == 0){
      coord bp1= {mid_ele.x-2,mid_ele.y};
      coord bp2= {mid_ele.x+2,mid_ele.y};
      blocked_positions.push_back(bp1);
      blocked_positions.push_back(bp2);
    }else if (orie == 1){
      coord bp1= {mid_ele.x,mid_ele.y-2};
      coord bp2= {mid_ele.x,mid_ele.y+2};
      blocked_positions.push_back(bp1);
      blocked_positions.push_back(bp2);
    }else if (orie == 2){
      coord bp1= {mid_ele.x-2,mid_ele.y+2};
      coord bp2= {mid_ele.x+2,mid_ele.y-2};
      blocked_positions.push_back(bp1);
      blocked_positions.push_back(bp2);
    }else{
      coord bp1= {mid_ele.x-2,mid_ele.y-2};
      coord bp2= {mid_ele.x+2,mid_ele.y+2};
      blocked_positions.push_back(bp1);
      blocked_positions.push_back(bp2);
    }
  }


  for (int k = 0; k < opp_soldier_list.size(); k++){
    coord soldier = opp_soldier_list[k];
    for (int i = 0; i < blocked_positions.size(); i++){
      coord curr_pos = blocked_positions[i];
      if (soldier.x == curr_pos.x && soldier.y == curr_pos.y){
          number++;
      }
    }
  }
  return number;
}
