/*
ID: jockeys1
TASK: ratios
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



int main()
{
    ifstream fin("ratios.in");
    ofstream fout("ratios.out");

    if (!fin.is_open()) {
        cout << "cannot find the file ratios." << endl;
        return 0;
    }

    int g[3], m[3][3];

    for (int i = 0; i < 3; i++)
    {
        fin >> g[i];
    }

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            fin >> m[i][j];
        }

    int x[3] = { 0 }, y[3] = { 0 };
    int ans[3] = { 0 }; int ans2; int ansv = 1e9;

    for (x[0] = 0; x[0] <= 100; x[0]++)
        for (x[1] = 0; x[1] <= 100; x[1]++)
            for (x[2] = 0; x[2] <= 100; x[2]++)
            {
                /*if (x[0] == 0 && x[1] == 0 && x[2] == 0)
                    continue;*/
                y[0] = y[1] = y[2] = 0;
                for (int i = 0; i < 3; i++)
                {
                    y[0] += x[i] * m[i][0];
                    y[1] += x[i] * m[i][1];
                    y[2] += x[i] * m[i][2];
                }

                bool okay = true;
                for (int i = 0; i < 3; i++)
                {
                    if (y[i] == 0)
                    {
                        if (g[i])                      
                            okay = false;                     
                    }
                    if (g[i] == 0)
                    {
                        if (y[i])
                            okay = false;
                    }
                        else if (y[i] % g[i])
                            okay = false;
                }
                if (okay && (y[0] * g[1] == y[1] * g[0]) && (y[1] * g[2] == y[2] * g[1]))
                {
                    if (ansv > x[0] + x[1] + x[2])
                    {
                        ansv = x[0] + x[1] + x[2];
                        ans[0] = x[0], ans[1] = x[1], ans[2] = x[2];
                        if (g[0] != 0)
                            ans2 = y[0] / g[0];
                        else
                            ans2 = 0;
                    }
                }
            }
    if (ansv == 1e9)
        fout << "NONE" << endl;
    else
        fout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans2 << endl;

    fin.close();
    fout.close();
}

