#include "tree.h"

//expands the children. for d = 0 children of root are leaves.
//DONT SET CHILDREN BEFORE CREATE TREE FUNCTION!!
//d = 2 reasonable
void create_tree(Node* root,int d){
  (*root).SetChildren();
  while (d != 0 && ((*root).GetChildren().size())!=0){
    d--;
    vector<Node*> succ = (*root).GetChildren();
    // cout<<"Current depth: "<<d+1<<" Number of children = "<<succ.size()<<endl;
    for (int k = 0; k<succ.size(); k++){
      Node* curr_child = succ[k];
      create_tree(curr_child,d);
    }
  }
}

void print_board_new(vector<vector<int> > v){
  for (int i = 0; i< v.size() ; i++){
    vector<int> ll = v[i];
    for (int j = 0; j < ll.size();j++){
      cout<<ll[j]<<"  ";
    }
    cout<<endl;
  }
}

// int main(int argc, char const *argv[]) {
//   std::vector<std::vector<int> > board = initialise();
//
//   Node root;
//   root.SetBoard(board);
//   // print_board_new(root.GetBoard());
//   int d;
//   cin >>d;
//   // root.SetChildren();
//   create_tree((&root),d);
//   tuple<int,MOVE> test = minimax(&root,true,-1000,1000);
//   // cout<<test<<endl;
//   // vector<Node*> succ = root.GetChildren();
//   // Node* child_1 = succ[0];
//   // vector<Node*> succ2 = (*child_1).GetChildren();
//   // cout<<succ2.size()<<endl;
//   // Node* child_2 = succ2[0];
//   // print_board_new((*child_1).GetBoard());
//   // cout<<"----------------------------"<<endl;
//   // print_board_new((*child_2).GetBoard());
//
//   // int d = 2;
//   // for (int k = 0; k<succ.size(); k++){
//   //   Node* child = succ[k];
//   //   print_board_new((*child).GetBoard());
//   //   cout<<"---------------------------"<<endl;
//   // }
//
//   // (*child).SetChildren();
//   //
//   // // while (d != 0){
//   // //   for (int k = 0; k < succ.size(); k++){
//   // //       Node curr_child = succ[k];
//   // //   }
//   // //
//   // // }
//   // Node* one = succ[0];
//   // vector<Node*> n = (*one).GetChildren();
//   // cout<<n.size()<<endl;
//   // cout<< succ<<endl;
//   cout <<"Working"<<endl;
//
//   return 0;
// }
