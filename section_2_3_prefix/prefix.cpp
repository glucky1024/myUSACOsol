/*
ID: jockeys1
TASK: prefix
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

int main()
{
    ifstream fin("prefix.in");
    ofstream fout("prefix.out");

    vector<string> a;
    string t, x;
    fin >> t;
    while (t != ".")
    {
        a.push_back(t);
        fin >> t;
    }
    while (getline(fin, t))
    {
        x += t;
    }

    int n = x.size();
    vector <bool> dp(n + 1);
    dp[0] = 1;

    for (int i = 0; i <= n; i++)
    {
        if (!dp[i]) 
            continue;
        for (string s : a)
        {
            int m = s.size();
            if (i + m > n) 
                continue;
            if (x.substr(i, m) == s) dp[i + m] = 1;
        }
    }

    int ans = -1;
    for (int i = n; i >= 0; i--)
        if (dp[i])
        {
            ans = i;
            break;
        }
    fout << ans << endl;

    fin.close();
    fout.close();
}