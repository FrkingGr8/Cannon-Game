#include "node.h"


void Node::SetBoard(vector<vector<int> > temp){
    board_config = temp;
}
void Node::SetBlack(bool t){
  black = t;
}

void Node::SetMove(MOVE m){
  move = m;
}

//Use this function only once!
//WHOSE turn is it??
void Node::SetChildren(){
  vector<coord> black_soldiers = Soldiers_list(1,board_config);
  vector<coord> white_soldiers = Soldiers_list(-1,board_config);
  //first is black and second is white
  tuple<vector<CANNON>,vector<CANNON> > cannon_lists = Update(board_config);
  //if current chance is black
  vector<MOVE> next_possibilities;
  if (GetBlack() == true){
    next_possibilities = next_moves(get<0>(cannon_lists),black_soldiers,white_soldiers,true);
  }  else{
    next_possibilities = next_moves(get<1>(cannon_lists),white_soldiers,black_soldiers,false);
  }

  for (int j =0; j<next_possibilities.size();j++){
    MOVE curr_move = next_possibilities[j];
    vector<vector <int> > new_board =Update_board(curr_move,board_config);
    Node next_state;
    next_state.SetBoard(new_board);
    next_state.SetMove(curr_move);
    next_state.SetBlack(!(GetBlack()));
    children.push_back(next_state);
  }
}



int main(int argc, char const *argv[]) {
  std::vector<std::vector<int> > board = initialise();
  Node root;
  root.SetBoard(board);
  root.SetChildren();
  vector<Node> succ = root.GetChildren();
  Node one = succ[0];
  cout<< succ<<endl;
  cout <<"Working"<<endl;

  return 0;
}
