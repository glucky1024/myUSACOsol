/*
ID: jockeys1
TASK: kimbits
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

int n, l;
long long ii;

long long coef[32][32], num[32][32];

int main()
{
    ifstream fin("kimbits.in");
    ofstream fout("kimbits.out");

    if (!fin.is_open()) {
        cout << "cannot find the file kimbits." << endl;
        return 0;
    }

    fin >> n >> l >> ii;

    coef[0][0] = 1;
    for (int i = 0; i < 32; i++)
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
                coef[i][j] = 1;
            else
                coef[i][j] = coef[i - 1][j - 1] + coef[i - 1][j];
        }

    for (int i = 0; i < 32; i++)
        for (int j = 0; j < 32; j++)
            for (int k = 0; k <= j; k++)
            {
                num[i][j] += coef[i][k];
            }
    for (int i = n; i >= 1; i--)
    {
        long long x = num[i - 1][l];
        if (ii > x)
        {
            fout << "1";
            ii -= x;
            l--;
        }
        else {
            fout << "0";
        }
    }
    fout << endl;

    fin.close();
    fout.close();
}

