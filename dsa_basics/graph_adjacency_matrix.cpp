#include <iostream>
#include <vector>
using namespace std;

class Graph
{
  vector<vector<int>> am;
  vector<int> nodes;

public:
  Graph(int n, vector<int> values)
  {
    am.resize(n);
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        am[i].push_back(0);
      }
      addNodeValue(values[i]);
    }
    showAdjMatrix();
  }

  void addNodeValue(int val)
  {
    nodes.push_back(val);
  }

  void addEdge(int firstNode, int secondNode, bool isDirected = false, int weight = 1)
  {
    am[firstNode][secondNode] = weight;
    if (!isDirected)
    {
      am[secondNode][firstNode] = weight;
    }
  }

  void addNewNode(int val)
  {
    addNodeValue(val);
    int n = getTotalNodes();
    am.resize(n);
    for (int i = 0; i < n; i++)
    {
      am[i].push_back(0);
      am[n - 1].push_back(0);
    }
  }

  int getTotalNodes()
  {
    return nodes.size();
  }

  void showAdjMatrix()
  {
    cout << "The matrix is: "
         << "\n"
         << "\t";
    for (int i = 0; i < getTotalNodes(); i++)
    {
      cout << nodes[i] << "\t";
    }
    cout << "\n";
    for (int i = 0; i < getTotalNodes(); i++)
    {
      cout << nodes[i] << "\t";
      for (int j = 0; j < getTotalNodes(); j++)
      {
        cout << am[i][j] << "\t";
      }
      cout << "\n";
    }
  }
};

int main()
{
  Graph g(5, {1, 2, 3, 4, 5});
  g.addEdge(0, 1);
  g.addEdge(1, 2);
  g.addEdge(2, 3, true);
  g.addEdge(3, 4, true, 5);
  g.showAdjMatrix();
  g.addNewNode(6);
  g.addEdge(4, 5);
  g.showAdjMatrix();
  return 0;
}