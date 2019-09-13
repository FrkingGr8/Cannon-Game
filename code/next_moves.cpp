#include "next_moves.h"

// coord test(int a){
//   coord c;
//   c.x = a+1;
//   c.y = a+10;
//   return c;
// }
//
// //
int main(){
  coord a,b,c;
  a.x = 0;
  a.y = 0;
  b.x = 1;
  b.y = 1;
  c.x = 2;
  c.y = 2;
  int d = orientation(make_tuple(a,b,c));
  cout<<d;
  // b.x = a;
  // b.y = a+1;
  // b = test(a);
  // cout<<b.y<<'\n';
  return 0;
}
//



vector<MOVE> next_moves(vector<CANNON> cannon_list, int** board, vector<coord> soldier_list, vector<coord> opp_soldier_list, bool black) {
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



  return possibilities;
}
