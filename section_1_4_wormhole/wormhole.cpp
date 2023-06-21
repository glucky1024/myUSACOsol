
/*
PROG: wormhole
LANG: C++11
*/


#include <fstream>
#include <iostream>

using namespace std;

int n;
int x[20], y[20], nxt[20], part[20], answer;
bool paired[20];

bool check()
{
    for (int s = 1; s <= n; s++)
    {
        int cur = s;
        for (int it = 1; it <= n; it++) cur = part[nxt[cur]];
        if (cur) return true;
    }
    return false;
}

void dfs()
{
    int f = 1;
    while (paired[f] && f <= n)
    {
        f++;
    }

    if (f == n + 1)
    {
        if (check()) {
            answer++;
        }
    }

    for (int s = f + 1; s <= n; s++)
    {
        if (!paired[s])
        {
            paired[f] = paired[s] = true;
            part[f] = s; part[s] = f;
            dfs();
            paired[f] = paired[s] = false;
            part[f] = s; part[s] = 0;
        }
    }
}

int main()
{
    ifstream fin("wormhole.in");
    ofstream fout("wormhole.out");

    fin >> n;
    nxt[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        fin >> x[i] >> y[i];
        nxt[i] = 0;
        paired[i] = 0;
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j && y[i] == y[j] && x[j] >= x[i] &&
                (!nxt[i] || x[j] < x[nxt[i]]))
            {
                nxt[i] = j;
            }

    answer = 0;
    dfs();
    cout << answer << endl;
    fout << answer << endl;
}