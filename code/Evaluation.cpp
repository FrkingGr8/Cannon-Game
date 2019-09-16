#include "Evaluation.h"


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


int blocked_cannon(vector<coord>soldier_list,vector<coord>opp_soldier_list,vector<CANNON>cannon_list){
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
