/*
ID: jockeys1
TASK: inflate
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

int m, n;
int dp[10005];

int main()
{
    ifstream fin("inflate.in");
    ofstream fout("inflate.out");

    if (!fin.is_open()) {
        cout << "cannot find the file inflate." << endl;
        return 0;
    }

    fin >> m >> n;

    dp[0]=0;
    for (int i = 0; i < n; i++)
    {
        int pnt, min;
        fin >> pnt >> min;
        for (int j = min; j <= m; j++)
        {
            dp[j] = max(dp[j], dp[j - min] + pnt);
        }
    }

    int ans = 0;
    for (int i = 0; i <= m; i++)
    {
        ans = max(ans, dp[i]);
    }

    fout << ans << endl;

    fin.close();
    fout.close();
}