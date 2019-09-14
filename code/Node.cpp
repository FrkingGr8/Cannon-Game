#include "commonlib.h"

class Node{
    private:
        vector<vector<int> > board_config;
    public:
        Node *list;

        void SetBoard(vector<vector<int> > temp){
            board_config = temp;
        }

        vector<vector<int> > Get_board(){return board_config;}

};