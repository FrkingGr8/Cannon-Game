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
  bool my_turn,amBlack;
  cerr<<player<<" "<<tl<<" "<<n<<" "<<m<<endl;
  Node curr_root;
  // cerr <<"tst"<<endl;
  if (player == 1){
      my_turn = true; //my_color = black
      curr_root.SetBlack(true);
      amBlack=true;
  }else{
    my_turn = false; //my_color = white
    curr_root.SetBlack(false);
    amBlack=false;
  }

  vector<vector<int> >  board = initialise();

  while (true){
    // cerr<<"Tes5t"<<endl;
    if (my_turn == false){
      //cerr<<"Move from computer: "<<my_turn<<endl;
      char t[10];
      cin >> f;
      // cerr<< f;
      cin >> a;
      // cerr<< a;
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
      // cout<<"Best Move from player side: ";
      int depth = 2;
      // Node curr_root;
      curr_root.SetBoard(board);
      create_tree(&curr_root,depth);
      tuple<int,MOVE> best_tuple = minimax(&curr_root,true,-1000,1000,amBlack);
      MOVE m = get<1>(best_tuple);
      // cout<<"Best Move from player side: ";
      print_move(m);
      // cout<<endl;
      board = Update_board(m,board);
      my_turn = false;
    }
  }


  /* code */
  return 0;
}
