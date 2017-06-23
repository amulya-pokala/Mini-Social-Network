#include "trie.h"
#include "Graph.h"
#include <iostream>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;
struct nodes
{
    char* name;
};
char** indexArray;
int Vertices;
void init()
{
    indexArray = (char**)malloc(50000*sizeof(char*));
}
bool isNamePresent(TNode* root,char* name,int index)
{
    /*if word is present already, it returns false
    else it inserts word in trie and returns false*/
    if(insertWordInTrie(root,name,index)){
        Vertices++;
        return false;
    }
    return true;

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
   indexArray[v1]=(char*)malloc(strlen(name1)+1);
    strcpy(indexArray[v1],name1);
    indexArray[v2]=(char*)malloc(strlen(name2)+1);
    strcpy(indexArray[v2],name2);
    insertEdge(g,v1,v2);
}
void mutualFriends(Graph* g,char* name1,char* name2,TNode* root)
{
    int arr[1000],i=0;
    int v1=giveTheVertexOfWord(root,name1);int v2=giveTheVertexOfWord(root,name2);
    LinkedListNode* temp=g->heads[v1];
    while(temp!=NULL){
    LinkedListNode* temp1=g->heads[v2];
    while(temp1!=NULL)
    {
        if(temp1->data==temp->data)
        {
            arr[i]=temp->data;
            i++;
        }
        temp1=temp1->next;
    }
    temp=temp->next;
    }
    if(i>0)
    {
        cout<<"\n\n MUTUAL FRIENDS OF "<<name1<<" and "<<name2<<" are: ";
    for(int j=0;j<i;j++)
    {
        cout<<indexArray[arr[j]]<<" ";
    }
    }
    else cout<<name1<<" "<<name2<<" do not have any mutual friends\n";
    cout<<endl<<endl<<endl;
}
void printFriends(TNode* root,char* name,Graph* g)
{
    cout<<"\n---------------------------------\n";
    cout<<"FRIENDS OF "<<name<<" ARE: ";
    int v=giveTheVertexOfWord(root,name);
    LinkedListNode* temp=g->heads[v];
    cout<<"->" ;
    while(temp!=NULL)
    {
        cout<<indexArray[temp->data]<<" ";
        temp=temp->next;

    }
    cout<<endl<<endl;
}

int main()
{
    Graph* g=createGraph(50000);
    TNode* root=createTrieNode();
    init();
    FILE *fp=fopen("friendship.txt","r");
    char name1[50],name2[50];
    while (!feof(fp))
    {
        fscanf(fp,"%s %s",name1,name2);
        makeFriendship(root,name1,name2,g);
    }
    fclose(fp);

    while(1){
    cout<<"OPTIONS"<<endl;
    cout<<"\n--------------------------------------\n";
    cout<<"1-ENTER FREINDSHIP\n";
    cout<<"2-PRINT FRIENDS\n";
    cout<<"3-PRINT MUTUAL FRIENDS\n";
    cout<<"4-PRINT STATS\n";
    cout<<"5-EXIT\n\n\n";
    cout<<"-----------------------------------------\n";
    cout<<"enter any one of the option\n";
    int option;
    cin>>option;
    switch(option)
    {
        case 5:return 0;
        case 1:
            {
                char name1[50];
                char name2[50];
                cout<<"enter first name: ";
                cin>>name1;
                cout<<"\nenter second name: ";
                cin>>name2;
                cout<<endl;
                makeFriendship(root,name1,name2,g);
                break;
            }
        case 2:
            {
                char name[50];
                cout<<"\nenter name: ";
                cin>>name;
                cout<<endl;
                printFriends(root,name,g);
                break;
            }
        case 3:
            {
                char name1[50],name2[50];
                cout<<"enter first name: ";
                cin>>name1;
                cout<<"\nenter second name: ";
                cin>>name2;
                cout<<endl;
                mutualFriends(g,name1,name2,root);
            }

    }
    }
    return 0;
}
