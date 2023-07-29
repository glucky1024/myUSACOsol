/*
ID: jockeys1
TASK: cowtour
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
#include <iomanip>

using namespace std;

using ld = long double;

#define maxn 150

int n, x[maxn], y[maxn];
string s;

ld adj[maxn][maxn];
ld maxdist[maxn];
ld inf = 1e9;

ld dist(int i, int j)
{
    ld dx = x[i] - x[j];
    ld dy = y[i] - y[j];
    return sqrt(dx * dx + dy * dy);
}

int main()
{

    ifstream fin("cowtour.in");
    ofstream fout("cowtour.out");

    fin >> n;
    for (int i = 0; i < n; i++)
    {
        fin >> x[i] >> y[i];
        /*cout << x[i] << y[i];*/

    }

    for (int i = 0; i < n; i++)
    {
        fin >> s;
        for (int j = 0; j < n; j++)
        {
            if (s[j] == '1')
                adj[i][j] = dist(i, j);
            else
                adj[i][j] = inf;
            if (i == j)
                adj[i][j] = 0;
        }

    }

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }

    ld ans = inf;

    for (int i = 0; i < n; i++)
    {
        maxdist[i] = -1;

        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] == inf)
                continue;
            maxdist[i] = max(maxdist[i], adj[i][j]);
        }

        for (int j = 0; j < i; j++)
        {
            if (adj[i][j] != inf)
                continue;

            ans = min(ans, maxdist[i] + dist(i, j) + maxdist[j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        ans = max(ans, maxdist[i]);
    }

    fout << fixed << setprecision(6) << ans << endl;

    fin.close();
    fout.close();
}