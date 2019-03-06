#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "../log/log.h"
#include "../stack/stack.h"
#include "nQueens.h"

int main(void) {
    int solCount[5] = {2, 10, 4, 40, 92};
    int i=0, c=0;
    for (int bs=4; bs<9; bs++) {
        stack* sol = stack_new();
        int* board = calloc(bs, sizeof(int));
        placeQueen(bs, sol, 0, board);
        
        if (s_size(sol) != solCount[i]) {
            Assert(false, __func__, "while calculating board size %i found wrong solution count of %i", bs, c);
        }
        while (s_size(sol) != 0) {
            int* board = s_pop(sol);
            free(board);
        }
        i++;
        free(sol);
    }
}

