#ifndef MINIMAX_H
#define MINIMAX_H

#include "commonlib.h"

int Evaluation(int a, int b, int c, int d);
int minimax(int depth, Node node, bool maximizingPlayer, int values[], int alpha, int beta);

// Initial values of
// Aplha and Beta
const int MAX = 1000;
const int MIN = -1000;

#endif
