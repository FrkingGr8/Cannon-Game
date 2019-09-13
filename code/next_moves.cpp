#include "next_moves.h"

coord test(int a){
  coord c;
  c.x = a+1;
  c.y = a+10;
  return c;
}


int main(){
  int a;
  coord b;
  cin >> a;
  // b.x = a;
  // b.y = a+1;
  b = test(a);
  cout<<b.y<<'\n';
  return 0;
}


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
vector<coord> moves_filter(vector<coord> moves, vector<coord> soldier_list, int n = 8, int m = 8){
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

vector<MOVE> coord_to_move(coord soldier, vector<coord> moves){
  vector<MOVE> mvs ;
  for (int k = 0; k < moves.size(); k++){
    coord curr_coord = moves[k];
    MOVE tmp = make_tuple('S',soldier.x,soldier.y,'M',curr_coord.x,curr_coord.y);
    mvs.push_back(tmp);
  }
  return mvs;
}
//not done bounding on the size of the board.
vector<coord> soldier_moves(coord soldier, vector<coord> op_soldier_list, bool black){ //black = 1 if black else white
	vector<coord> capture_and_retreat;

	bool adj = false;

	// forward to the soldier
	for (int i =-1; i<2; i++){
		coord always;
		always.x = soldier.x + i;
    if (black == true){
      always.y = soldier.y - 1;
    } else{
      always.y = soldier.y + 1;
    }
		if (contains(always,op_soldier_list) == true){
			adj = true;
		}
		capture_and_retreat.push_back(always);
	}

	//Same line and behind the soldier.
	for (int i = -1 ; i<2 ;i++){
		coord new_coord;
		coord only_retreat;
		new_coord.y = soldier.y; // same irrespective of black or white
    if (black == true){
      only_retreat.y = soldier.y + 1; //behind
    } else {
      only_retreat.y = soldier.y - 1; //behind
    }
		only_retreat.x = soldier.x + i;
		if (contains(only_retreat,op_soldier_list) == true){
			adj = true;
		}
		if (i == 0){
			continue;
		} else{
			new_coord.x = soldier.x + i;
			if (contains(new_coord,op_soldier_list)){
				adj = true;
				capture_and_retreat.push_back(new_coord);
			}
		}
	}

	if (adj == true){
		coord retreat1,retreat2,retreat3;
    if (black == true){
      retreat1.y = retreat2.y = retreat3.y = soldier.y + 2;
    } else {
      retreat1.y = retreat2.y = retreat3.y = soldier.y - 2;
    }
		retreat1.x = soldier.x;
		retreat2.x = soldier.x - 2;
		retreat3.x = soldier.x + 2;
		capture_and_retreat.push_back(retreat1);
		capture_and_retreat.push_back(retreat2);
		capture_and_retreat.push_back(retreat3);
	}
	return capture_and_retreat;
}


vector<MOVE> next_moves(vector<CANNON> cannon_list, int** board, vector<coord> soldier_list, vector<coord> opp_soldier_list, bool black) {
  int l = 8;
  int b = 8;
  vector<MOVE> possibilities;
  MOVE curr_move;
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
