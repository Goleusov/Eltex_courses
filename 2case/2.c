#include <stdio.h>       
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int rez=2;

void Output(float *p, int *razm )//razm - n(строк в матрице), razm+1 - m(число столбцов)
{
for(int i=0;i<(*razm);i++)
  for(int j=0;j<(*(razm+1));j++)
    printf("p[%d][%d] = %f\n",i,j,*(p + i*(*(razm+1)) + j));

}

float *Input(int *razm) {
  printf("Введите размерность матрицы: кол-во строк и столбцов\n");
 // scanf("%d%d",razm,(razm+1));//ввод размерности закоментирован для удобства
    (*razm) = 2;//n строк
    (*(razm+1)) = 2;//m столбцов
    float *p;
    p = (float *) malloc(sizeof(float) * (*razm)*(*(razm+1)));//указатель на матрицу
    for (int i = 0; i < (*razm); i++) {
        for (int j = 0; j < (*(razm+1)); j++) {
            //printf("p[%d][%d] - ",i, j);
            //scanf("%f", (p + i*(*m) + j));
            //ввод с клавиатуры тоже закоменчен
            *(p+i*(*(razm+1))+j)= (float) (rez);
            rez+=10;
        }
    }
    return p;
}

void Input2(float **p,int **razm, int size) {
  for(int i=0;i<size;i++)
  {
  //printf("Введите размерность матрицы: кол-во строк и столбцов\n");
 // scanf("%d%d",razm,(razm+1));//ввод размерности закоментирован для удобства
 razm[i]=(int*)malloc(sizeof(int) * 2);
    (*razm[i]) = 2;//n строк
    (*(razm[i]+1)) = 2;//m столбцов
    //float *p;
    p[i] = (float *) malloc(sizeof(float) * (*razm[i])*(*(razm[i]+1)));//указатель на матрицу
    for (int k = 0; k < (*razm[i]); k++) {
        for (int j = 0; j < (*(razm[i]+1)); j++) {
            //printf("p[%d][%d] - ",i, j);
            //scanf("%f", (p[i] + i*(*m) + j));
            //ввод с клавиатуры тоже закоменчен, его еще передеать нужно
            *(p[i]+k*(*(razm[i]+1))+j)= (float) (rez);
            rez+=10;
        }
    }
  }
}

int main(void)                 
{                            
int size;
int **razm;
float **p;
printf("Введите кол-во матриц:");
scanf("%d", &size);
razm=(int**)malloc(sizeof(int*)*size);
p = (float **) malloc(sizeof(float*) * size);
Input2(p,razm,size);
for(int i=0;i<size;i++)
{
    printf("%d матирица\n", i+1);
    Output(p[i],razm[i]);
}
for(int i=0;i<size;i++)
  {
    free(p[i]);
    free(razm[i]);
  }
  free(p);
  free(razm);
}
