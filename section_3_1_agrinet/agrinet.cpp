/*
ID: jockeys1
TASK: agrinet
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <cassert>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <climits>
#include <numeric>
#include <set>
#include <bitset>
#include <utility>

using namespace std;

int n;
int a[105][105];
int weight[105], visited[105];

int main()
{
    ifstream fin("agrinet.in");
    ofstream fout("agrinet.out");

    if (!fin.is_open()) {
        cout << "cannot find the file agrinet." << endl;
        return 0;
    }

    fin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            fin >> a[i][j];
        }

    for (int i = 1; i <= n; i++)
    {
        weight[i] = 1e9, visited[i] = 0;
    }
    weight[1] = 0, visited[1] = 1;
    int cur = 1;
    int ans = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            weight[j] = min(weight[j], a[cur][j]);
        }

        int nxt = -1;
        for (int j = 1; j <= n; j++)
        {
            if (!visited[j] && (nxt == -1 || weight[j] < weight[nxt]))
            {
                nxt = j;
           }
        }
        cur = nxt;
        ans += weight[nxt];
        visited[nxt] = 1;
    }
    fout << ans << endl;

    fin.close();
    fout.close();
}