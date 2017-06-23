/*#include "trie.h"
#include "Graph.h"
#include <iostream>
#include <stdbool.h>
#include <string>
using namespace std;
char* indexArray[10000];
int Vertices;
void newNodes()
{

}
bool isNamePresent(TNode* root,char* name,int index)
{
    /*if word is present already, it returns false
    else it inserts word in trie and returns false
    if(insertWordInTrie(root,name,Vertices)){
        Vertices++;
        indexArray[Vertices-1]=name;
        return false;
    }
    else return true;
}
int giveTheVertexOfWord(TNode* root,char* name)
{
    return returnVertex(root,name);
}
void makeFriendship(TNode* root,char* name1,char* name2,Graph* g)
{
    isNamePresent(root,name1,Vertices);
    isNamePresent(root,name2,Vertices);
    int v1=giveTheVertexOfWord(root,name1),v2=giveTheVertexOfWord(root,name2);
    insertEdge(g,v1,v2);
}
void printFriends(TNode* root,char* name,Graph* g)
{
    int v=giveTheVertexOfWord(root,name);
    LinkedListNode* temp=g->heads[v];
    cout<<name<<"->" ;
    while(temp!=NULL)
    {
        cout<<indexArray[temp->data]<<",";
        temp=temp->next;
    }
}*/
