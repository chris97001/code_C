#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *good_types[] = {
    "Juice",
    "Wine",
    "Laptop"
};

void *produce(void *top_of_stack, const char *good_type, size_t count);
void *consume(void *top_of_stack, size_t count);
void list_remain(void *top_of_stack);

int main(){
    char record[64], *job, *good;
    size_t count;
    void *top_of_stack = NULL;

    while(fgets(record, 64, stdin)){
        job = strtok(record, " ");
        if(!strcmp(job, "Produce")){
            good = strtok(NULL, " ");
            count = atol(strtok(NULL, " "));

            for(int i = 0; i < 3; i++){
                if(!strcmp(good, good_types[i])){
                    top_of_stack = produce(top_of_stack, good_types[i], count);
                    break;
                }
            }
        }
        else if(!strcmp(job, "Consume")){
            count = atol(strtok(NULL, " "));
            top_of_stack = consume(top_of_stack, count);
        }
    }

    list_remain(top_of_stack);

    return 0;
}
// Your code goes here
//You may need to define your own struct here.
int store_count=0;
struct good{
    char gtype[10];
    int gcount;
    struct good *next;
};
struct good *head=NULL;

void gproduce(const char *good_type, const size_t count)
{
    if(head!=NULL && !strcmp(head->gtype,good_type))
    {
        head->gcount+=count;
        return ;
    }
    struct good *New=(struct good*)malloc(sizeof(struct good));
    New->gcount=count;
    strcpy(New->gtype,good_type);
    New->next=head;
    head=New;
}

void *produce(void *top_of_stack, const char *good_type, const size_t count)
{
    void *re = NULL;
    store_count+=count;
    gproduce(good_type,count);
    return re;
}


void gconsume(const size_t count)
{
    for(int i=0;i<count;i++)
    {
        head->gcount--;
        if(head->gcount==0)
            head=head->next;
    }
}
void *consume(void *top_of_stack, const size_t count)
{
    void *re = NULL;
    store_count-=count;
    gconsume(count);
    return re;
}

void list_remain(void *top_of_stack)
{
    if(store_count==0)
    {
        printf("Empty\n");
        return ;
    }
    else
    {
        while(head!=NULL)
        {
            printf("%s x %d\n",head->gtype,head->gcount);
            head=head->next;
        }
    }
}
