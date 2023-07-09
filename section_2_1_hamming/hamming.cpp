/*
ID: jockeys1
TASK: hamming
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

int hamming(int a, int b)
{
    bitset<8> c(a ^ b);
    return c.count();
}

int main()
{
    ifstream fin("hamming.in");
    ofstream fout("hamming.out");

    int n, b, d;
    vector<int> ans;

    fin >> n >> b >> d;
    for (int i = 0; i <= b; i++)
    {
        for (int i = 0; i < (1 << b); i++)
        {
            bool flag = 1;
            for (int x : ans)
            {
                if (hamming(x, i) < d)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                ans.push_back(i);
                if (ans.size() == n) break;

            }
        }

       
       

        }
    int printed = 0;
    for (int i = 0; i < n; i++)
    {
        fout << ans[i];
        printed++;
        if (printed == 10 || i == n - 1)
        {
            printed = 0;
            fout << endl;
        }
        else
        {
            fout << " ";
        }
    }
}