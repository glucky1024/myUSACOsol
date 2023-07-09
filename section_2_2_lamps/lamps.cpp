/*
ID: jockeys1
TASK: lamps
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

using vi = vector<int>;

int n, cc;
vi on, off;
set<vi> ans;


bool check(vi lamps)
{
    for (int x : on) if (lamps[x] == 0) return false;
    for (int x : off) if (lamps[x] == 1) return false;
    return true;
}

vi A(vi x)
{
    for (int i = 1; i <= n; i++) x[i] = 1 - x[i];
    return x;
}

vi B(vi x)
{
    for (int i = 1; i <= n; i+=2) x[i] = 1 - x[i];
    return x;
}

vi C(vi x)
{
    for (int i = 2; i <= n; i+=2) x[i] = 1 - x[i];
    return x;
}

vi D(vi x)
{
    for (int i = 1; i <= n; i += 3) x[i] = 1 - x[i];
    return x;
}


void dfs(vi lamps, int count, bool a, bool b, bool c , bool d )
{
    if (count > cc) return;
    if ((cc - count) % 2 == 0)
    {
        if (check(lamps)) {
            ans.insert(lamps);
        }
    }
    if (!a) dfs(A(lamps), count + 1, 1, b, c, d);
    if (!b) dfs(B(lamps), count + 1, a, 1, c, d);
    if (!c) dfs(C(lamps), count + 1, a, b, 1, d);
    if (!d) dfs(D(lamps), count + 1, a, b, c, 1);
}


int main()
{
    ifstream fin("lamps.in");
    ofstream fout("lamps.out");

    fin >> n >> cc;
    int t;
    fin >> t;
    while (t != -1) {
        on.push_back(t);
        fin >> t;
    }

    fin >> t;
    while (t != -1) {
        off.push_back(t);
        fin >> t;
    }

    vi lamps(n + 1, 1);
    dfs(lamps, 0, 0, 0, 0, 0);
    if (ans.size() == 0) {
        fout << "IMPOSSIBLE" << endl;
    }
    else {
        for (vi x : ans) {
            for (int i = 1; i <= n; i++)
            {
                fout << x[i];
            }
            fout << endl;
        }
    }

}