#include <stdlib.h>

typedef struct{
    size_t size;
    size_t offset;
    unsigned char *memory;
}arena;

arena setArena(size_t size){

    arena a;

    a.size = size;
    a.offset = 0;
    a.memory = malloc(size);
    if(a.memory == NULL) {a.size = 0;}

    return a;
    
}

void *arenaAlloc(arena *arena, size_t size){
    if(arena->offset + size > arena->size){
        return NULL;
    }

    char *ptr = (char*)arena->memory + arena->offset;
    arena->offset += size;

    return ptr;

}

void freeArena(arena *arena){
    free(arena->memory);    
    arena->offset = 0;
    arena->size = 0;
    arena->memory = NULL;
}

void resetArena(arena *arena){
    arena->offset = 0;
}