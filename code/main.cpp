#include "minimax.h"
#include "tree.h"

int main(int argc, char const *argv[]) {
  int player,n,m,tl,b_size;
  cin >> player;
  cin >> n;
  cin >> m;
  cin >> tl;
  if (n == 8 && m == 8){
    b_size=1;
  }else if (n == 10 && m == 8){
    b_size=2;
  }else{
    b_size=3;
  }

  char f,s;
  int a,b,c,d;
  bool my_turn,amBlack;
  Node curr_root;
  if (player == 1){
      my_turn = true; //my_color = black
      curr_root.SetBlack(true);
      amBlack=true;
  }else{
    my_turn = false; //my_color = white
    curr_root.SetBlack(false);
    amBlack=false;
  }

  vector<vector<int> >  board = initialise(b_size);

  while (true){
    if (my_turn == false){
      char t[10];
      cin >> f;
      cin >> a;
      cin >> b;
      cin >> s;
      cin >> c;
      cin >> d;
      
      //cerr <<"testing "<<f<<endl;
      // cin.getline(t, 10);
      // cerr<<"yoyoyo"<<t<<endl;
      // string temp;
      // getline(cin, temp);
      // if(getline(cin, temp)){
      //   cerr <<"Yello";
      //   cerr<<temp;
      //   // return 0;
      //   break;
      // }
      // cin>>temp;
      // cerr<<temp;
      
      // cin >> f;
      // cerr<< f;
      // cin >> a;
      // cerr<< a;
      // cin >> b;
      // cin >> s;
      // cin >> c;
      // cin >> d;
      
      MOVE m  = make_tuple(f,a,b,s,c,d);
      cerr<<"Move from computer: ";
      printerr_move(m);
      cerr<<endl;
      board = Update_board(m,board);
      my_turn = true;
    }else{
      int depth = 2;
      curr_root.SetBoard(board);
      create_tree(&curr_root,depth);
      tuple<int,MOVE> best_tuple = minimax(&curr_root,true,-1000,1000,amBlack);
      MOVE m = get<1>(best_tuple);
      print_move(m);
      board = Update_board(m,board);
      my_turn = false;
    }
  }

  return 0;
}
