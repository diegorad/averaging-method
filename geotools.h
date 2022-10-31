# include <stdio.h>
# include <stdlib.h>

typedef struct 	Vertex 
	{
   	int  		index;
   	double coordinates[2];
	} Vertex;

typedef struct 	Poly 
	{
   	int	index;
   	int	vertices[4];
	int	vecinos[4];//Index de poligonos vecinos
	int	numDeVecinos;
	int	numberOfEdges;	
	double	temp;
	double coordinates[2];
	} Poly;

double *createVector(int dim);
Vertex *createVerticesList(int len);
Vertex fillVertexList(int len,Vertex *list,FILE *input);
Poly *createPolyList(int len);
Poly fillPolyList(int len,Poly *polyList,FILE *input);
int compareH(const void * a, const void * b);
Poly fillVecinos(Poly *polys,int numberOfPolys);
