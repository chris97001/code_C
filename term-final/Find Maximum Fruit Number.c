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