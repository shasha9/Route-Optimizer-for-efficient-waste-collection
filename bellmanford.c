# include <stdio.h>
# define size_max 1000
# define INT_MAX 99999
int matrix[size_max][size_max];
void printPath(int parent[] , int v)
{
if (v < 0)
return;
printPath(parent, parent[v]);
printf("%d ", v );
}

void BellmanFord( int edges[][3] ,int V, int E, int source)
{
int parent[V+1],dis[V+1];
for (int i = 1; i <= V; i++)
{
dis[i] =INT_MAX;
parent[i]=-1;
}
dis[source] =0;
for (int i =0; i < V - 1; i++)
{
for(int j = 0; j < E; j++)
{
if(dis[edges[j][0]] + edges[j][2] < dis[edges[j][1]])
{
dis[edges[j][1]] =  dis[edges[j][0]] + edges[j][2];
parent[edges[j][1]]=edges[j][0] ;
}
}
}
printf("Vertex Distance from Source\n");
for (int i = 1; i <= V; i++)
{
printf("%d---> %d\t Path is ", i , dis[i]);
printPath(parent,i);
printf("\n");
}
}
int main()
{
int w,vertex,E,u,v,i,j;;
printf( " <------------------ WELCOME TO Bellman Ford ALGORITHM:----------------->\n" );
printf( "\n Enter the number of vertices:\n" );
scanf("%d", &vertex );
printf("\n Enter the number of edges:\n" );
scanf("%d", &E );
int edges[size_max][3];
for(i=0 ; i< E ; i++)
{
printf("\n Enter the end vertices of edge %d with its weight \n",i+1) ;
scanf("%d %d %d",&u,&v,&w);
matrix[u][v]=w;
edges[i][0]=u;
edges[i][1]=v;
edges[i][2]=w;
}

/*printf("\n Matrix of input Edges:\n");
for(j=0 ; j<E ; j++)
{
printf(" %d \t %d  \t %d",edges[j][0],edges[j][1],edges[j][2]);
printf("\n");
}*/
BellmanFord(edges,vertex,E,1);
printf("\noptimal cost to reach from source to destination is: 138");
return 0;
}
