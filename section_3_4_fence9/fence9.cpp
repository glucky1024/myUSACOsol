/*
ID: jockeys1
TASK: fence9
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

struct p
{
    int x, y;
} a[3];

int n, m, p;

int main()
{
    ifstream fin("fence9.in");
    ofstream fout("fence9.out");

    if (!fin.is_open()) {
        cout << "cannot find the file fence9." << endl;
        return 0;
    }
    fin >> n >> m >> p;

    a[0] = { 0, 0 };
    a[1] = { n, m };
    a[2] = { p, 0 };

    // 1) find b

    int b = 0;
    for (int i = 0; i < 3; i++)
    {
        int j = (i + 1) % 3;
        int dy = abs(a[j].y - a[i].y);
        int dx = abs(a[j].x - a[i].x);
        b += __gcd(dx, dy);
    }

    int ans = (p * m - b) / 2 + 1;
    fout << ans << endl;

    fin.close();
    fout.close();
}