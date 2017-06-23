#include "LinkedListNode.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

LinkedListNode* createLinkedListNode(ElementType data)
{
    LinkedListNode *newNode = new LinkedListNode;
    newNode->next = NULL;
    newNode->data = data;
    return newNode;
}

LinkedListNode* insertLinkedListNodeInBegin(LinkedListNode *head, ElementType data)
{
    LinkedListNode *newNode = createLinkedListNode(data);
    newNode->next = head;
    return newNode;
}

LinkedListNode* insertLinkedListNodeInEnd(LinkedListNode *head, ElementType data)
{
    LinkedListNode *newNode = createLinkedListNode(data);
    if(head==NULL)
        return newNode;

    while(head->next!=NULL)
        head = head->next;

    head->next = newNode;
    return head;
}

LinkedListNode* deleteLLNode(LinkedListNode *head, int v)
{
    LinkedListNode *p=NULL, *c=head;
    if(head!=NULL){
        // First Node
        if(v== head->data)
        {
            p = head->next;
            free(head);
            return p;
        }

        while(c!=NULL){
            if(c->data==v){
                p->next = c->next;
                free(c);
                break;
            }
            p = c;
            c=c->next;
        }
    }
    return head;
}

LinkedListNode* deleteFirstLinkedListNode(LinkedListNode *head)
{
    assert(head!=NULL);
    LinkedListNode *first = head;
    head = head->next;
    free(first);
    return head;
}

LinkedListNode* destroyLinkedListNodes(LinkedListNode *head)
{
    LinkedListNode *next;
    while(head!=NULL)
    {
        next = head->next;
        free(head);
        head = next;
    }
    return NULL;
}

void traverseLinkedList(LinkedListNode *head)
{
    while(head!=NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}
