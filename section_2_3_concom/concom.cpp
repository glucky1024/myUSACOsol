/*
ID: jockeys1
TASK: concom
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
#include <cstdio>

using namespace std;

using pi = pair<int, int >; 
int n;
vector < pi> owns[101];
int own[101], owned[101];

void dfs(int i) {
    if (owned[i]) return;
        owned[i] = 1;

    for (pi x : owns[i]) {
        own[x.first] += x.second;
        if (own[x.first] > 50)
        {
            dfs(x.first);
        }
    }
}

int main()
{
    freopen("concom.in", "r", stdin);
    freopen("concom.out", "w", stdout);

    scanf("%d", &n);
    for (int i=0; i < n; i++) {
        int x, y, p;
        scanf("%d%d%d", &x,&y,&p);
        owns[x].push_back({ y,p });
    }

    for (int i=1; i <= 100; i++) 
    {
        fill(own, own + 101, 0);
        fill(owned, owned+ 101, 0);
        dfs(i);
        for (int j = 1; j <= 100; j++) {
            if (i != j && owned[j])
            {
                printf("%d %d\n", i, j);
            }
        }
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
    
