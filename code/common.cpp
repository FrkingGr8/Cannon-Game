#include "commonlib.h"

bool contains(coord ele, vector<coord> list){
  for (int i = 0 ; i < list.size(); i++){
    coord curr_coord = list[i];
    if (curr_coord.x == ele.x && curr_coord.y == ele.y){
      return true;
    } else{
      continue;
    }
  }
  return false;
}


//removes moves which go outside the board or on a team soldier.
vector<coord> moves_filter(vector<coord> moves, vector<coord> soldier_list, int n, int m){
  vector<coord> correct_moves;
  for (int i = 0; i< moves.size(); i++){
  	coord a = moves[i];
  	if (a.x < n  && a.y < m){
      if (contains(a,soldier_list) == false){
        correct_moves.push_back(a);
      }
  	}
  }
	return correct_moves;
}
