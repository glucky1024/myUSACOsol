/*
ID: jockeys1
TASK: subset
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

int n, sum;
long long dp[2000];


int main()
{
    ifstream fin("subset.in");
    ofstream fout("subset.out");

    fin >> n;
    dp[0] = 1;
    sum = n * (n + 1) / 2;

    if (sum %2) fout << "0" << endl;
    else {
        sum /= 2;
      
        for (int i = 1; i <= n; i++) {
            for (int j = sum; j >= i; j--) {
                dp[j] += dp[j-i];
            }
        }
        cout << dp[sum] / 2 << endl;
        fout << dp[sum] / 2 << endl;
    }

}