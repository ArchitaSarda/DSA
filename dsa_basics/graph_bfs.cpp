#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
  vector<vector<int>> al;

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
  void bfs(int startNode)
  {
    queue<int> q;
    vector<int> visited(al.size(), 0);
    cout << "BFS: "
         << "\n";
    q.push(startNode);
    visited[startNode] = 1;
    while (!q.empty())
    {
      int temp = q.front();
      q.pop();
      for (int i = 0; i < al[temp].size(); i++)
      {
        if (visited[al[temp][i]] == 0)
        {
          q.push(al[temp][i]);
          visited[al[temp][i]] = 1;
        }
      }
      cout << temp << "\t";
    }
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
  g.bfs(0);
  g.bfs(2);
  return 0;
}