#include "geotools.h"

Poly fillTemperature(Poly *mesh, int numberOfPolys,FILE *input)
{
int i;
	for(i=0;i<numberOfPolys;i++)
	fscanf(input,"%lf",&mesh[i].temp);
	
}

Poly average(Poly *mesh, int numberOfPolys)
{
double *tempNew;
int i,j;
double value;

tempNew=createVector(numberOfPolys);

	for(j=0;j<numberOfPolys;j++)
	{
	value=mesh[j].temp;
	if(mesh[j].numberOfEdges==3)
		{
		for(i=0;i<mesh[j].numDeVecinos;i++)
		value+=mesh[mesh[j].vecinos[i]].temp;
		tempNew[j]=value/(mesh[j].numDeVecinos+1);
		}
	else
		tempNew[j]=value;
	}

	for(j=0;j<numberOfPolys;j++)
	mesh[j].temp=tempNew[j];
}

