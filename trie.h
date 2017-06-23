#ifndef TRIE_H_INCLUDED
#define TRIE_H_INCLUDED

#include <stdlib.h>

#define	ALPHABET_SIZE	26
typedef struct tnode TNode;
struct tnode
{
	bool isEOW;
	int index;
	TNode *next[ALPHABET_SIZE];
};

TNode *createTrieNode();
bool insertWordInTrie(TNode *root, char *word,int index);
void printWordsInTrie(TNode *root);
bool rinsertWordInTrie(TNode *root, char *word);
bool deleteWordFromTrie(TNode *root, char *word);
int printPrefix(TNode *root,char* prefix);
int returnVertex(TNode* root,char* name);
void printWordsInTriePrefix(TNode *root,char* prefix);

#endif // TRIE_H_INCLUDED
