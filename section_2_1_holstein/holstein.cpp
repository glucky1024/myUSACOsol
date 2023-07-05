/*
ID: jockeys1
TASK: holstein
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

using namespace std;

const int mxg = 20;
const int mxv = 1005;

int v, g;
int r[mxv], s[mxg][mxv];

vector<int> used;
int ans = mxg;
vector<int> ansv;

void dfs(int i)
{
    if (i == g + 1)
    {
        // check
        for (int j = 1; j <= v; j++)
        {
            int sum = 0;
            for (int k : used)
            {
                sum = sum + s[k][j];
            }
            if (sum < r[j]) return;
        }
        //if good update answer
        if (used.size() < ans) {
            ans = used.size();
            ansv = used;
        }

        return;
    }

    used.push_back(i);
    dfs(i + 1);
    used.pop_back();
    dfs(i + 1);
}


int main()
{
    ifstream fin("holstein.in");
    ofstream fout("holstein.out");

    fin >> v;
    for (int i = 1; i <= v; i++)
    {
        fin >> r[i];
        cout << r[i];
    }
    fin >> g;
    for (int i = 1; i <= g; i++)
        for (int j = 1; j <= v; j++)
        {
            fin >> s[i][j];
            cout << s[i][j];
        }

    dfs(1);



    fout << ans << " " << ansv[0];
    for (int i = 1; i < ansv.size(); i++)
    {
        fout << " " << ansv[i];
    }
    fout << endl;

    cout << ans << " " << ansv[0];
    for (int i = 1; i < ansv.size(); i++)
    {
        cout << " " << ansv[i];
    }
    cout << endl;
}