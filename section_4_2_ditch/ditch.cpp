/*
ID: jockeys1
TASK: ditch
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
#include <queue>

using namespace std;

const int nn = 205;
const int inf = 0x3f3f3f3f;

int n, m, adj[nn][nn], pa[nn];

bool reach(int st, int en)
{
    static int vis[nn];

    for (int i = 1; i <= m; i++)
    {
        vis[i] = 0;
    }
    vis[st] = 1;
    queue<int>  q;
    q.push(st);
    while (!q.empty())
    {
        int i = q.front(); q.pop();
        for (int j = 1; j <= m; j++)
        {
            if (!vis[j] && adj[i][j] > 0)
            {
                vis[j] = 1;
                pa[j] = i;
                q.push(j);
            }
        }
    }

    return vis[en];
}

int main()
{
    ifstream fin("ditch.in");
    ofstream fout("ditch.out");

    if (!fin.is_open()) {
        cout << "cannot find the file ditch." << endl;
        return 0;
    }

    fin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int s, e, c;
        fin >> s >> e >> c;
        adj[s][e] += c;
    }

    long long flow = 0;
    while (reach(1, m))
    {
        int curflow = inf;
        for (int i = m; i != 1; i = pa[i])
        {
            curflow = min(curflow, adj[pa[i]][i]);
        }
        for (int i = m; i != 1; i = pa[i])
        {
            adj[pa[i]][i] -= curflow;
            adj[i][pa[i]] += curflow;
        }

        flow += curflow;
    }

    cout << flow << endl;
    fout << flow << endl;

    fin.close();
    fout.close();
}