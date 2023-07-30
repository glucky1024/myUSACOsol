/*
ID: jockeys1
TASK: comehome
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


const int n = 52;
const int inf = 1e9;

int min(int a, int b)
{
    return(a < b ? a : b);
}

int code(char c)
{
    if (c >= 'a' && c <= 'z')
        return (c - 'a');
    else return (c - 'A' + 26);
}

int main()
{
    ifstream fin("comehome.in");
    ofstream fout("comehome.out");

    static int p, dd[52][52];

    fin >> p;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                dd[i][j] = 0;
            else
                dd[i][j] = inf;
        }

    for (int i = 0; i < p; i++)
    {
        char x, y;
        int d;
        fin >> x >> y >> d;
        int xx = code(x), yy = code(y);
        dd[xx][yy] = min(dd[xx][yy], d);
        dd[yy][xx] = min(dd[yy][xx], d);
    }

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                dd[i][j] = min(dd[i][j], dd[i][k] + dd[k][j]);
            }

    int best; int dist = inf;

    for (int i = 26; i < n - 1; i++)
    {
        if (dd[i][n - 1] < dist)
        {
            best = i;
            dist = dd[i][n - 1];
        }

    }

    fout << char('A' + best - 26) << " " << dist << endl;

}