#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int c=0,r=0;
int find(char key,char a[10],int res[10])
{

    for(int i=0;i<c;i++)
    {
        if(a[i]==key)
        {
            
            return res[i];
        }
    }
}
void replace(char key,char a[10],int res[10],int val)
{
    

    for(int i=0;i<c;i++)
    {
        if(a[i]==key)
        {
            
            res[i]=val;
        }
    }

}
int calc(int a,int b,char s)
{
    int result;
    switch(s)
    {
        case '+':result=a+b;
                 return result;
        case '-':result=a-b;
                 return result;
        case '*':result=a*b;
                 return result;
        case '/':result=a/b;
                 return result;    
    }
}
void clear(char string[10])
{
    for(int i=0;i<strlen(string);i++)
    {
        string[i] = 0;
    }
}
int main()
{
    int n,response,temp,temp1,line=0;
    char s[20],a,b,constant[10];
    int sum[10];
    FILE *fp,*fp1;
    fp=fopen("inputInstruction.txt","r");
    while(1)
    {
        if(feof(fp))
        {
            return 0;
            
        }
        fscanf(fp,"%c %c %s",&a,&b,s);
        line++;
        //printf("\n%c %c %c %c %c",a,b,s[0],s[1],s[3]);
            if(strlen(s)<=2)
            {
                if(line>1)
                {
                    if(isdigit(s[1]))
                    {
                       // printf("\n%c = %d",b,(int)(s[1]-'0'));
                        constant[c++]=b;
                        sum[r++]=(int)(s[1]-'0');
                    }
                    else
                    {
                        response = find(s[1],constant,sum);
                       // printf("\n%c = %d",b,response);
                        constant[c++]=b;
                        sum[r++]=response;
                    }
                    
                }
                else
                {
                    
                       // printf("\n%c = %d",a,atoi(s));
                        constant[c++]=a;
                        sum[r++]=atoi(s);
                    
                    
                }
                
                    
            }
            else
            {
                if(isdigit(s[1])&&isdigit(s[3]))
                {
                    response=calc((int)(s[1]-'0'),(int)(s[3]-'0'),s[2]);
                    printf("\n%c = %d%c%d",b,(int)(s[1]-'0'),s[2],(int)(s[3]-'0'));
                }
                else if(isdigit(s[1]))
                {
                    response = find(s[3],constant,sum);
                    temp = calc((int)(s[1]-'0'),response,s[2]);
                    printf("\n%c = %d%c%d",b,response,s[2],(int)(s[1]-'0'));
                    constant[c++]=b;
                    sum[r++]=temp;
                }
                else if(isdigit(s[3]))
                {
                    response = find(s[1],constant,sum);
                    temp = calc(response,(int)(s[3]-'0'),s[2]);
                    printf("\n%c = %d%c%d",b,response,s[2],(int)(s[3]-'0'));
                    constant[c++]=b;
                    sum[r++]=temp;
                }
                else
                {
                    response = find(s[1],constant,sum);
                    temp = find(s[3],constant,sum);
                    temp1= calc(response,temp,s[2]);
                    printf("\n%c = %d%c%d",b,response,s[2],temp1);
                    constant[c++]=b;
                    sum[r++]=temp;
                }
                
                
            }
            

    }
    
    
    return 0;
}