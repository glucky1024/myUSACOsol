/*
ID: jockeys1
TASK: sort3
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


int n;
int o[1005], s[1005];

int main()
{
    ifstream fin("sort3.in");
    ofstream fout("sort3.out");

    fin >> n;
    for (int i = 1; i <= n; i++) 
    {
        fin >> o[i];
        s[i] = o[i];        
    }
    sort(s + 1, s + n + 1);

    int ans = 0;

    // ab to ba
    for (int i = 1; i <= n; i++)
    {
        if (o[i] == s[i]) continue;
        for (int j = i + 1; j <= n; j++)
        {
            if (o[i] == s[j] && o[j] == s[i]) {
                swap(o[i], o[j]);
                ans++;
            }
        }
    }
    


    // abc to bca

    for (int i = 1; i <= n; i++)
    {
        if (o[i] == 1 && o[i] != s[i]) ans += 2;
    }

    fout << ans << endl;
    cout << ans << endl;
}