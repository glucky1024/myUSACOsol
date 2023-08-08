/*
ID: jockeys1
TASK: game1
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

const int n = 105;
int nn, a[n], dp[n][n];
int sum = 0;

int main()
{
    ifstream fin("game1.in");
    ofstream fout("game1.out");

    if (!fin.is_open()) {
        cout << "cannot find the file game1." << endl;
        return 0;
    }

    fin >> nn;
    for (int i = 1; i <= nn; i++)
    {
        fin >> a[i]; 
        sum += a[i];
        dp[i][i] = a[i];
    }

    for (int i = nn; i >= 1; i--)
        for (int j = i + 1; j <= nn; j++)
        {
            dp[i][j] = max(a[i] - dp[i + 1][j],
                           a[j] - dp[i][j - 1]);
        }
    int s1 = (dp[1][nn] + sum) / 2;
    int s2 = sum - s1;

    fout << s1 << " " << s2 << endl;

    fin.close();
    fout.close();
}