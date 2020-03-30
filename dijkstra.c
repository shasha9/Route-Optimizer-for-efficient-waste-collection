#include<stdio.h>
#define size_max 50
void dijkstra(int Graph[size_max][size_max],int n , int src) /*Method to implement shortest path algorithm*/
{
Intcost[size_max][size_max],distance[size_max],pred[size_max];     //pred[] stores the predecessor of each node
Intvisited[size_max],count,mindistance,nextnode,i,j;//count gives the number of nodes seen so far

//create the cost matrix
for(i=0;i<n;i++)
for(j=0;j<n;j++)
cost[i][j]=Graph[i][j];



//initialize pred[],distance[] and visited[]
for(i=0;i<n;i++)
{
distance[i]=cost[src][i];
pred[i]=src;
visited[i]=0;
}

distance[src]=0;
visited[src]=1;
count=1;

while(count<n-1)
{
mindistance=99999;

//nextnode gives the node at minimum distance
for(i=0;i<n;i++)
if(distance[i]<mindistance&&!visited[i])
{
mindistance=distance[i];
nextnode=i;
}

//check if a better path exists through nextnode
visited[nextnode]=1;
for(i=0;i<n;i++)
if(!visited[i])
if(mindistance+cost[nextnode][i]<distance[i])
{
distance[i]=mindistance+cost[nextnode][i];
pred[i]=nextnode;
}
count++;
}

//print the path and distance of each node
for(i=0;i<n;i++)
if(i!=src)
{
printf("\n\nDistance of node%d=%d",i+1,distance[i]);
printf("\nPath=%d",i);

j=i;
do
{
j=pred[j];
printf("<-%d",j);
}while(j!=src);
}
}

int main()
{
int p[size_max][size_max],w,vertices,edges,u,v,i,j;;
printf( "  <----------------- WELCOME TO DIJKSTRA'S ALGORITHM :----------------->\n" );
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
printf("\n Matrix of input data:\n");
for(i=0 ; i< vertices ; i++)
{
for(j=0 ; j<vertices ; j++)
printf("%d \n",p[i][j]);
}
dijkstra(p,vertices,0);
return 0;
}