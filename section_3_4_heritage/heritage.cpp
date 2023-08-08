/*
ID: jockeys1
TASK: heritage
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
#include <cstring>
#include <utility>

using namespace std;

char in[30], pre[30];

ifstream fin("heritage.in");
ofstream fout("heritage.out");

void dfs(int i, int j, int x, int y)
{
    
    if (i == j) {
        fout << in[i];
        return;
    }
    else if (i > j) {
        return;
    }
    char root = pre[x]; int k = 0;
    for (int ii = 1; ii <= j; ii++)
    {
        if (in[ii] == root)
            k = ii;
    }
    dfs(i, k - 1, x + 1, x + k - i - 1);         //left
    dfs(k + 1, j, x + k - i + 1, y);         //right
    fout << root;
}

int main()
{

    if (!fin.is_open()) {
        cout << "cannot find the file heritage." << endl;
        return 0;
    }

    fin >> in >> pre;
    int n = strlen(in);
    dfs(0, n - 1, 0, n - 1);
    fout << endl;

    fin.close();
    fout.close();
}