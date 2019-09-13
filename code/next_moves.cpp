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


vector<coord> ret_bound(vector<coord> moves, int n = 8, int m = 8, bool imp_flag){
  vector<coord> correct_moves;
  for (int i = 0; i< moves.length(); i++){
	coord a = moves[i];
	if (a.x < n  && a.y < m){
		correct_moves.push_back(a)
	}
  }
	return correct_moves;
}

vector<int> allowed_moves(coord soldier, vector<coord> opp_soldier_list){

}

bool contains(coord ele, vector<coord> list){
	if (find(list.begin(),list.end(),ele)!= list.end()){
		return true;
	}
	return false;
}

#not done bounding on the size of the board. 
vector<coord> soldier_moves(coord soldier, vector<coord> op_soldier_list){
	vector<coord> capture_and_retreat;
	
	bool adj =false;
	
	# Y value 1 less than the soldier.
	for (int i =-1; i< 2; i++){
		coord always;
		always.x = soldier.x + i;
		always.y = soldier.y - 1;
		if (contains(always,op_soldier_list) == true){
			adj = true;
		}
		capture_and_retreat.push_back(always)
	}
	
	#Same y value and one below
	for (int i = -1 ; i<2 ;i++){
		coord new_coord;
		coord only_retreat; 
		new_coord.y = soldier.y;
		only_retreat.y = soldier.y + 1;
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
		retreat1.y = retreat2.y = retreat3.y = soldier.y +2;
		retreat1.x = soldier.x 
		retreat2.x = soldier.x - 2
		retreat3.x = soldier.x + 2;
		capture_and_retreat.push_back(retreat1);
		capture_and_retreat.push_back(retreat2);
		capture_and_retreat.push_back(retreat3);
	}
	
	return capture_and_retreat;
}


vector<MOVE> next_moves(vector<CANNON> cannon_list, int** board, vector<coord> soldier_list, vector<coord> opp_soldier_list) {
  int l = 8;
  int b = 8;
  vector<MOVE> possibilities;
  MOVE curr_move;
  for (int i = 0; i < soldier_list.length(); i++){
    coord curr_coord = soldier_list[i];
	




  }

  return 0;
}
