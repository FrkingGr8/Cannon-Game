#include "minimax.h"

int Evaluation(int a, int b, int c, int d){
    return a + b + c + d;
}

int minimax( Node *node, bool maximizingPlayer, int alpha, int beta) {

  vector<Node*> list = (*node).GetChildren();

    if ((*node).GetChildren().size() == 0){
        int t = Evaluation(1,2,3,4);
        (*node).SetEval(t);
        // cout<<t<<" "<<(*node).GetEval()<<endl;
        return t;

    }

    if (maximizingPlayer) {
        int best = MIN;
        // Recur for all the child
        for (int i = 0; i < list.size(); i++) {

            int val = minimax( (list[i]), false, alpha, beta);
            best = max(best, val);
            alpha = max(alpha, best);
            // Alpha Beta Pruning
            if (beta <= alpha)
                break;
        }
        (*node).SetEval(best);
        // cout<<best<<" "<<(*node).GetEval()<<endl;
        return best;
    }else{
        int best = MAX;

        // Recur for left and
        // right children
        for (int i = 0; i < list.size(); i++)
        {
            int val = minimax( (list[i]),
                              true, alpha, beta);
            best = min(best, val);
            beta = min(beta, best);
            // Alpha Beta Pruning
            if (beta <= alpha)
                break;
        }
        (*node).SetEval(best);
        // cout<<best<<" "<<(*node).GetEval()<<endl;
        return best;
    }
}
