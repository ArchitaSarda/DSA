#include <bits/stdc++.h>
using namespace std;
int INF = 2147483647;

void check(vector<vector<int>> &maps, int i, int j, int m, int n, queue<pair<int, int>> &q, int dist)
{
  if (i < 0 || j < 0 || i >= m || j >= n || maps[i][j] == -1 || maps[i][j] == 0)
  {
    return;
  }
  if (maps[i][j] < dist || maps[i][j] == INF)
  {
    maps[i][j] = dist + 1;
    q.push(make_pair(i, j));
  }
}

vector<vector<int>> getDistance(vector<vector<int>> &maps)
{

  queue<pair<int, int>> q;
  int m = maps.size();
  int n = maps[0].size();
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (maps[i][j] == 0)
      {
        q.push(make_pair(i, j));
      }
    }
  }
  int dist = 0;
  while (!q.empty())
  {
    pair<int, int> &curr = q.front();
    q.pop();
    int i = get<0>(curr);
    int j = get<1>(curr);

    cout << i << j << "\n";
    check(maps, i - 1, j, m, n, q, dist);
    check(maps, i + 1, j, m, n, q, dist);
    check(maps, i, j - 1, m, n, q, dist);
    check(maps, i, j + 1, m, n, q, dist);
  }

  return maps;
}

int main()
{
  vector<vector<int>> input, output;
  input.push_back({INF, -1, 0, INF});
  input.push_back({INF, INF, INF, -1});
  input.push_back({INF, -1, INF, -1});
  input.push_back({0, -1, INF, INF});

  output = getDistance(input);
  cout << "output is: "
       << "\n";
  for (int i = 0; i < output.size(); i++)
  {
    for (int j = 0; j < output[i].size(); j++)
    {
      cout << output[i][j] << "\t";
    }
    cout << "\n";
  }
}