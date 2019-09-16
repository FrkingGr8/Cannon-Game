#include "minimax.h"
#include "tree.h"

int main(int argc, char const *argv[]) {
  int player,n,m,tl;
  cin >> player;
  cin >> n;
  cin >> m;
  cin >> tl;

  char f,s;
  int a,b,c,d;
  bool my_turn;

  if (player == 0){
      my_turn = true; //my_color = black
  }else{
    my_turn = false; //my_color = white
  }

  vector<vector<int> >  board = initialise();

  while (true){
    if (my_turn == false){
      cin >> f;
      cin >> a;
      cin >> b;
      cin >> s;
      cin >> c;
      cin >> d;
      MOVE m  = make_tuple(f,a,b,s,c,d);
      cout<<"Move from computer: ";
      print_move(m);
      cout<<endl;
      board = Update_board(m,board);
      my_turn = true;
    }else{
      int depth = 2;
      Node curr_root;
      curr_root.SetBoard(board);
      create_tree(&curr_root,2);
      tuple<int,MOVE> best_tuple = minimax(&curr_root,true,-1000,1000);
      MOVE m = get<1>(best_tuple);
      cout<<"Best Move from player side: ";
      print_move(m);
      cout<<endl;
      board = Update_board(m,board);
      my_turn = false;
    }
  }


  /* code */
  return 0;
}
