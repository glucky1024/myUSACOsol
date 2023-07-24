/*
ID: jockeys1
TASK: nocows
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

using namespace std;

int n, k;
int dp[201][201];

int main() 
    {
        ifstream fin("nocows.in");
        ofstream fout("nocows.out");


        fin >> n >> k;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= k; j++) {
                if (i == 1) dp[i][j] = 1;
                else {
                    for (int k = 1; k < i; k++)
                    {
                        dp[i][j] += dp[k][j - 1] * dp[i - k - 1][j - 1];
                        dp[i][j] %= 9901;
                    }
                }
            }
        int ans = (dp[n][k] - dp[n][k - 1] + 9901) % 9901;
        fout << ans << endl;
    }
