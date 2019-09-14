#ifndef NODE_H
#define NODE_H

#include "next_moves.h"
#include "cannon_list.h"


class Node{
    private:
      vector<vector<int> > board_config;
      vector<Node> children;
      static Node parent;
      bool is_root;
    public:
        void SetBoard(vector<vector<int> > temp);
        void SetChildren();
        void SetParent(Node parent_node);


        vector<vector<int> > Get_board();
        vector<Node> GetChildren();
        bool GetIsRoot();
        Node GetParent();

};


#endif
