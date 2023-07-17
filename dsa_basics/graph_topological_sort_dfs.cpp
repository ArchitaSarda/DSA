#include <bits/stdc++.h>
using namespace std;

class Graph
{
  vector<vector<int>> al;
  int nodes;

public:
  Graph(int n)
  {
    nodes = n;
    al.resize(n);
  }

  void addEdge(int first, int second)
  {
    al[first].push_back(second);
  }

  void showAL()
  {
    cout << "Adjacency list is: "
         << "\n";
    for (int i = 0; i < nodes; i++)
    {
      cout << i << ": ";
      for (auto j : al[i])
      {
        cout << "\t"
             << "->" << j;
      }
      cout << "\n";
    }
  }

  void dfs(int curr, vector<int> &visited, stack<int> &s)
  {
    visited[curr] = 1;
    for (auto i : al[curr])
    {
      if (!visited[i])
      {
        dfs(i, visited, s);
      }
    }
    s.push(curr);
  }

  void topologicalSort()
  {
    vector<int> visited(nodes, 0);
    stack<int> s;
    for (int i = 0; i < nodes; i++)
    {
      if (!visited[i])
      {
        dfs(i, visited, s);
      }
    }

    cout << "Topological sort is: "
         << "\n";
    while (!s.empty())
    {
      cout << s.top() << "\t";
      s.pop();
    }
  }
};

int main()
{
  Graph g(6);
  g.addEdge(2, 3);
  g.addEdge(3, 1);
  g.addEdge(4, 1);
  g.addEdge(4, 0);
  g.addEdge(5, 0);
  g.addEdge(5, 2);

  g.showAL();
  g.topologicalSort();
  return 0;
}