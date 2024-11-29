#pragma once

#include <stdlib.h>
#include <stdio.h>

#include "utilities.h"
#include "list.h"

#define _gself_copy_ struct Graph*
#define _gself_ struct Graph**

typedef struct Graph {
    int num_vertexes;
    ListNode** vertexes;

    void (*addEdge)(_gself_, int src, int dest);
    void (*print)(_gself_copy_);
    void (*destroy)(_gself_copy_);
} Graph;

Graph* newGraph(int num_vertexes);