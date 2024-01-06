# Projet-SFSD
#include <stdio.h>
#include <stdlib.h>
typedef struct produit  *ptr;
typedef struct produit
{int id;
ptr svt;}produit;
typedef struct bloc
{   int tb_id[10];
    int nb; //nbr de elt per bloc
}bloc;


int main ()
{
     FILE *f;
 f=fopen("test001.bin","wb");
ptr t,p,nouv;
int a;
switch (a)
{
case 1://creation
     FILE *f;
 f=fopen("test001.bin","wb");
case 2://supression d element 
     int a;
case 3://inserssion d element 
       
case 4://recheche  
    ptr z,p;
  f=fopen("test001.bin","rb");
fread (z,sizeof(produit),1,f);
    int b;
    p=z;
    scanf ("%d" ,&b);
     while (p->id!=b)
            {p=p->svt;
             if (p->id==b)
             {
               printf ("you should boycot this!!!!!");
             }else 
             {printf ("this is fine !!!!!! ");}
              }
    break;

default:
    break;
}


