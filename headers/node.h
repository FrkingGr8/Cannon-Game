#ifndef NODE_H
#define NODE_H

#include "next_moves.h"
#include "cannon_list.h"


class Node{
    private:
      vector<vector<int> > board_config;
      vector<Node> children;
      // Node parent;
      // bool is_root;
    public:
        void SetBoard(vector<vector<int> > temp);
        void SetChildren();
        // void SetParent(Node parent_node);


        vector<vector<int> >GetBoard(){
          return board_config;
        }
        vector<Node> GetChildren(){
          return children;
        }
        // bool GetIsRoot(){
        //   return is_root;
        // }
        // Node GetParent(){
        //   return parent;
        // }

};


#endif
