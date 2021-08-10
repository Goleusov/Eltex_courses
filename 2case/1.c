#include <stdio.h>       
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int Search(char string[], int *p)//поиск чисел
{
    int a=0, j=0, k=0, flag=1;
    int size = strlen(string);
    char buff[size];
     int arr[10];
    memset(buff,0,sizeof(buff));
    for(int i=0;i<size;i++)
   {
       if(isdigit(string[i]))
       {
       buff[j]=string[i];
       j++;
       }
       else if(buff[0]!=0)
        {
            p[k]=atoi(buff);
            printf("p %d\n",p[k]);
            memset(buff,0,sizeof(buff));
            k++;
            j=0;
        }
   }
   if(buff[0]!=0)
    p[k]=atoi(buff);
}   

int Trans_num(int num, int opt)//функция перевода чисел в нужную систему счисления
{
    int bin = 0, k = 1;
    
    switch (opt)
    {
    case 0:
     return 0;
        break;

    case 1:
        while (num)
    {
        bin += (num % 2) * k;
        k *= 10;
        num /= 2;
    }
    return bin;
        break;

    case 2:
        while (num)
    {
        bin += (num % 3) * k;
        k *= 10;
        num /= 3;
    }
    return bin;
        break;

    case 3:
        while (num)
    {
        bin += (num % 4) * k;
        k *= 10;
        num /= 4;
    }
    return bin;
        break;

    case 4:
        while (num)
    {
        bin += (num % 5) * k;
        k *= 10;
        num /= 5;
    }
    return bin;
        break;

    case 5:
        while (num)
    {
        bin += (num % 6) * k;
        k *= 10;
        num /= 6;
    }
    return bin;
        break;

    case 6:
        while (num)
    {
        bin += (num % 7) * k;
        k *= 10;
        num /= 7;
    }
    return bin;
        break;

    case 7:
        while (num)
    {
        bin += (num % 8) * k;
        k *= 10;
        num /= 8;
    }
    return bin;
        break;

    case 8:
        while (num)
    {
        bin += (num % 9) * k;
        k *= 10;
        num /= 9;
    }
    return bin;
        break;

    case 9:
    return num; break;

    default:
        break;
    }
}

int Max_num(int A)//максимальная цифра в числе
{
    int max=0, x;
    while (A!=0) {
      x=A%10;
      if (x>=max) max=x;
      A=A/10;
      }
      return max;
}

char* Translite_str(int num, char* p)//перевод из int в string
{
    int k=0, x, j=0;
    int n=num;
    while(n)
    {
        k++;
        n=n/10;
    }
    p=(char *)malloc(k);
    sprintf(p,"%d",num);
}

char* New_str(char str[], int num[], char *pp)//сборка новой строки из символов и новых числовых преобразований
{
    int flag=1;
    char* p;
    p=(char*)malloc(20);
    int j=0, k=0;
    for(int i=0; i<strlen(str);i++)
    {
        if(!isdigit(str[i]))
        {
            flag=1;
            pp[j]=str[i];
            j++;
        }
        else if(flag==1)
        {
            sprintf(p,"%d",num[k]);
            strcat(pp, p);
            j+=strlen(p);
            k++;
            flag=0;
        }
    }
}

int main(void)                 
{                               
    char string[]="10r11a12s13d14f15g16h17j1aa1a";   
    char* pp;
    int* p;
    int k=0, flag=1;
   for(int i=0;i<strlen(string);i++)
    {
        if(isdigit(string[i])&&flag==1)
        {k++; flag=0;}
        if(!isdigit(string[i])) flag=1;
    }
    p=(int *)malloc(k*sizeof(int));

    Search(string,p);//поиск чисел в строке
     for(int i=0;i<k;i++)
        printf("prpr - %d\n",p[i]);
    for(int i=0;i<k;i++)
    {
        p[i]=Trans_num(p[i], Max_num(p[i]));
        printf("p[i] - %d\n",p[i]);
    }
    pp=(char*)malloc(sizeof(string)+sizeof(p));
    New_str(string,p,pp);
    printf("pp %s\n",pp);
    free(pp);
}     