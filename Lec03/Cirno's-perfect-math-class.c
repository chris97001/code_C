#include <stdio.h>
int main() 
{
    int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	printf("%04d %04d %04d", a, a-b+c, a-b+c-d);
}