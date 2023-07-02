/*
ID: jockeys1
TASK: castle
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

using namespace std;

char dir[] = { 'W','N','E','S' };

using pi = pair <int, int>;
#define f first
#define s second

struct cell {
    bool visited = false;
    int sz = 0;
    pi p = { -1, -1 };
    vector<bool> w = { 0,0,0,0 };
};

int n, m;
cell g[60][60];

int x[] = { 0,-1,0,1 };
int y[] = { -1,0,1,0 };

bool valid(pi xx)
{
    return xx.f >= 1 && xx.f <= n && xx.second >= 1 && xx.second <= m;
}

int dfs(pi c, pi p) {
    g[c.f][c.s].p = p;
    g[c.f][c.s].sz = 1;
    g[c.f][c.s].visited = true;

    for (int k = 0; k < 4; k++)
    {
        pi a = { c.f + x[k], c.second + y[k] };
        if (!valid(a)) continue;
        if (g[a.f][a.s].visited) continue;
        if (g[c.f][c.s].w[k])  continue;
        g[c.f][c.s].sz += dfs(a, p);
    }
    return g[c.first][c.second].sz;
}

int main()
{
    ifstream fin("castle.in");
    ofstream fout("castle.out");

    fin >> m >> n;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        {
            int k; fin >> k;
            g[i][j].visited = false;
            g[i][j].p = { -1, -1 };
            g[i][j].w = vector<bool>(4);
            if (k >= 8) {
                k -= 8;
                g[i][j].w[3] = 1;
            }

            if (k >= 4) {
                k -= 4;
                g[i][j].w[2] = 1;
            }

            if (k >= 2) {
                k -= 2;
                g[i][j].w[1] = 1;
            }
            if (k >= 1) {
                k -= 1;
                g[i][j].w[0] = 1;
            }

            //for (int m = 0; m < 4; m++)
            //{
            //    if ((1 << m) & k) {
            //        g[i][j].w[m] = 1;
            //    }
            //}
        }

    //
    int num = 0, maxsz = 0; 

    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        {
            if (g[i][j].visited)  continue;
            maxsz = max(maxsz, dfs({ i, j }, { i,j }));
            num++;
        }

    //
    int maxsz2 = 0;
    pi wall; int d;

    for (int j = 1; j <= m; j++)
    for (int i = n; i >=1; i--)
        {
        pi xx = g[i][j].p;
            for (int k = 0; k <=2; k++)
            {
                pi a = { i+ x[k], j+ y[k] };
                if (!valid(a)) continue;
                pi yy = g[a.f][a.s].p;
                int res = g[xx.f][xx.s].sz;
                if (xx != yy)  res += g[yy.f][yy.s].sz;
                if (res > maxsz2){
                    maxsz2 = res;
                    wall = { i,j }; d = k;
                    
                }
            }


    }

    cout << num << endl;
    cout << maxsz << endl;
    cout << maxsz2 << endl;
    cout << wall.f << " " << wall.s << " " << dir[d] << endl;

    fout << num << endl;
    fout << maxsz << endl;
    fout << maxsz2 << endl;
    fout << wall.f << " " << wall.s << " " << dir[d] << endl;





}