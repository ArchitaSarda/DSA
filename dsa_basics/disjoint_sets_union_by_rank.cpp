#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
  vector<int> rank;
  vector<int> parent;
  int nodes;

public:
  DisjointSet(int n)
  {
    nodes = n;
    rank.resize(n, 0);
    parent.resize(n);
    for (int i = 0; i < n; i++)
    {
      parent[i] = i;
    }
  }

  void unionByRank(int u, int v)
  {
    int up = findParent(u);
    int vp = findParent(v);

    if (up == vp)
    {
      cout << "Cycle detected!"
           << "\n";
      return;
    }
    int ur = rank[up];
    int vr = rank[vp];
    if (ur < vr)
    {
      parent[up] = vp;
    }
    else if (ur > vr)
    {
      parent[vp] = up;
    }
    else
    {
      parent[vp] = up;
      rank[u]++;
    }
  }

  int findParent(int n)
  {
    if (parent[n] == n)
    {
      return n;
    }
    else
    {
      return parent[n] = findParent(parent[n]);
    }
  }
};

int main()
{
  DisjointSet d(7);
  d.unionByRank(0, 1);
  d.unionByRank(1, 2);
  d.unionByRank(3, 4);
  d.unionByRank(5, 6);
  cout << d.findParent(0) << "\n";
  cout << d.findParent(1) << "\n";
  cout << d.findParent(2) << "\n";
  cout << d.findParent(3) << "\n";
  cout << d.findParent(4) << "\n";
  cout << d.findParent(5) << "\n";
  cout << d.findParent(6) << "\n";
  d.unionByRank(0, 2);
  d.unionByRank(4, 5);
  d.unionByRank(2, 6);
  cout << d.findParent(0) << "\n";
  cout << d.findParent(1) << "\n";
  cout << d.findParent(2) << "\n";
  cout << d.findParent(3) << "\n";
  cout << d.findParent(4) << "\n";
  cout << d.findParent(5) << "\n";
  cout << d.findParent(6) << "\n";
  // d.unionByRank(0, 1);
  return 0;
}