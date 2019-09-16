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
  	if (a.x < n  && a.y < m && a.x >= 0 && a.y >= 0){
      if (contains(a,soldier_list) == false){
        correct_moves.push_back(a);
      }
  	}
  }
	return correct_moves;
}

void print_cannon(vector<CANNON> list){
    for(int i = 0; i<list.size(); i++){
        CANNON temp = list[i];
        coord F = get<0>(temp), M = get<1>(temp), L = get<2>(temp);
        cout<<F.x<<" "<<F.y<<" -> "<<M.x<<" "<<M.y<<" -> "<<L.x<<" "<<L.y<<endl;
    }
}


void print_board(vector<vector<int> > board){
    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}


void print_soldier(vector<coord> t){
    for(int i = 0; i<t.size(); i++){
        cout<<t[i].x<<" "<<t[i].y<<endl;
    }
}



void print_move(MOVE m){
  cout<<get<0>(m)<<" "<<get<1>(m)<<" "<<get<2>(m)<<" "<<get<3>(m)<<" "<<get<4>(m)<<" "<<get<5>(m)<<endl;
}
