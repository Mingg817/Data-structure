#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int data;
    struct ListNode *next;
};

struct ListNode *createlist()
{
    int Stack[10];
    int Stack_size = -1;
    do
    {
        Stack_size += 1;
        scanf("%d", &Stack[Stack_size]);
    } while (Stack[Stack_size]!=-1);
    struct ListNode *head;
    struct ListNode *p;
    p = head;
    struct ListNode *Node;
    for (int i = Stack_size-1; i >= 0;i--)
    {

        Node = (struct ListNode *)malloc(sizeof(struct ListNode));
        Node->next = NULL;
        Node->data = Stack[i];

        if (i == Stack_size - 1)
        {
            head = Node;
            p = Node;
        }
        else{
            p->next = Node;
            p = p->next;
        }
        
     }
    return head;
}

int main()
{
    struct ListNode *p, *head = NULL;

    head = createlist();
    for (p = head; p != NULL; p = p->next)
        printf("%d ", p->data);
    printf("\n");

    return 0;
}

/* 你的代码将被嵌在这里 */