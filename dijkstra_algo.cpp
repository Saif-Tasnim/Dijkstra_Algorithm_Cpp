// graph algorithm - dijkstra

/*

Input:
6 8 ------> #nodes & #edges
u v w
0 1 4
1 2 4
0 2 2
2 4 3
2 3 6
2 5 1
4 3 2
5 3 3

Output:
1->2->0->5->4->3

*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int INF = 1e9;

vector<pair<int, int>> nodeList[N];
int d[N], visited[N];
int nodes, edges;

void printGraph()
{
    for (int i = 0; i <= nodes; i++)
    {
        for (auto adj : nodeList[i])
        {
            cout << "Node :-> " << i << " -> " << adj.first << " , weight :-> " << adj.second << endl;
        }
        cout << endl;
    }
}

void dijkstra(int src)
{
    char source = src + 'A';
    cout << "Source Node :->  " << source << endl << endl;
    for (int i = 0; i < nodes; i++)
    {
        d[i] = INF;
    }

    d[src] = 0;

    for (int i = 0; i < nodes; i++)
    {
        int selection_node = -1;
        for (int j = 1; j <= nodes; j++)
        {
            if (visited[j] == 1)
                continue;
            if (selection_node == -1 || d[selection_node] > d[j])
            {
                selection_node = j;
            }
        }

        visited[selection_node] = 1;
        for (auto adj : nodeList[selection_node])
        {
            int adj_node = adj.first;
            int weight = adj.second;
            if (d[selection_node] + weight < d[adj_node])
            {
                d[adj_node] = d[selection_node] + weight;
            }
        }
    }
}

void printDistanceArray()
{
    for (int i = 0; i < nodes; i++)
    {
        char source = i + 'A';
        if (i == nodes - 1)
        {
            cout << d[i] << "(" << source << ")" << endl;
            break;
        }
        cout << d[i] << "(" << source << ")"
                                         " -> ";
    }

    cout << endl;
}

int main()
{
    cout << "Enter Nodes & Edges : ";
    cin >> nodes >> edges;

    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        nodeList[u].push_back({v, w});
        nodeList[v].push_back({u, w});
    }

    cout << "Enter Source Node : ";
    int src;
    cin >> src;

    // printGraph();

    dijkstra(src);

    printDistanceArray();
}