#include "libs/arena_cqdlulis.h"
#include <stdio.h>

int main(){

    arena arena1 = setArena(1024);

    int *x = arenaAlloc(&arena1, sizeof(int));

    freeArena(&arena1);

    return 0;
}