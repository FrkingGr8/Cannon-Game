#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>

using namespace std;
struct coord{
  int x,y;
};

typedef tuple<coord,coord,coord> CANNON;
typedef tuple<char, int, int, char, int, int> MOVE;

int board[8][8];

void initialise();
tuple<vector<CANNON>, vector<CANNON> > Update_C_list(MOVE);
tuple<vector<CANNON>, vector<CANNON> > Update(int, MOVE);
vector<CANNON> Get_list(int);

bool Search(vector<CANNON>, CANNON);

void print_board();
void print_cannon(vector<CANNON>);


int main(){

    tuple<vector<CANNON>, vector<CANNON> > ans;
    MOVE move = make_tuple('s', 2, 1, 'm', 3, 1);

    initialise();

    ans = Update_C_list(move);

    print_board();

    return 0;
}

//Initialising the board
void initialise(){
    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            board[i][j] = 0;
        }
    }
    //Position of townhall
    board[0][0] = -2; board[0][2] = -2; board[0][4] = -2; board[0][6] = -2;
    board[7][1] = 2; board[7][3] = 2; board[7][5] = 2; board[7][7] = 2;

    //Position of soldiers
    //White
    board[0][1] = -1; board[1][1] = -1; board[2][1] = -1;
    board[0][3] = -1; board[1][3] = -1; board[2][3] = -1;
    board[0][5] = -1; board[1][5] = -1; board[2][5] = -1;
    board[0][7] = -1; board[1][7] = -1; board[2][7] = -1;
    //Black
    board[7][0] = 1; board[6][0] = 1; board[5][0] = 1;
    board[7][2] = 1; board[6][2] = 1; board[5][2] = 1;
    board[7][4] = 1; board[6][4] = 1; board[5][4] = 1;
    board[7][6] = 1; board[6][6] = 1; board[5][6] = 1;

}

tuple<vector<CANNON>, vector<CANNON> > Update_C_list(MOVE move){
    int x = get<1>(move);
    int y = get<2>(move);
    int type = board[x][y];

    return Update(type, move);
}

tuple<vector<CANNON>, vector<CANNON> > Update(int type, MOVE move){
    int src_x = get<1>(move), src_y = get<2>(move);
    int dest_x = get<4>(move), dest_y = get<5>(move);

    //updating the board from the move we get

    if(get<3>(move) == 'B'){
        board[dest_x][dest_y] = 0;
    }else{
        board[src_x][src_y] = 0;
        board[dest_x][dest_y] = type;
    }

    vector<CANNON> Clist1 = Get_list(type);
    vector<CANNON> Clist2 = Get_list(-1*type);
    tuple<vector<CANNON>, vector<CANNON> > ans;
    ans = make_tuple(Clist1, Clist2);

    cout<<"Of type:- "<<type<<endl;
    //print_cannon(Clist1);

    cout<<"Of type:- "<<-1*type<<endl;
    //print_cannon(Clist2);
    
    return ans;
}

bool Search(vector<CANNON> list, CANNON temp){
        coord middle_temp_cannon = get<1>(temp);
        coord first_temp_cannon = get<0>(temp);
        coord last_temp_cannon = get<2>(temp);

    for(int i = 0; i<list.size(); i++){
        CANNON t = list[i];
        coord middle_list_cannon = get<1>(t);
        coord first_list_cannon = get<0>(t);
        coord last_list_cannon = get<2>(t);

        if(middle_list_cannon.x == middle_temp_cannon.x && middle_temp_cannon.y == middle_list_cannon.y){
            if(first_list_cannon.x == first_temp_cannon.x && first_temp_cannon.y == first_list_cannon.y){
                if(last_list_cannon.x == last_temp_cannon.x && last_temp_cannon.y == last_list_cannon.y){
                    return true;
                }
            }else{
                if(first_temp_cannon.x == last_list_cannon.x && last_list_cannon.y == first_temp_cannon.y){
                    if(last_temp_cannon.x == first_list_cannon.x && first_list_cannon.y == last_temp_cannon.y){
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

vector<CANNON> Get_list(int type){
    vector<CANNON> list;
    int n = 8;
    int m = 8;

    for(int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            if(board[i][j] == type){
                if(i<n-1 && i>0 && j<m-1 && j>0){
                    CANNON temp;
                    coord F, M, L;

                    M.x = i; M.y = j;

                    //Vertical Cannon
                    F.x = i+1; F.y = j;
                    L.x = i-1; L.y = j;
                    if(board[F.x][F.y] == type && board[L.x][L.y] == type){
                        //cout<<i<<" "<<j<<" "<<type<<endl;
                        CANNON t = make_tuple(F, M, L);
                        bool res = Search(list, t);
                        //cout<<F.x<<" "<<F.y<<" -> "<<M.x<<" "<<M.y<<" -> "<<L.x<<" "<<L.y<<endl;                        
                        if(res == false){
                            list.push_back(t);
                            //CANNON temp = list[0];
                            //coord F = get<0>(temp), M = get<1>(temp), L = get<2>(temp);
                            //cout<<list.size()<<endl;
                            //cout<<F.x<<" "<<F.y<<" -> "<<M.x<<" "<<M.y<<" -> "<<L.x<<" "<<L.y<<endl;                        
                        }
                    }

                    //Horizontal Cannon
                    F.x = i; F.y = j+1;
                    L.x = i; L.y = j-1;
                    if(board[F.x][F.y] == type && board[L.x][L.y] == type){
                        //cout<<i<<" "<<j<<" "<<type<<endl;                        
                        CANNON t = make_tuple(F, M, L);
                        bool res = Search(list, t);
                        if(res == false){
                            list.push_back(t);
                        }
                    }

                    //Main Diagonal Cannon
                    F.x = i-1; F.y = j-1;
                    L.x = i+1; L.y = j+1; 
                    if(board[F.x][F.y] == type && board[L.x][L.y] == type){
                        //cout<<i<<" "<<j<<" "<<type<<endl;
                        CANNON t = make_tuple(F, M, L);
                        bool res = Search(list, t);
                        if(res == false){
                            list.push_back(t);
                        }
                    }

                    //Secondary Diagonal Cannon
                    F.x = i-1; F.y = j+1;
                    L.x = i+1; L.y = j-1;
                    if(board[F.x][F.y] == type && board[L.x][L.y] == type){
                        //cout<<i<<" "<<j<<" "<<type<<endl;
                        CANNON t = make_tuple(F, M, L);
                        bool res = Search(list, t);
                        if(res == false){
                            list.push_back(t);
                        }
                    }
                }
                if(i == 0 || i == n-1){ //taking only first or last row. Hence only horizontal cannon possible.
                    if(j == 0 || j == m-1){
                        continue;
                    }else{
                        coord M, F, L;
                        M.x = i; M.y = j;
                        F.x = i; F.y = j+1;
                        L.x = i; L.y = j-1;
                        
                        if(board[F.x][F.y] == type && board[L.x][L.y] == type){
                            //cout<<i<<" "<<j<<" "<<type<<endl;
                            CANNON t = make_tuple(F, M, L);
                            bool res = Search(list, t);
                            if(res == false){
                                list.push_back(t);
                            }
                        }
                    }
                }
                if(j == 0 || j == m-1){//taking only last or first colum. Hence only vertical cannon possible.
                    if(i == 0 || i == n-1){
                        continue;
                    }else{
                        coord M, F, L;
                        M.x = i; M.y = j;
                        F.x = i+1; F.y = j;
                        L.x = i-1; L.y = j;

                        if(board[F.x][F.y] == type && board[L.x][L.y] == type){
                            //cout<<i<<" "<<j<<" "<<type<<endl;                            
                            CANNON t = make_tuple(F, M, L);
                            bool res = Search(list, t);
                            //cout<<res;
                            if(res == false){
                                list.push_back(t);
                            }
                        }
                    }
                }
            }
        }
    }
    
    return list;
}

void print_cannon(vector<CANNON> list){
    for(int i = 0; i<list.size(); i++){
        CANNON temp = list[i];
        coord F = get<0>(temp), M = get<1>(temp), L = get<2>(temp);
        cout<<F.x<<" "<<F.y<<" -> "<<M.x<<" "<<M.y<<" -> "<<L.x<<" "<<L.y<<endl;
    }
}


void print_board(){
    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
