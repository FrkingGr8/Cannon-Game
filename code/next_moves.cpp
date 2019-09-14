#include "next_moves.h"

// coord test(int a){
//   coord c;
//   c.x = a+1;
//   c.y = a+10;
//   return c;
// }
//
// //
// int main(){
//   coord a2,b,c,d,e;
//   a2 = {3,3};
//   b = {4,4};
//   c = {5,5};
//   d = {3,2};
//   e = {2,2};
//   vector<coord> soldiers = {a2,b,c,d};
//   // vector<coord> v2 = {a2,b,d};
//   // vector<coord> vv = soldier_moves(a,v,false);
//   CANNON can = make_tuple(c,b,a2);
//   std::vector<CANNON> v = {can};
//   std::vector<MOVE> vv = next_moves(v,soldiers,{e},0);
//   // MOVE a = cannon_coord_to_move(a2,b);
//   // bool tst = contains(a,v);
//   for (int i = 0; i < vv.size(); i++){
//     MOVE a = vv[i];
//     cout << get<0>(a)<<" "<< get<1>(a)<<" "<<get<2>(a)<<" "<<get<3>(a)<<" "<<get<4>(a)<<" "<<get<5>(a)<<'\n';
//
//     // cout << now.x<<" "<<now.y<<'\n';
//   }
//   return 0;
// }
//



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
