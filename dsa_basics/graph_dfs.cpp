#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph
{
  vector<vector<int>> al;

  void dfsTraversal(int startNode, vector<int> &visited)
  {
    cout << startNode << "\t";
    for (int i = 0; i < al[startNode].size(); i++)
    {
      if (visited[al[startNode][i]] == 0)
      {
        visited[al[startNode][i]] = 1;
        dfsTraversal(al[startNode][i], visited);
      }
    }
  }

public:
  Graph(int n)
  {
    al.resize(n);
  }
  void addEdge(int firstNode, int secondNode)
  {
    al[firstNode].push_back(secondNode);
    al[secondNode].push_back(firstNode);
  }

  void dfs(int startNode)
  {
    if (al.size() == 0)
    {
      cout << "Empty graph";
      return;
    }
    cout << "DFS: "
         << "\n";
    vector<int> visited(al.size(), 0);
    visited[startNode] = 1;
    dfsTraversal(startNode, visited);
    cout << "\n";
  }

  void showAdjacencyList()
  {
    cout << "The adjacencey list is: "
         << "\n";
    for (int i = 0; i < al.size(); i++)
    {
      cout << i;
      for (int j = 0; j < al[i].size(); j++)
      {
        cout << "->"
             << "\t" << al[i][j];
      }
      cout << "\n";
    }
  }
};

int main()
{
  Graph g(5);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(0, 3);
  g.addEdge(3, 4);
  g.addEdge(1, 3);
  g.addEdge(4, 2);
  g.showAdjacencyList();
  g.dfs(2);
  return 0;
}