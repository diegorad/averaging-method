#include "geotools.h"

double *createVector(int dim)
{
double *pf;
	if((pf=(double *)malloc/*Memory Allocation: cantidad de espacio de un tipo de dato que quieres reservar*/(dim*sizeof(double)))==NULL)
	{printf("Error allocating memory \n");
	exit(1);
	}

return pf;
}

Vertex *createVerticesList(int len)
{
Vertex *verticesList;
	if((verticesList=(Vertex *)malloc(len*sizeof(Vertex)))==NULL)
	{
	printf("Error allocating memory \n");
	exit(1);
	}
return verticesList;
}

Vertex fillVertexList(int len,Vertex *list,FILE *input)
{
int i,j;
	for(i=0;i<len;i++)
	{
	list[i].index=i;
	for(j=0;j<2;j++)
	{
	fscanf(input,"%lf",&list[i].coordinates[j]);
	}
	fscanf(input,"%*f");
	}
	return *list;

}

Poly *createPolyList(int len)
{
Poly *polyList;
	if((polyList=(Poly *)malloc(len*sizeof(Poly)))==NULL)
	{
	printf("Error allocating memory \n");
	exit(1);
	}
return polyList;
}

Poly fillPolyList(int len,Poly *polyList,FILE *input)
{
int i,j;

for(i=0;i<len;i++)
fscanf(input,"%d",&polyList[i].numberOfEdges);

for(i=0;i<len;i++)
	{
	polyList[i].index=i;
		if(polyList[i].numberOfEdges==3)
		{
		for(j=0;j<3;j++)
		fscanf(input,"%d",&polyList[i].vertices[j]);
		}
		else
		{
		for(j=0;j<4;j++)
		fscanf(input,"%d",&polyList[i].vertices[j]);
		}
	}

for(i=0;i<len;i++)
for(j=0;j<2;j++)
fscanf(input,"%lf",&polyList[i].coordinates[j]);

return *polyList;
}

int compareH(const void * a, const void * b)
{
return (*(int*)a-*(int*)b);
}

Poly fillVecinos(Poly *polys,int numberOfPolys)
{
int i,j,m,n,hrunI,hrunJ,currentValue;
for(i=0;i<numberOfPolys;i++)
for(m=0;m<polys[i].numberOfEdges;m++)
{
currentValue=polys[i].vertices[m];
for(j=i+1;j<numberOfPolys;j++)
for(n=0;n<polys[j].numberOfEdges;n++)
if(polys[j].vertices[n]==currentValue)
	for(hrunI=m+1;hrunI<polys[i].numberOfEdges;hrunI++)
	for(hrunJ=n+1;hrunJ<polys[j].numberOfEdges;hrunJ++)
		if(polys[j].vertices[hrunJ]==polys[i].vertices[hrunI])
			{
			polys[i].vecinos[polys[i].numDeVecinos]=j;
			polys[i].numDeVecinos++;

			polys[j].vecinos[polys[j].numDeVecinos]=i;
			polys[j].numDeVecinos++;
			}
}
}
