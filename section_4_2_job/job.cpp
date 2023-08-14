/*
ID: jockeys1
TASK: job
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

#define nn     1000
#define mm     30

int main()
{
    ifstream fin("job.in");
    ofstream fout("job.out");

    if (!fin.is_open()) {
        cout << "cannot find the file job." << endl;
        return 0;
    }

    int n;
    static int m[2], a[2][mm], b[2][mm], ti[2][nn];

    fin >> n >> m[0] >> m[1];
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < m[i]; j++)
        {
            fin >> a[i][j];
            b[i][j] = a[i][j];
        }

    for (int i = 0; i < 2; i++)
    {
        sort(ti[i], ti[i] + n, [](int ii, int jj)
        {
            return ii > jj;
        });

        int ans = 0;
        for (int j = 0; j < n; j++)
        {
            int mink = min_element(a[i], a[i] + m[i]) - a[i];
            if (i == 0)
                ti[i + 1][j] = ti[i][j] + a[i][mink];
            ans = max(ans, ti[i][j] + a[i][mink]);
            a[i][mink] += b[i][mink];

        }

        fout << ans;
        if (i == 0)
            fout << " ";
    }
   
    fout << endl;

    fin.close();
    fout.close();
}