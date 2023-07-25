/*
ID: jockeys1
TASK: zerosum
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

int n;
vector<string> ans;
int eval(string s)
{
    int sign = 1;
    int result = 0;
    int cur = 0;
    for (char c : s)
    {
        if (c == '+'){
            result += sign * cur;
                sign = 1;cur = 0;
        }  else if (c == '-') {
            result += sign * cur;
            sign = -1; cur = 0;
        }  else if (c == ' ') {
            cur = cur * 10;
        }   else {
            cur = cur + (c- '0');
        }

    }
    result += sign * cur;
    return result;

}

void dfs(int nn, string s)
{
    if (nn == n + 1) {
        if (eval(s) == 0)
       {
            ans.push_back(s);
       }
        return;
    }
    dfs(nn + 1, s + "+" + to_string(nn));
    dfs(nn + 1, s + "-" + to_string(nn));
    dfs(nn + 1, s + " " + to_string(nn));
}

int main()
{
    ifstream fin("zerosum.in");
    ofstream fout("zerosum.out");


    fin >> n;
    dfs(2, "1");
    sort(begin(ans), end(ans));

    for (string s: ans) fout << s << endl;
}
