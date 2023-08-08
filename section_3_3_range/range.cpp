/*
ID: jockeys1
TASK: range
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

const int nn = 255;
int n, dp[nn][nn], ans[nn];
char a[nn][nn];

int main()
{
    ifstream fin("range.in");
    ofstream fout("range.out");

    if (!fin.is_open()) {
        cout << "cannot find the file range." << endl;
        return 0;
    }

    fin >> n;
    for (int i = 1; i <= n; i++)
    {
        fin >> a[i] + 1;
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == '1')
            {
                dp[i][j] = min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] } ) +1;
            }
            else {
                dp[i][j] = 0;
            }
            for (int k = 2; k <= dp[i][j]; k++)
            {
                ans[k]++;
            }
        }
    for (int i = 2; i <= n; i++)
    {
        if (ans[i])
        {
            fout << i << " " << ans[i] << endl;
        }
    }


            fin.close();
            fout.close();
        }
