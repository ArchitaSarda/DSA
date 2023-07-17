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

  void topologicalSort()
  {
    vector<int> indegree(nodes, 0);
    queue<int> q;
    vector<int> ans;

    for (int i = 0; i < nodes; i++)
    {
      for (auto j : al[i])
      {
        indegree[j]++;
      }
    }

    for (int i = 0; i < nodes; i++)
    {
      if (indegree[i] == 0)
      {
        q.push(i);
      }
    }

    while (!q.empty())
    {
      int curr = q.front();
      q.pop();
      ans.push_back(curr);
      cout << curr << "\n";
      for (auto i : al[curr])
      {
        indegree[i]--;
        if (indegree[i] == 0)
        {
          q.push(i);
        }
      }
    }

    cout << "Topological sort is: "
         << "\n";
    for (auto i : ans)
    {
      cout << i << "\t";
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