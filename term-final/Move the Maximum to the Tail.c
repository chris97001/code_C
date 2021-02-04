#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node* next;
};
struct node* head = NULL;
struct node* tail = NULL;
void MoveToTail();

int main(void) { 
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        struct node* tmp =(struct node*) malloc(sizeof(struct node));
        scanf("%d", &tmp->val);
        tmp->next = NULL;
        if(i == 1)
            head = tmp;
        else
            tail->next = tmp;
        tail = tmp;
    }
    MoveToTail();
    for(struct node* cur = head; cur != NULL; cur = cur->next)
        printf("%d ", cur->val); 
    return 0;
    
}
// Your code goes here
void MoveToTail() 
{
    // "struct node* head" and "struct node* tail" are in global
    // you can use this two pointers to do this problem
    struct node_M
    {
        struct node* mid;
        struct node* next;
        struct node* prev;
    };
    struct node_M big;
    big.prev=NULL;
    big.mid=head;
    big.next=head->next;
    for(struct node* cur=head->next;cur!=NULL; cur=cur->next)
    {
        if(cur->val>big.mid->val)
        {
            big.prev=big.mid;
            big.mid=cur;
            big.next=cur->next;
        }
    }
    if(big.mid->val==tail->val) return;
    if(big.prev!=NULL)
        big.prev->next=big.next;
    else
        head=big.next;
    big.mid->next=NULL;
    tail->next=big.mid;
    return ;
}