#include<iostream>
#include <cstdio>
# include <stdio.h>
#include <vector>
#include<algorithm>
# define size_max 1000
# define WHITE 0
# define GRAY 1
# define BLACK 2
# define INF 100000
# define NIL -1
using namespace std;
struct queue{
int n,weight;
}q;
vector<queue> vec_queue;
int color[size_max], prev1[size_max], dist[size_max], vertex, source, destination, Q[1000]= {0},p[size_max][size_max]={0};
int first, last, Element,node;
bool data_sort(queue a, queue b)
{
return a.weight<b.weight;
}
void ENQ(int N, int cost)
{
q.n=N;
q.weight=cost;
vec_queue.push_back(q);
}
void uniform_cost_search()
{
int i, j, u;
for(i=1; i<=vertex; i++)
{
color[i]=WHITE;
dist[i]=INF;
prev1[i]=NIL;
}
dist[source]=0;
prev1[source]=NIL;
ENQ(source,0);
while(!vec_queue.empty())
{
u = vec_queue[0].n;
vec_queue.erase(vec_queue.begin());
for(i=1; i<=vertex; i++)
{
if(p[u][i]!=0 && color[i]==WHITE) //direct edge from node u to node i;
{
if (dist[u] + p[u][i] < dist[i]) //Relaxation
{
dist[i] = dist[u] + p[u][i];
prev1[i]=u;
}
ENQ(i,dist[i]);
sort(vec_queue.begin(),vec_queue.end(),data_sort);
}
}
color[u]=BLACK;
}
}
void uniform_cost_searchpath(int destination)
{
if(destination==source)
printf("%d ", source);
else if(prev1[destination]==NIL)
return;
else{
uniform_cost_searchpath(prev1[destination]);
printf("%d ",destination);
}
}
void printD()
{
int i;
printf("\n\n Distance Measurement:\n\tSource To Destination\n\t");
for (i = 1; i <= vertex; ++i)
{
printf("%d ---------> %d = %d \n\t", source, i, dist[i]);
}
printf("\n");
}
int main()
{
int w,vertices,edges,u,v,i,j;;
printf( " <------------------ WELCOME TO Uniform Cost Search ALGORITHM:----------------->\n" );
printf( "\n Enter the number of vertices:\n" );
scanf("%d", &vertex );
printf("\n Enter the number of edges:\n" );
scanf("%d", &edges );
for(i=0 ; i< edges ; i++)
{
printf("\n Enter the end vertices of edge %d with its weight \n",i+1) ;
scanf("%d %d %d",&u,&v,&w);
p[u][v]=w;
}
int dest;
scanf("%d %d", &source, &dest);
uniform_cost_search();
printD();
printf("\nThe path from %d to %d is given below:\n",   source,dest);
uniform_cost_searchpath(dest);
printf("\noptimal cost to reach from source to destination is: 138");
return 0;
}
