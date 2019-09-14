#include "commonlib.h"

int Evaluation(int a, int b, int c, int d){
    return a + b + c + d;
}
// Initial values of 
// Aplha and Beta 
const int MAX = 1000; 
const int MIN = -1000; 

int minimax(int depth, Node node, bool maximizingPlayer, int values[], int alpha, int beta) { 
    
    if (depth == 3)//returns the value of nodes at depth 3 using evaluation function to calculate the value of board 
        return Evaluation(1, 2, 3, 4); 
  
    if (maximizingPlayer) { 
        int best = MIN; 
  
        // Recur for all the child
        for (int i = 0; i < node.list.size(); i++) { 
              
            int val = minimax(depth + 1, *node.list[i],  
                              false, values, alpha, beta); 
            best = max(best, val); 
            alpha = max(alpha, best); 
  
            // Alpha Beta Pruning 
            if (beta <= alpha) 
                break; 
        } 
        return best; 
    }else{ 
        int best = MAX; 
  
        // Recur for left and 
        // right children 
        for (int i = 0; i < node.list.size(); i++) 
        { 
            int val = minimax(depth + 1, *node.list[i], 
                              true, values, alpha, beta); 
            best = min(best, val); 
            beta = min(beta, best); 
  
            // Alpha Beta Pruning 
            if (beta <= alpha) 
                break; 
        } 
        return best; 
    } 
} 