/*
ID: jockeys1
TASK: maze1
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

using pi = pair<int, int>;

int n, m;
string graph[205];
vector < pi>  ent;
int dist[205][205];


int dx[] = { 0,0, 1, -1 };
int dy[] = { 1,-1,0,0 };

void dfs(int x, int y, int d)
{
    if (d >= dist[x][y])
        return;
    dist[x][y] = d;
    for (int k = 0; k < 4; k++)
    {
        int i = x + dx[k];
        int j = y + dy[k];
        if (i <0 || i >n || j < 0 || j>m)        //out of bounds
            continue;
        if (graph[i][j] == '-' || graph[i][j] == '|')
            continue; //wall
        i += dx[k]; j += dy[k];
        if (i <0 || i >n || j < 0 || j>m)        //out of bounds
            continue;
        if (graph[i][j] == '-' || graph[i][j] == '|')
            continue; //wall
        dfs(i, j, d + 1);
    }
}

int main()
{
    ifstream fin("maze1.in");
    ofstream fout("maze1.out");

    fin >> m >> n; // m=W, n=H
    n *= 2; m *= 2;
    std::getline(fin, graph[0]);
    for (int i = 0; i <= n; i++)
    {
        std::getline(fin, graph[i]);
    }

    for (int i = 0; i <= n; i++)
    {
        if (graph[i][0] == ' ')
            ent.push_back({ i, 1 });
        if (graph[i][m] == ' ')
            ent.push_back({ i, m - 1 });
    }
    for (int i = 0; i <= m; i++)
    {
        if (graph[0][i] == ' ')
            ent.push_back({ 1, i });
        if (graph[n][i] == ' ')
            ent.push_back({ n - 1, i });
    }
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
        {
            dist[i][j] = (int)1e9;
        }

    for (pi x : ent)
        dfs(x.first, x.second, 1);

    int ans = 0;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
        {
            if (dist[i][j] == 1e9)
                continue;
            ans = max(ans, dist[i][j]);
        }
    cout << ans << endl;
    fout << ans << endl;

    fin.close();
    fout.close();
}