/*
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

// This struct represents a directed graph using
// adjacency list representation
typedef struct Graph_t {

	// No. of vertices
	int V;
	bool adj[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Constructor
Graph* Graph_create(int V)
{
	Graph* g = malloc(sizeof(Graph));
	g->V = V;

	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			g->adj[i][j] = false;
		}
	}

	return g;
}

// Destructor
void Graph_destroy(Graph* g) { free(g); }

// Function to add an edge to graph
void Graph_addEdge(Graph* g, int v, int w)
{
	// Add w to v’s list.
	g->adj[v][w] = true;
}

// Prints BFS traversal from a given source s
void Graph_BFS(Graph* g, int s)
{
	// Mark all the vertices as not visited
	bool visited[MAX_VERTICES];
	for (int i = 0; i < g->V; i++) {
		visited[i] = false;
	}

	// Create a queue for BFS
	int queue[MAX_VERTICES];
	int front = 0, rear = 0;

	// Mark the current node as visited and enqueue it
	visited[s] = true;
	queue[rear++] = s;

	while (front != rear) {

		// Dequeue a vertex from queue and print it
		s = queue[front++];
		printf("%d ", s);

		// Get all adjacent vertices of the dequeued
		// vertex s.
		// If an adjacent has not been visited,
		// then mark it visited and enqueue it
		for (int adjacent = 0; adjacent < g->V;
			adjacent++) {
			if (g->adj[s][adjacent] && !visited[adjacent]) {
				visited[adjacent] = true;
				queue[rear++] = adjacent;
			}
		}
	}
}

// Driver code
int main()
{
    int k,m,n,q,r;
   printf("Number of Vertices\n");
            scanf("%d",&m);
            Graph* g = Graph_create(m);
    while(1)
    {
        printf("\t 1:add edge 2:BFS \n");
        scanf("%d",&k);
        switch(k)
        {
            case 1:printf("SOURCE AND DESTINATION\n");
            scanf("%d%d",&n,&q);
            Graph_addEdge(g, n, q);
            break;
            case 2:
                printf("Breadth First Traversal start from vertex \n");
                scanf("%d",&r);
	         Graph_BFS(g, r);
	           Graph_destroy(g);
        }
    }
	// Create a graph







	return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

typedef struct Graph_t {
    int V;
    int adj[MAX_VERTICES][MAX_VERTICES];
} Graph;



Graph* Graph_create(int V)
{
    Graph* g = malloc(sizeof(Graph));
    g->V = V; //is assigning the value of the variable V (number of vertices) to the V member of the Graph struct.

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            g->adj[i][j] = 0;
        }
    }

    return g;
} //In summary, the Graph_create function allocates memory for the graph structure, sets the number of vertices,
// and initializes the adjacency matrix with no edges. It then returns the created graph.




void Graph_destroy(Graph* g)
{
    free(g);
}

void Graph_addEdge(Graph* g, int v, int w)
{
    g->adj[v][w] = 1; // v is source, w is destination
}

void Graph_BFS(Graph* g, int s)
{
    int visited[MAX_VERTICES]; // Array to keep track of visited vertices
    for (int i = 0; i < g->V; i++) {
        visited[i] = 0; // Initialize all vertices as not visited
    }

    int queue[MAX_VERTICES];
    int front = 0, rear = 0; // Indices for front and rear of the queue

    visited[s] = 1; // Mark the source vertex as visited
    queue[rear++] = s; // Enqueue the source vertex

    while (front != rear) {
        s = queue[front++]; // Dequeue a vertex from the front of the queue
        printf("%d ", s); // Print the vertex

        // Traverse all adjacent vertices of the dequeued vertex
        for (int adjacent = 0; adjacent < g->V; adjacent++) {
            // If an adjacent vertex is present and not visited, mark it as visited and enqueue it
            if (g->adj[s][adjacent] && !visited[adjacent]) {
                visited[adjacent] = 1;
                queue[rear++] = adjacent; // Enqueue the adjacent vertex
            }
        }
    }
}

int main()
{
    int k, m, n, q, r;
    printf("Number of Vertices\n");
    scanf("%d", &m);
    Graph* g = Graph_create(m);

    while (1) {
        printf("\t 1:add edge 2:BFS \n");
        scanf("%d", &k);

        switch (k) {
            case 1:
                printf("SOURCE AND DESTINATION\n");
                scanf("%d%d", &n, &q);
                Graph_addEdge(g, n, q);
                break;
            case 2:
                printf("Breadth First Traversal start from vertex \n");
                scanf("%d", &r);
                Graph_BFS(g, r);
                break;
        }
    }

    Graph_destroy(g);

    return 0;
}

/*
1
SOURCE AND DESTINATION
4
5
         1:add edge 2:BFS
1
SOURCE AND DESTINATION
4
12
         1:add edge 2:BFS
1
SOURCE AND DESTINATION
4
8
         1:add edge 2:BFS
1
SOURCE AND DESTINATION
12
13
         1:add edge 2:BFS
1
SOURCE AND DESTINATION
10
11
         1:add edge 2:BFS
2
Breadth First Traversal start from vertex
3
3 1 2 4 7 6 10 5 8 12 9 11       1:add edge 2:BFS
13
*/
