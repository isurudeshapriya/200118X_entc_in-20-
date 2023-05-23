#include <stdio.h>
#include <limits.h>
#include <iostream>

using namespace std;


#define V 6

//Find the vertex 
int minKey(int key[], bool mstSet[]){
    
    int min = INT_MAX, min_index;

    for (int i= 0; i<V; i++){
        if ((mstSet[i]==false) && (key[i]<min)){
            min = key[i], min_index = i;
        }
    }

    return min_index;
}

//Print  MST
int printMST(int parent[], int n, int graph[V][V]){
    cout << "Edge   Weight\n";

    for (int i=1; i<V; i++){
        printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
    }
}

void primMST(int graph[V][V]){
    int parent[V];

    int key[V];

    bool mstSet[V];

    // Initialize all keys as INFINITE
    for (int i=0; i<V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;

    parent[0] = -1;

    // The MST will have V vertices
    for (int count=0; count<V-1; count++){

        int u = minKey(key, mstSet);

       
        mstSet[u] = true;

        for (int i=0; i<V; i++){
            if (graph[u][i]&&mstSet[i]==false && graph[u][i]<key[i]){
                parent[i] = u;
                key[i] = graph[u][i];
            }
        }
    }
    printMST(parent, V, graph);
}


int main(){
    //Define the graph
    int graph[V][V] = {{0, 3, 0, 0, 0, 1}, {3, 0, 2, 1, 10, 0}, {0, 2, 0, 3, 0, 5}, {0, 1, 3, 0, 5, 0}, {0, 10, 0, 5, 0, 4}, {1, 0, 5, 0, 4, 0}};

    
    primMST(graph);

    return 0;
}