/*
ID: jockeys1
TASK: rockers
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

int n, t, m, sz[30];
int ans = 0;

void dfs(int i, int j, int k, int l)
{
    if (k > m || l > t)
        return;
    if (i == n + 1)
    {
        ans = max(ans, j);
        return;
    }
    dfs(i + 1, j, k, l);
    dfs(i + 1, j + 1, k, l + sz[i]);
    dfs(i + 1, j + 1, k + 1, sz[i]);
}

int main()
{
    ifstream fin("rockers.in");
    ofstream fout("rockers.out");

    if (!fin.is_open()) {
        cout << "cannot find the file rockers." << endl;
        return 0;
    }

    fin >> n >> t >> m;
    for (int i = 1; i <= n; i++)
    {
        fin >> sz[i];
    }

    dfs(1, 0, 1, 0);
    fout << ans << endl;

    fin.close();
    fout.close();
}