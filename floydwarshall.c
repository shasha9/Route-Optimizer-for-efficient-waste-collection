#include<stdio.h>
#include<limits.h>
#define size_max 50
// Recursive Function to print path of given
// vertex i from source vertex j
void printPath(int path[size_max][size_max], int v, int u)
{
if (path[v][u] == v)
return;
printPath(path, v, path[v][u]);
printf("%d ", path[v][u]);
}
// Function to run Floyd-Warshall algorithm
void FloydWarshell(int adjMatrix[size_max][size_max],int N)
{
// cost[] and parent[] stores shortest-path
int cost[size_max][size_max], path[size_max][size_max];
// initialize cost[] and parent[]
for (int i = 0; i < N; i++)
{
for (int j = 0; j < N; j++)
{
cost[i][j] = adjMatrix[i][j];
if (i == j)
path[i][j] = 0;
else if (cost[i][j] != INT_MAX)
path[i][j] = i;
}
}
// run Floyd-Warshall algorithm
for (int k = 0; k < N; k++)
{
for (int i = 0; i < N; i++)
{
for (int j = 0; j < N; j++)
{
if(i==j)
cost[i][j]=0;
else if ( cost[i][j] > ( cost[i][k]+cost[k][j] ) )
{
cost[i][j]= cost[i][k]+cost[k][j];
path[i][j]=path[k][j];
}
}
}
}
printf("\n");
//print the path and shortest distance
for (int v = 0; v < N; v++)
{
for (int u = 0; u < N; u++)
{
if (u != v && path[v][u] != -1)
{
printf("Shortest Path from vertex %d to vertex %d is ( %d ", v ,u ,v);
printPath(path, v, u);
printf( "%d ) \n\n",u);
}
}
}
}
int main()
{
int p[size_max][size_max],w,vertices,edges,u,v,i,j;;
printf( " <------------------ WELCOME TO FLOYDWARSHELL ALGORITHM:----------------->\n" );
printf( "\n Enter the number of vertices:\n" );
scanf("%d", &vertices );
printf("\n Enter the number of edges:\n" );
scanf("%d", &edges );
for(i=0 ; i< vertices ; i++)
{
for(j=0 ; j<vertices ; j++)
p[i][j]=99999; /* Define Infinite value.This value will be used for
vertices not connected to each other */
}
for(i=0 ; i< edges ; i++)
{
printf("\n Enter the end vertices of edge %d with its weight \n",i+1) ;
scanf("%d %d %d",&u,&v,&w);
p[u][v]=w;
}
/*printf("\n Matrix of input data:\n");
for(i=0 ; i< vertices ; i++)
{
for(j=0 ; j<vertices ; j++)
{
printf(" %d  ",p[i][j]);
}
printf("\n");
}*/
// Run Floyd Warshell algorithm
FloydWarshell(p,vertices);
return 0;
}
