#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct element {                        // elements of the stack
        int data;
        struct element *next;   // point to the next element in the stack
};

struct head {
        int size;                               // record the size of the stack
        struct element *next;   // point to the bottom element in the stack if there is any
        struct element *top;    // point to the top of the stack
};

void print_stack(struct head *stack_p);
void push(struct head *stack_p, int data);      // put an element to the top of the stack
struct element *pop(struct head *stack_p);      // remove an element from the top of the stack

int main(void) {
        // stack declaration
        struct head stack_head;
        stack_head.size = 0;
        stack_head.next = NULL;
        stack_head.top = NULL;

        // read instructions
        int num, data;
        char command[5];
        scanf("%d", &num);
        for (int i = 0; i < num; ++i) {
                scanf("%4s", command);
                if (strcmp(command, "push") == 0) {     // push command, call push()
                        scanf("%d", &data);
                        push(&stack_head, data);
                }
                else if (strcmp(command, "pop") == 0) { // pop command, call pop()
                        struct element *e = pop(&stack_head);
                        free(e);
                }
        }
        print_stack(&stack_head);
        return 0;
}

void print_stack(struct head *stack_p) {
        printf("%d\n", stack_p->size);
        for (struct element *ptr = stack_p->next; ptr != NULL; ptr = ptr->next)
                printf("%d ", ptr->data);
}
// Your code goes here
void push(struct head *stack_p, int data) // create an element and push it to the top of the stack
{   
    (stack_p->size)++;
    struct element *new_stack=(struct element*)malloc(sizeof(struct element));
    new_stack->data=data;
    new_stack->next=NULL;
    if(stack_p->next==NULL)//first element push
    {
        stack_p->next=new_stack;
        stack_p->top=new_stack;
    } 
    else
    {
        stack_p->top->next=new_stack;//make original top stack points to new stack
        stack_p->top=new_stack;//let stack_p stay bottom,only use stack_p->top to link the list(we need stack_p for print()to get the bottom stack )
    }
}
struct element* pop(struct head *stack_p) // return the element which is popped from the stack
{   
    (stack_p->size)--;
    struct element* stack_newtop=stack_p->next;
    struct element* stack_pop=stack_p->top;
    while(stack_newtop->next==NULL||stack_newtop->next->next!=NULL)//*very importan*there's only 1 element and we pop, the action of accessing stack_newtop->next->next would cause error
    {
        if(stack_newtop->next==NULL)
        {
            stack_p->next=NULL;
            return stack_pop;
        }
        stack_newtop=stack_newtop->next;
    }
    stack_newtop->next=NULL;
    stack_p->top =stack_newtop;//stack_newtop is the stack right before stack_top(new stack top)
    return stack_pop;
}