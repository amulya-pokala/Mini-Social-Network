#include "trie.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <iostream>
using namespace std;
char WORD[100];
int t,count1;
TNode *createTrieNode()
{
        TNode* tnode1=(TNode*)malloc(sizeof(TNode));
        for(int i=0;i<26;i++) tnode1->next[i]=NULL;
        tnode1->isEOW=false;
        return tnode1;
}

bool insertWordInTrie(TNode *root, char *word,int index)
{
    TNode* temp=(TNode*)malloc(sizeof(tnode));
    temp=root;
    for(int i=0;word[i]!='\0';i++)
    {
        int num=word[i]-'a';
        if(temp->next[num]==NULL)
            temp->next[num]=createTrieNode();
        temp=temp->next[num];
    }
    if(temp->isEOW==true) return false;
    temp->isEOW=true;
    temp->index=index;
    return true;
}
int returnVertex(TNode* root,char* name)
{
    TNode* temp=(TNode*)malloc(sizeof(tnode));
    temp=root;
    for(int i=0;name[i]!='\0';i++)
    {
        int num=name[i]-'a';
        if(temp->next[num]==NULL)
            temp->next[num]=createTrieNode();
        temp=temp->next[num];
    }
    return temp->index;
}
bool rinsertWordInTrie(TNode* root,char* word)
{
    if(word[0]=='\0')root->isEOW=true;
    if(root->next[word[0]-'a']==NULL)
    {
        root->next[word[0]-'a']=createTrieNode();
    }
    bool b=rinsertWordInTrie(root->next[word[0]-'a'],word+1);

}
void printWordsInTrie(TNode *root)
{

       if(root==NULL) return;
       if(root->isEOW==true)
        {
            printf("%s\n",WORD);
        }

        for(int i=0;i<26;i++)
        {
            if(root->next[i]!=NULL)
                {

                    WORD[t]='a'+i;
                    t++;
                    WORD[t]='\0';
                    printWordsInTrie(root->next[i]);
                }
        }
        t--;
}
void printWordsInTriePrefix(TNode *root,char* prefix)
{

       if(root==NULL) return;
       if(root->isEOW==true)
        {

          // printf("%s%s\n",prefix,WORD);
           count1++;
        }

        for(int i=0;i<26;i++)
        {
            if(root->next[i]!=NULL)
                {

                    WORD[t]='a'+i;
                    t++;
                    WORD[t]='\0';
                    printWordsInTriePrefix(root->next[i],prefix);
                }
        }
        t--;
}

int printPrefix(TNode *root,char* prefix)
{
    for(int i=0;prefix[i]!='\0';i++)
    {
        if(root!=NULL)
        root=root->next[prefix[i]-'a'];

    }
    count1=0;
    printWordsInTriePrefix(root,prefix);
    return count1;
}
bool deleteWordFromTrie(TNode *root,char *word)
{

}
bool isLeaf(TNode *root)
{
    for(int i=0;i<ALPHABET_SIZE;i++)
        if(root->next[i]!=NULL)
            return false;
    return true;
}
















