#include<iostream>
#include<conio.h>
#include <stdio.h> 
#include <limits.h> 
   
#define V 5
   
int minDistance(int dist[], bool sptSet[]) 
{ 
  
   int min = INT_MAX, min_index; 
   
   for (int v = 0; v < V; v++) 
     if (sptSet[v] == false && dist[v] <= min) 
         min = dist[v], min_index = v; 
   
   return min_index; 
} 
   int printSolution(int dist[], int src) 
{ 
   printf("Link State Routing Table for router %d \n____________________________________\n",src+1); 
   for (int i = 0; i < V; i++) 
      printf("%d \t \t %d\n", i+1, dist[i]); 
      
    printf("\n\n");
} 

void dijkstra(int graph[V][V], int src) 
{ 
     int dist[V];     
   
     bool sptSet[V]; 
   
  
     for (int i = 0; i < V; i++) 
        dist[i] = INT_MAX, sptSet[i] = false; 
   
     // Distance of source vertex from itself is always 0 
     dist[src] = 0; 
   
     // Find shortest path for all vertices 
     for (int count = 0; count < V-1; count++) 
     { 
        
       int u = minDistance(dist, sptSet); 
   
       
       sptSet[u] = true; 
   
       
       for (int v = 0; v < V; v++) 
   
       
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v]) 
            dist[v] = dist[u] + graph[u][v]; 
     } 
   
        printSolution(dist,src);     
} 

int main()
{ 
int graph[5][5] ={{0, 4, 0, 0, 8,}, 
                      {4, 0, 8, 11, 0}, 
                      {0, 8, 0, 7, 4 }, 
                      {9,7, 0, 0, 14,}, 
                      {10, 9, 0, 1, 0}};
 for(int i =0; i <V;i++)
 {
  dijkstra(graph,i);
}
	return 0;
}
