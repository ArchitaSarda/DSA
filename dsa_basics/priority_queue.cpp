#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int arr[6] = {10, 2, 4, 8, 6, 9};

    priority_queue<int> pq;
    for (int i = 0; i < 6; i++)
    {
        pq.push(arr[i]);
    }
    while (!pq.empty())
    {
        cout << pq.top() << ' ';
        pq.pop();
    }

    return 0;
}