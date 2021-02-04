/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20000

void find_fruit(char input[],char fruit[][15]);

int main(void) {
	char fruit[20][15] = {
        "guava",
        "litchi",
        "longan",
        "watermelon",
        "pomelo",
        "pear",
        "banana",
        "papaya",
        "pumpkin",
        "tomato",
        "mango",
        "kiwi",
        "persimmon",
        "cantaloupe",
        "strawberry",
        "grape",
        "peach",
        "orange",
        "coconut",
        "lemon"
    };
    char input[N];
    scanf("%s", input);
    find_fruit(input,fruit);
    return 0;
}
// Your code goes here
void find_fruit(char input[],char fruit[][15])
{
    int count[20]={};
    char* fruit_tok;
    fruit_tok=strtok(input,"+_+");
    while(fruit_tok!=NULL)
    {
        for(int i=0;i<20;i++)
            if(strcmp(fruit_tok,fruit[i])==0)
                count[i]++;
        fruit_tok=strtok(NULL,"+_+");
    }
    int max=0;
    for(int i=0;i<20;i++)
    {
        if(max<count[i])
            max=count[i];
    }
    for(int i=0;i<20;i++)
    {
        if(count[i]==max)
            printf("%s\n",fruit[i]);
    }
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
#define MESSAGE_LENGTH 64
#define NAME_LENGTH 10

struct timestamp {
    int hour, minute;
};

struct message_info {
    struct timestamp time;
    char name[NAME_LENGTH];
    char message[MESSAGE_LENGTH];
};

int cmp(const void *a, const void *b);
void sort_message(struct message_info *m, int *total);

int main(void) {
    struct message_info m[100];
    int total;
    scanf("%d", &total);
    for(int i = 0; i < total; i++)
        scanf("%d:%d %s %[^\n]", &m[i].time.hour, &m[i].time.minute, m[i].name, m[i].message);
    sort_message(m, &total);
    for(int i = 0; i < total; i++)
        printf("%02d:%02d %s %s\n", m[i].time.hour, m[i].time.minute, m[i].name, m[i].message);
    return 0;
}
// Your code goes here
void sort_message(struct message_info *m, int *total)
{
    qsort(m,*total,sizeof(struct message_info*),cmp);
}
int cmp(const void *a, const void *b)
{
    int a_time=(((struct message_info*)a)->time.hour)*60+(((struct message_info*)a)->time.minute);
    int b_time=(((struct message_info*)b)->time.hour)*60+(((struct message_info*)b)->time.minute);
    return a_time-b_time;
}
*/


/*
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
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void permute(char* a,int l,int r);
int cmp(const void*,const void*);
void swap(char* a,char* b);
int main(void)
{
    char a[6];
    scanf("%s",a);
    qsort(a,strlen(a),sizeof(char),cmp);
    permute(a,0,strlen(a)-1);
    return 0;
}

void permute(char* a,int l,int r)
{
    if(l==r)
    {
        printf("%s\n",a);
        return ;
    }
    for(int i=l;i<=r;i++)
    {
        swap(&a[l],&a[i]);
        permute(a,l+1,r);
        swap(&a[l],&a[i]);
    }
}
int cmp(const void* a,const void* b)
{
    return *(char*)a-*(char*)b;//* in front of (char*)a is necessary.
}
void swap(char* a,char* b)
{
    char temp=*a;
    *a=*b;
    *b=temp;
}




