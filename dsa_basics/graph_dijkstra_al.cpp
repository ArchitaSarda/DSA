// C++ Program to find Dijkstra's shortest path using
// priority_queue in STL
#include <bits/stdc++.h>

using namespace std;

// iPair ==> Integer Pair
typedef pair<int, int> iPair;

class Graph
{
  vector<vector<iPair>> al;
  int nodes;

public:
  Graph(int v)
  {
    this->nodes = v;
    al.resize(v);
  }

  void addEdge(int first, int second, int weight)
  {
    al[first].push_back(make_pair(second, weight));
    al[second].push_back(make_pair(first, weight));
  }

  void showAl()
  {
    cout << "The adjacency list is: "
         << "\n";
    for (int i = 0; i < nodes; i++)
    {
      cout << i;
      for (int j = 0; j < al[i].size(); j++)
      {
        cout << "\t"
             << "-> " << al[i][j].first << ": " << al[i][j].second;
      }
      cout << "\n";
    }
  }

  void shortestPath(int start)
  {

    vector<int> dist(nodes, numeric_limits<int>::max());
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty())
    {
      iPair curr = pq.top();
      pq.pop();
      for (auto i : al[curr.second])
      {
        if (i.second + curr.first < dist[i.first])
        {
          dist[i.first] = i.second + curr.first;
          pq.push({dist[i.first], i.first});
        }
      }
    }

    cout << "Shortest distance from " << start << " is: "
         << "\n";
    for (int i = 0; i < nodes; i++)
    {
      cout << i << ": " << dist[i] << "\n";
    }
  }
};

// Driver's code
int main()
{
  // create the graph given in above figure
  int V = 9;
  Graph g(V);

  // making above shown graph
  g.addEdge(0, 1, 4);
  g.addEdge(0, 7, 8);
  g.addEdge(1, 2, 8);
  g.addEdge(1, 7, 11);
  g.addEdge(2, 3, 7);
  g.addEdge(2, 8, 2);
  g.addEdge(2, 5, 4);
  g.addEdge(3, 4, 9);
  g.addEdge(3, 5, 14);
  g.addEdge(4, 5, 10);
  g.addEdge(5, 6, 2);
  g.addEdge(6, 7, 1);
  g.addEdge(6, 8, 6);
  g.addEdge(7, 8, 7);

  g.showAl();
  // Function call
  g.shortestPath(0);

  return 0;
}
