/*
ID: jockeys1
TASK: frac1
LANG: C++17
*/

#include <iostream>
#include <fstream>
#include <cassert>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <climits>
#include <numeric>

using namespace std;

using frac = pair<double, pair<int, int>>;
//typedef pair<double, pair<int, int>> frac;

// deomin ater
int n;
set<frac> fracs;

int main()
{
    ifstream fin("frac1.in");
    ofstream fout("frac1.out");

    fin >> n;

    fracs.insert({ 0., {0, 1} });

    for (int num = 0; num <= n; num++)
        for (int dem = num; dem <= n; dem++)
        {
            int gcd = std::gcd(num, dem);
            if (gcd == 0)
                continue;

            int num2 = num / gcd;
            int dem2 = dem / gcd;
            fracs.insert({ 1.0 * num2 / dem2, { num2,dem2 } });
        }

    for (frac f : fracs)
    {
        cout << f.second.first << "/" << f.second.second << endl;
        fout << f.second.first << "/" << f.second.second << endl;
    }


}