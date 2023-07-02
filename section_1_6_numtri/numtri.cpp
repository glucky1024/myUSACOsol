/*
ID: jockeys1
TASK: numtri
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

const int maxn = 1005;
int R;
int val[maxn][maxn];
int dp[maxn][maxn];

int main()
{
    ifstream fin("numtri.in");
    ofstream fout("numtri.out");

    fin >> R;
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            fin >> val[i][j];
        }
    }


    dp[1][1] = val[1][1];
    for (int i = 2; i <= R; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i][j] = val[i][j];
            if (j == 1)
                dp[i][j] += dp[i - 1][j];
            else if (j == 1)
                dp[i][j] += dp[i - 1][j - 1];
            else
                dp[i][j] += max(dp[i - 1][j], dp[i - 1][j - 1]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= R; i++)
    {
        ans = max(ans, dp[R][i]);
    }
    fout << ans << endl;
}