/*
ID: jockeys1
TASK: nuggets
LANG: C++17
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

const int up = 64769 + 1;

int n, a[10], dp[up];

int main()
{
    ifstream fin("nuggets.in");
    ofstream fout("nuggets.out");

    if (!fin.is_open()) {
        cout << "cannot find the file nuggets." << endl;
        return 0;
    }

    fin >> n;
    for (int i = 0; i < n; i++)
    {
        fin >> a[i];
    }

    int g = 0;
    for (int i = 0; i < n; i++)
    {
        g = std::gcd(g, a[i]);
    }
    if (g != 1)
    {
        fout << "0" << endl;
        return 0;
    }

    dp[0] = 1;
    for (int i = 1; i < up; i++)
        for (int j = 0; j < n; j++)
        {
            if (i >= a[j] && dp[i - a[j]] == 1)
                dp[i] = 1;
        }
    for (int i = up - 1; i >= 0; i--)
    {
        if (!dp[i])
        {
            fout << i << endl;
            return 0;
        }
    }
    fout << "0" << endl;

    fin.close();
    fout.close();
}