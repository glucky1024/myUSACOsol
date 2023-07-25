/*
ID: jockeys1
TASK: money
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

int v, n, a[25];
long long dp[10001];

int main()
{
    ifstream fin("money.in");
    ofstream fout("money.out");


    fin >> v >>n;
    for (int i = 0; i < v; i++) fin >> a[i];
    dp[0] =1;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < n; j++){
            if (j + a[i] <= n) {
                dp[j + a[i]] += dp[j];
            }
        }
    }
    fout << dp[n] << endl;

}
