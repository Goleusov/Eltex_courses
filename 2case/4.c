#include <stdio.h>       
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
int sizePointPointP=0;

int Counting(int arr[], int sizeArr)
{
    int flag=1,k=0;
    for (int i=0;i<sizeArr-1;i++)
    {
        if(arr[i+1]==(arr[i]+1)&&flag==1)
        {
            k++;
            flag=0;
        }
        if(arr[i+1]!=(arr[i]+1))
        flag=1;
    }
    return k;
}

int **f(int arr[],int sizeArr)
{
    int a,b,c,d,e;
    int lastIter=sizeArr-1;
    int flag=0,lenChein=0,otherIter=0, cycleVariable=0, pointIter=1;
    int otherArr[sizeArr];
    int numCheins=Counting(arr,sizeArr);
    sizePointPointP=numCheins;
    int **p=(int **)malloc(sizeof(int*)*(numCheins+1));
    for (int i=0;i<sizeArr-1;i++)
    {
        if(arr[i+1]==(arr[i]+1))
        {
            lenChein++;
            flag=1;
        }
        else
        {
            if(flag==1)
            {
            //lenChein++;
            p[pointIter]=(int*)malloc(sizeof(int)*lenChein);
            p[pointIter][0]=lenChein+1;
            cycleVariable=lenChein+1;

            for(int j=1;j<=cycleVariable;j++)
            {
                p[pointIter][j]=arr[i-lenChein];
                b=arr[i-lenChein];
                lenChein-=1;
            }
            lenChein=0;
            pointIter++;
            flag=0;
            }
            else
            {
                otherArr[otherIter]=arr[i];
                otherIter++;
            }  
        }
    }
    //последняя итерация   
    if(flag==1)
    {
        //lenChein++;
        p[pointIter]=(int*)malloc(sizeof(int)*lenChein);
        p[pointIter][0]=lenChein+1;
        cycleVariable=lenChein+1;
        for(int j=1;j<=cycleVariable;j++)
        {
            p[pointIter][j]=arr[lastIter-lenChein];
            b=arr[lastIter-lenChein];
            lenChein-=1;
        }
    }
    else
    {
            otherArr[otherIter]=arr[lastIter];
            otherIter++;
    }  
    p[0]=(int*)malloc(sizeof(int)*(otherIter+1));

    p[0][0]=otherIter;
    for(int i=1;i<=otherIter;i++)
    {
       c=otherArr[i-1];
       p[0][i]=otherArr[i-1];
    }
    return p;
    

}

int main()
{
    int arr[]={1,2,3,5,4,5,6,8,7,8,9};
    int count=sizeof(arr)/sizeof(arr[0]);
    int **p;
    p=f(arr,count);
    printf("длина - %d, цепочка не возрастающих значений -", p[0][0]);
    for(int j=1;j<=p[0][0];j++)
        {
            count=p[0][j];
            printf(" %d", p[0][j]);
        }
        printf("\n");
    for(int i=1;i<sizePointPointP+1;i++)
    {
        printf("длина - %d, цепочка -", p[i][0]);
        for(int j=1;j<=p[i][0];j++)
        {
            count=p[i][j];
            printf(" %d", p[i][j]);
        }
        printf("\n");
    }
}
