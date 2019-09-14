#include "node.h"

class Node{
    private:
        vector<vector<int> > board_config;
        vector<Node> children;
        Node parent;
        bool is_root = true;
    public:
        // Node *list;

        void SetBoard(vector<vector<int> > temp){
            board_config = temp;
        }
        vector<vector<int> >GetBoard(){
          return board_config;
        }

        //Use this function only once!
        //WHOSE turn is it??
        void SetChildren(){
          vector<coord> black_soldiers = Soldiers_list(1,board_config);
          vector<coord> white_soldiers = Soldiers_list(-1,board_config);
          //first is black and second is white
          tuple<vector<CANNON>,vector<CANNON> > cannon_lists = Update(board_config);
          //if current chance is black
          vector<MOVE> next_possibilities = next_moves(get<0>(cannon_lists),black_soldiers,white_soldiers,true)
          // else
          vector<MOVE> next_possibilities = next_moves(get<1>(cannon_lists),white_soldiers,black_soldiers,false)

          for (int j =0; j<next_possibilities.size();j++){
            MOVE curr_move = next_possibilities[j];
            vector<vector <int> > new_board =Update_board(curr_move,board_config);
            Node next_state;
            next_state.SetBoard(new_board);
            next_state.SetParent(*this);
            children.push_back(next_state);
          }
        }
        vector<Node> GetChildren(){
          return children;
        }
        void SetParent(Node parent_node){
          is_root = false;
          parent = parent_node;
        }
        bool GetIsRoot(){
          return is_root;
        }
        Node GetParent(){
          return parent;
        }

      };
