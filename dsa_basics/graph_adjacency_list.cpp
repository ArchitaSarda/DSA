#include <iostream>
#include <vector>
using namespace std;

class Graph
{
  vector<vector<pair<int, int>>> al;

public:
  Graph(int noOfNodes)
  {
    al.resize(noOfNodes);
  }

  void addEdge(int firstNode, int secondNode, bool isDirected = false, int weight = 1)
  {
    al[firstNode].push_back({secondNode, weight});
    if (!isDirected)
    {
      al[secondNode].push_back({firstNode, weight});
    }
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
        pair<int, int> temp = al[i][j];
        cout << "->"
             << "\t" << temp.first << "," << temp.second;
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
  g.addEdge(3, 4, true);
  g.addEdge(1, 3, false, 10);
  g.addEdge(4, 2);
  g.showAdjacencyList();
  return 0;
}