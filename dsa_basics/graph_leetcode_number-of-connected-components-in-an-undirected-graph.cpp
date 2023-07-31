#include <bits/stdc++.h>
using namespace std;

class Graph
{
  vector<int> sp;

  void unionBySize(int u, int v)
  {
    int up = findParent(u);
    int vp = findParent(v);
    int ur = abs(sp[u]);
    int vr = abs(sp[v]);

    if (ur >= vr)
    {
      sp[up] = (ur + vr) * -1;
      sp[vp] = up;
    }
    else
    {
      sp[vp] = (ur + vr) * -1;
      sp[up] = vp;
    }
  }

  int findParent(int n)
  {
    if (sp[n] < 0)
    {
      return n;
    }
    else
    {
      sp[n] = findParent(sp[n]);
      return sp[n];
    }
  }

public:
  int connected(vector<vector<int>> &edges, int n)
  {
    sp.resize(n, -1);
    for (auto i : edges)
    {
      unionBySize(i[0], i[1]);
    }
    int ans = 0;
    for (auto i : sp)
    {
      if (i < 0)
      {
        ans++;
      }
    }
    return ans;
  }
};

int main()
{
  vector<vector<int>> input;
  input.push_back({0, 1});
  input.push_back({1, 2});
  input.push_back({3, 4});

  Graph g;

  cout << "\n"
       << g.connected(input, 5);
  return 0;
}