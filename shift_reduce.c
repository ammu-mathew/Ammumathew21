#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int k = 0, z = 0, i = 0, j = 0, c = 0;
char a[16], ac[20], stk[15], act[10];
void check();

int main()
{
    int flag = 0;
    puts("GRAMMAR :");
    puts(" S->S+S \n S->S*S \n S->id");
    puts("enter input string ");
    gets(a);
    c = strlen(a);
    strcpy(act, "SHIFT");
    puts("stack  \t  input   \taction");
    printf("--------------------------------");
    printf("\n$\t%s\t",a);
    for (k = 0, i = 0; j < c; k++, i++, j++)
    {
        printf("%s",act);
        if (a[j] == 'i' && a[j + 1] == 'd')
        {
            stk[i] = a[j];
            stk[i + 1] = a[j + 1];
            stk[i + 2] = '\0';
            a[j] = ' ';
            a[j + 1] = ' ';
            printf("\n$%s\t%s$\t", stk, a);
            check();
        }
        else
        {
            stk[i] = a[j];
            stk[i + 1] = '\0';
            a[j] = ' ';
            printf("\n$%s\t%s$\t", stk, a);
            check();
        }
    }
    if (stk[0]=='S' && stk[1]=='\0')
    {
        printf("ACCEPT");
        exit(0);
    }
    else
    {
        printf("REJECT");
        exit(0);
    }
    return 0;
}
void check()
{
    strcpy(ac, "REDUCE BY S");
    for (z = 0; z < c; z++)
        if (stk[z] == 'i' && stk[z + 1] == 'd')
        {
            printf("%s->id",ac);
            stk[z] = 'S';
            stk[z + 1] = '\0';
            printf("\n$%s\t%s$\t", stk, a);
            j++;
        }
    for (z = 0; z < c; z++)
        if (stk[z] == 'S' && stk[z + 1] == '+' && stk[z + 2] == 'S')
        {
            printf("%s->S+S",ac);
            stk[z] = 'S';
            stk[z + 1] = '\0';
            stk[z + 2] = '\0';
            printf("\n$%s\t%s$\t", stk, a);
            i = i - 2;
        }
    for (z = 0; z < c; z++)
        if (stk[z] == 'S' && stk[z + 1] == '*' && stk[z + 2] == 'S')
        {
            printf("%s->S*S",ac);
            stk[z] = 'S';
            stk[z + 1] = '\0';
            stk[z + 1] = '\0';
            printf("\n$%s\t%s$\t", stk, a);
            i = i - 2;
        }
}
