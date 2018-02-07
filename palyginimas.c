#include<stdio.h>
#include"palyginimas.h"

struct el{
	int data;
	struct el *next;
};

typedef struct el list;

int palyginimas (list *a, list *b)
{
	int ilgis_a=0,ilgis_b=0,zenklas_a,zenklas_b;
	if(a==NULL||b==NULL)
	{
		printf("vienas is skaiciu nera inicijuotas\n");
		return;
	}
	while(a->kitas!=NULL)
	{
		ilgis_a++;
		a=a->kitas;
	}
	zenklas_a=a->el;
	ilgis_a++;
	while(b->kitas!=NULL)
	{
		ilgis_b++;
		b=b->kitas;
	}
	zenklas_b=b->el;
	ilgis_b++;
	if(zenklas_a<0&&zenklas_b>0)
		return -1;
	if(zenklas_a>0&&zenklas_b<0)
		return 1;
	if(zenklas_a>0&&zenklas_b>0)
	{
		if(ilgis_a>ilgis_b)
			return 1;
		if(ilgis_a<ilgis_b)
			return -1;
	}
	if(zenklas_a<0&&zenklas_b<0)
	{
		if(ilgis_a>ilgis_b)
			return -1;
		if(ilgis_a<ilgis_b)
			return 1;
	}
	if(zenklas_a>0&&zenklas_b>0)\\liko tik atvejai kai ilgiai ir zenklai vienodi
	{
		
	}
}