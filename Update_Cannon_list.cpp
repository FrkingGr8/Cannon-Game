#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

struct coordinates{
    int x;
    int y;
};

int board[8][8];

void intialise();
tuple<vector<int>, vector<int> > Update_C_list(tuple<char, int, int, char, int, int>, vector<coordinates>, vector<coordinates>);


int main(){

    tuple<vector<int>, vector<int> > ans;
    tuple<char, int, int, char, int, int> move;
    vector<coordinates> Clist1, Clist2;

    ans = Update_C_list(move, Clist1, Clist2);

    return 0;
}

void initialise(){
    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            board[i][j] = 0;
        }
    }
    board[0][0] = -2; board[0][2] = -2;
}

tuple<vector<int>, vector<int> > Update_C_list(tuple<char, int, int, char, int, int>move, vector<int>Clist1, vector<int>Clist2){

}

