#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *create(struct Node *head, int x)
{
    struct Node *temp, *ptr = head;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if (head == NULL)
        head = temp;
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
    return head;
}

struct Node *removeNthFromEnd(struct Node *head, int B)
{
    int len = 0;
    struct Node *tmp = head;
    while (tmp != NULL)
    {
        len++;
        tmp = tmp->next;
    }
    if (B > len)
    {
        printf("Length of the linked list is %d", len);
        printf(" we can't remove %dth node from the", B);
        printf(" linked list\n");
        return head;
    }
    else if (B == len)
    {
        return head->next;
    }
    else
    {
        int diff = len - B;
        struct Node *prev = NULL;
        struct Node *curr = head;
        for (int i = 0; i < diff; i++)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        return head;
    }
}

void display(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct Node *head = NULL;
    head = create(head, 1);
    head = create(head, 2);
    head = create(head, 3);
    head = create(head, 4);
    head = create(head, 5);
    int n = 2;
    printf("Linked list before modification: \n");
    display(head);
    head = removeNthFromEnd(head, 2);
    printf("Linked list after modification: \n");
    display(head);
    return 0;
}
