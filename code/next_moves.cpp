#include "next_moves.h"

vector<MOVE> next_moves(vector<CANNON> cannon_list, vector<coord> soldier_list, vector<coord> opp_soldier_list, bool black) {
  int l = 8;
  int b = 8;
  vector<MOVE> possibilities;
  MOVE curr_move;

  //individual soldier's moves
  for (int i = 0; i < soldier_list.size(); i++){
    coord curr_sold = soldier_list[i];
    vector<coord> all_mov = soldier_moves(curr_sold, opp_soldier_list, black);
    vector<coord> fil_mov = moves_filter(all_mov,soldier_list,l,b);
    vector<MOVE> curr_sol_moves = coord_to_move(curr_sold,fil_mov);
    possibilities.reserve(possibilities.size() + distance(curr_sol_moves.begin(),curr_sol_moves.end()));
    possibilities.insert(possibilities.end(),curr_sol_moves.begin(), curr_sol_moves.end());
  }
  vector<MOVE> curr_cannon_moves = cannon_action(cannon_list,soldier_list, opp_soldier_list);
  possibilities.reserve(possibilities.size() + distance(curr_cannon_moves.begin(),curr_cannon_moves.end()));
  possibilities.insert(possibilities.end(),curr_cannon_moves.begin(), curr_cannon_moves.end());

  return possibilities;
}
