// DIJKSTRA IMPLEMENTATION

#include<iostream>
#include<climits>
using namespace std;

struct Edge {
    int u;
    int v;
    int w;
};

struct Graph {
    // V-> Number of vertices, E-> Number of edges
    int V, E;

    // graph is represented as an array of edges.
    struct Edge* edge;
};

struct Graph* createGraph(int V, int E) {
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

void dijkstra(Graph *g, int source) {
    int u, v, w;
    int d[g->V];
    int p[g->V];
    for (int i = 0; i < g->V; i++) {
        d[i] = INT_MAX;
        p[i] = 0;
    }
    d[source] = 0;
    for(int i = 0; i <= g->V-1; i++) {
        for(int j = 0; j < g->E; j++) {
            u = g->edge[j].u;
            v = g->edge[j].v;
            w = g->edge[j].w;
            
            if(d[u] != INT_MAX && d[v] > d[u] + w) {
                d[v] = d[u] + w;
                p[v] = u;
            }
        }
    }
    cout << "\nVertex\t\t:\t";
    for(int i = 0; i < g->V; i ++) {
        cout << i << "\t";
    }
    cout << "\nDistance\t:\t";
    for(int i = 0; i < g->V; i ++) {
        cout << d[i] << "\t";
    }
    cout << "\nParent\t\t:\t";
    for(int i = 0; i < g->V; i ++) {
        cout << p[i] << "\t";
    }
    cout << endl;
}




int main() 
{
    int V,E;
    
    cout << "\nEnter Number of Vertices\t:\t";
    cin >> V;
    cout << "\nEnter Number of Edges\t:\t";
    cin >> E;
     struct Graph* g = createGraph(V, E);

    cout << "\nEnter Edge's  source , destination , weight\n";
    for ( int i = 0; i < g->E; i++ ) 
    {
        cout << "\nEnter values for " << i+1 << " Edge\n";
        cin >> g->edge[i].u;
        cin >> g->edge[i].v;
        cin >> g->edge[i].w;
    }
    cout << "\nEnter Source Vertex\t:\t";
    int s;
    cin >> s;
    
    
	cout<<"Dijkstra Algorithm\n";
	dijkstra(g, s);
                  
        
    
     return 0;
}
