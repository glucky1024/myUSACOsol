/*
ID: jockeys1
TASK: runround
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

using ll = long long;

bool run(ll m)
{
    vector<int>  d;
    while (m)
    {
        d.push_back(m % 10);
        m /= 10;
    }
    reverse(d.begin(), d.end());
    int n = d.size();

    for (int i = 0; i < n; i++)
    {
        if (d[i] == 0) return false;
    }

    vector<int> count(10);
    for (int i = 0; i < n; i++)
    {
        if (count[d[i]]) return false;
        count[d[i]]++;
    }

    vector<int> count2(10);
    int cur = 0, ncur;
    for (int i = 0; i < n; i++)
    {
        ncur = (cur + d[cur]) % n;
        count2[d[cur]]++;
        if (count2[d[ncur]] && ncur != 0) return false;
        cur = ncur;
    }
    return true;
}

int main()
{
    ifstream fin("runround.in");
    ofstream fout("runround.out");

    ll m; fin >> m;

    ++m;
    while (!run(m)) m++;

    fout << m << endl;

}