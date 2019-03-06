#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "../log/log.h"
#include "../stack/stack.h"
#include "nQueens.h"

bool validQueen(int* board, int r, int qC);
int* boardCopy(int* board, int boardSize);

bool validQueen(int* board, int r, int qC) {
    for (int i=0; i<r; i++) {
        if (board[i] == qC || abs(i-r) == abs(qC-board[i])) return false;
    }
    return true;
}

void placeQueen(int boardSize, stack* sol, int r, int* board) {
    if (r == boardSize) {
        s_push(sol, board);
        return;
    }
    int c;
    for (c=0; c<boardSize; c++) {
        if (validQueen(board, r, c)) {
            int* boardNew = boardCopy(board, boardSize);
            boardNew[r] = c;
            placeQueen(boardSize, sol, r+1, boardNew);
        }
    }
}

int* boardCopy(int* board, int boardSize) {
    int* r = calloc(boardSize, sizeof(int));
    if (r == NULL) Assert(false, __func__, "calloc error");
    bcopy(board, r, boardSize*sizeof(int));
    return r;
}
