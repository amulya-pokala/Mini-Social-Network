#ifndef LINKEDLISTNODE_H_INCLUDED
#define LINKEDLISTNODE_H_INCLUDED

typedef int ElementType;
typedef struct linkedListNode LinkedListNode;

// Define Structure LinkedListNode
struct linkedListNode
{
    ElementType data;
    LinkedListNode *next;
};

LinkedListNode* createLinkedListNode(ElementType data);
LinkedListNode* insertLinkedListNodeInBegin(LinkedListNode *head, ElementType data);
LinkedListNode* insertLinkedListNodeInEnd(LinkedListNode *head, ElementType data);
LinkedListNode* deleteFirstLinkedListNode(LinkedListNode *head);
LinkedListNode* destroyLinkedListNodes(LinkedListNode *head);
void traverseLinkedList(LinkedListNode *head);
#endif // LINKEDLISTNODE_H_INCLUDED
