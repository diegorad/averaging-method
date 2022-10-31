# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include "geotools.h"
# include "termotools.h"

void main(int argc, char *argv[])
{
int numberOfVertices, numberOfPolys;
int i,j;
char fileName[28];
int it=strtol(argv[3], NULL, 10);

Vertex *vertexList;
Poly *polys;
FILE *input;
FILE *output;

//Input file from blender_mesh_export
sscanf(argv[1],"%s",&fileName[0]);
	if((input=fopen(fileName,"r"))==NULL)
	{printf("Cannot open file %s\n",fileName);
	exit(1);
	};
	fscanf(input,"%d",&numberOfVertices);
	fscanf(input,"%d",&numberOfPolys);
	printf("Number of polygons: %d\n", numberOfPolys);


vertexList=createVerticesList(numberOfVertices);
fillVertexList(numberOfVertices,vertexList,input);

polys=createPolyList(numberOfPolys);
fillPolyList(numberOfPolys,polys,input);

fclose(input);

//Determinar vecinos
for(i=0;i<numberOfPolys;i++)
if(polys[i].numberOfEdges==3)
qsort(polys[i].vertices,3,sizeof(int),compareH);
else
qsort(polys[i].vertices,4,sizeof(int),compareH);

fillVecinos(polys,numberOfPolys);

//Temperatura de tempmap.txt
sscanf(argv[2],"%s",&fileName[0]);
	if((input=fopen(fileName,"r"))==NULL)
	{printf("Cannot open file %s\n",fileName);
	exit(1);
	};
fillTemperature(polys,numberOfPolys,input);

//Input file
input=fopen("input.txt", "w+");
for(j=0;j<numberOfPolys;j++)
fprintf(input,"%lf %lf %lf\n",polys[j].coordinates[0],polys[j].coordinates[1],polys[j].temp);
fclose(input);

//Average
i=0;
while(i<it)
{
average(polys,numberOfPolys);
i++;
}

//Output
output=fopen("output.txt", "w+");
for(j=0;j<numberOfPolys;j++)
fprintf(output,"%lf %lf %lf\n",polys[j].coordinates[0],polys[j].coordinates[1],polys[j].temp);
fclose(output);
}
