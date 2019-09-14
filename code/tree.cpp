#include "tree.h"

//expands the children. for d = 1 children of root are leaves.
//DONT SET CHILDREN BEFORE CREATE TREE FUNCTION!!
void create_tree(Node* root,int d){
  (*root).SetChildren();
  while (d != 0){
    d--;
    vector<Node*> succ = (*root).GetChildren();
    cout<<"Current depth: "<<d+1<<" Number of children = "<<succ.size()<<endl;
    for (int k = 0; k<succ.size(); k++){

      Node* curr_child = succ[k];
      create_tree(curr_child,d);
    }
  }
}

int main(int argc, char const *argv[]) {
  std::vector<std::vector<int> > board = initialise();
  Node root;
  root.SetBoard(board);
  int d;
  cin >>d;
  create_tree((&root),d);
  // root.SetChildren();
  //
  // vector<Node*> succ = root.GetChildren();
  // // int d = 2;
  // Node* child = succ[0];
  // (*child).SetChildren();
  //
  // // while (d != 0){
  // //   for (int k = 0; k < succ.size(); k++){
  // //       Node curr_child = succ[k];
  // //   }
  // //
  // // }
  // Node* one = succ[0];
  // vector<Node*> n = (*one).GetChildren();
  // cout<<n.size()<<endl;
  // cout<< succ<<endl;
  cout <<"Working"<<endl;

  return 0;
}
