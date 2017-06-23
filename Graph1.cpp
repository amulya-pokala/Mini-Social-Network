#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "LinkedListNode.h"
#include "Graph.h"
int levels[100];
int parent[100];
Graph *createGraph(int nv)
{
    Graph *g = new Graph;
    g->nv = nv;
    g->ne = 0;
    g->heads =(LinkedListNode**) malloc(nv * sizeof(LinkedListNode *));
    int i;
    for(i=0;i<nv;i++)
        g->heads[i] = NULL;
    return g;
}

/*Graph *destroyGraph(Graph *g)
{
    int i;
    for(i=0;i<g->nv;i++)
    {
        g->heads[i] = destroyLinkedListNodes(g->heads[i]);
    }

    // Free the Heads array
    free(g->heads);
    free(g);

}*/

void insertEdge(Graph *g, int u, int v)
{
    g->heads[u] = insertLinkedListNodeInBegin(g->heads[u], v);
    g->heads[v] = insertLinkedListNodeInBegin(g->heads[v], u);
    g->ne++;
}

/*void deleteEdge(Graph *g, int u, int v)
{
    g->heads[u] = deleteLLNode(g->heads[u], v);
    g->heads[v] = deleteLLNode(g->heads[v], u);
    g->ne--;
}*/

void printGraph(Graph *g)
{
    int i;
    for(i=0; i<g->nv; i++)
    {
        printf("\n%d :", i);
        traverseLinkedList(g->heads[i]);
    }
}

/*void bfs(Graph *g)
{
    bool visited[g->nv];
    memset(visited,0,sizeof(visited));
    Queue *q=createQueue();
    enqueue(q,0);
    visited[0]=true;
    printf("\nBFS\n");
    while(!isQueueEmpty(q))
    {
        int v=dequeue(q);
        printf("%d ",v);

        LinkedListNode *h=g->heads[v];
        while(h!=NULL){
                if(visited[h->data]!=true){
                    enqueue(q,h->data);
                    visited[h->data]=true;}
                    h=h->next;
}
}
}

void dfsRecursive(Graph *g, int v, bool visited[])
{
    if(visited[v]==true) return;
    printf("%d ",v);
    visited[v]=true;
    LinkedListNode *h=g->heads[v];
    while(h!=NULL)
    {
        dfsRecursive(g,h->data,visited);
        h=h->next;
    }
}

void dfs(Graph *g)
{
    printf("\nDFS: ");
    int i;
    bool visited[g->nv];
    for(i=0; i<g->nv; i++)
        visited[i] = false;

    for(i=0; i<g->nv; i++)
        dfsRecursive(g, i, visited);
}

void printShortestPath(Graph *g, int s, int d)
{
    printf("\nShortest Path between %d & %d: ", s, d);
    g=g->heads[s];
    bfs(g);
}*/
