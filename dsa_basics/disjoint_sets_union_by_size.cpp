#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
  vector<int> sp;
  int nodes;

public:
  DisjointSet(int n)
  {
    nodes = n;
    sp.resize(n, -1);
  }

  void unionBySize(int u, int v)
  {
    int up = findParent(u);
    int vp = findParent(v);
    int ur = abs(sp[up]);
    int vr = abs(sp[vp]);

    if (up == vp)
    {
      cout << "Detected cycle!"
           << "\n";
      return;
    }
    else if (ur < vr)
    {
      sp[vp] = (ur + vr) * -1;
      sp[up] = vp;
    }
    else if (ur >= vr)
    {
      sp[up] = (ur + vr) * -1;
      sp[vp] = up;
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
      return sp[n] = findParent(sp[n]);
    }
  }
};

int main()
{
  DisjointSet d(8);
  d.unionBySize(0, 1);
  d.unionBySize(2, 3);
  d.unionBySize(4, 5);
  d.unionBySize(6, 7);
  cout << d.findParent(0) << "\n";
  cout << d.findParent(1) << "\n";
  cout << d.findParent(4) << "\n";
  cout << d.findParent(5) << "\n";
  d.unionBySize(1, 3);
  d.unionBySize(1, 4);
  d.unionBySize(0, 2);
  d.unionBySize(5, 7);
  d.unionBySize(4, 6);
  cout << d.findParent(0) << "\n";
  cout << d.findParent(1) << "\n";
  cout << d.findParent(2) << "\n";
  cout << d.findParent(3) << "\n";
  cout << d.findParent(4) << "\n";
  cout << d.findParent(5) << "\n";
  cout << d.findParent(6) << "\n";
  cout << d.findParent(7) << "\n";
  return 0;
}