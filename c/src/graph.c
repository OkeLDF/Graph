#include "graph.h"

void Graph_destroy(Graph* graph){
    int i = 0;
    for(; i < graph->num_vertexes; i++){
        if(graph->vertexes[i] == NULL) continue;
        graph->vertexes[i]->destroy(graph->vertexes[i]);
    }

    free(graph->vertexes);
    free(graph);
}

void Graph_addEdge(Graph** graph, int src, int dest){
    if(src < 0 || src >= (*graph)->num_vertexes){
        error("Invalid source vertex");
        return;
    }

    if(dest < 0 || dest >= (*graph)->num_vertexes){
        error("Invalid destiny vertex");
        return;
    }

    if((*graph)->vertexes[src] == NULL) (*graph)->vertexes[src] = newListNode(dest);
    else (*graph)->vertexes[src]->add(&((*graph)->vertexes[src]), dest);
}

void Graph_print(Graph* graph){
    int i = 0;

    printf("Graph in <0x%x> {\n", graph);

    for(; i < graph->num_vertexes; i++){
        ListNode* node = graph->vertexes[i];
        printf("  Vertex %d  { ", i);

        while(node != NULL){
            printf(" %d", node->value);
            node = node->next;
            if(node != NULL) printf(",");
        }
        puts("  }");
    }

    printf("\n}\n");
}

Graph* newGraph(int num_vertexes){
    Graph* self = (Graph*) malloc(sizeof(Graph));

    self->num_vertexes = num_vertexes;
    self->vertexes = (ListNode**) malloc(num_vertexes * sizeof(ListNode*));

    int i = 0;
    for(; i < num_vertexes; i++) self->vertexes[i] = NULL;

    self->addEdge = Graph_addEdge;
    self->print = Graph_print;
    self->destroy = Graph_destroy;

    return self;
}