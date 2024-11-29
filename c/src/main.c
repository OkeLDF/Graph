#include <stdlib.h>
#include <stdio.h>

#include "graph.h"

#define self graph

int main(){
    Graph* graph = newGraph(5);

    graph->print(self);

    graph->addEdge(&self, 0, 3);
    graph->addEdge(&self, 0, 2);

    graph->print(self);

    graph->destroy(self);

    return 0;
}