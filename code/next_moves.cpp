#include "next_moves.h"

// coord test(int a){
//   coord c;
//   c.x = a+1;
//   c.y = a+10;
//   return c;
// }
//
//
// int main(){
//   int a;
//   coord b;
//   cin >> a;
//   // b.x = a;
//   // b.y = a+1;
//   b = test(a);
//   cout<<b.y<<'\n';
//   return 0;
// }

int ret_bound(int a, int n = 8){
  if (a>n){
    return n;
  } else if (a < 0){
    return 0;
  } else{
    return a;
  }
}

// vector<int> allowed_moves(coord soldier, vector<coord> opp_soldier_list){
//
// }
//
//
//
// MOVE next_moves(vector<CANNON> cannon_list, int** board, vector<coord> soldier_list, vector<coord> opp_soldier_list) {
//   int l = 8;
//   int b = 8;
//   MOVE curr_move;
//   for (int i = 0; i < soldier_list.length(); i++){
//     coord curr_coord = soldier_list[i];
//
//
//
//
//   }
//
//   return 0;
// }
