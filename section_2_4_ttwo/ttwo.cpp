/*
ID: jockeys1
TASK: ttwo
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

using pi = pair<int, int>;
#define xx first
#define yy second

const int n = 10;
string grid[n];
pi c, f;

int x[] = {-1,0,1,0};
int y[] = {0,1,0,-1};

struct state
{
    pi fp, cp; 
    int fd, cd;
};

bool valid(pi p)
{
    if (p.xx < 0 || p.xx >= 10)
        return false;
    if (p.yy < 0 || p.yy >= 10)
        return false;
    if (grid[p.xx][p.yy] == '*')
        return false;
    return true;
}

int visited[10][10][10][10][4][4];

int main()
{
    ifstream fin("ttwo.in");
    ofstream fout("ttwo.out");

    if (!fin.is_open()) {
        cout << "cannot find the file." << endl;
        return 0;
    }

    for (int i = 0; i < 10; i++)
    {
        fin >> grid[i];
        for (int j = 0; j < 10; j++)
        {
            if (grid[i][j] == 'C')
                c = { i,j };
            if (grid[i][j] == 'F')
                f = { i,j };
        }
    }

    state s = { f,c, 0,0 };
    int dist = 0;

    while (s.fp != s.cp)
    {
        if (visited[s.fp.xx][s.fp.yy][s.cp.xx][s.cp.yy][s.fd][s.cd])
            break;

        visited[s.fp.xx][s.fp.yy][s.cp.xx][s.cp.yy][s.fd][s.cd] = 1;

        pi nf = { s.fp.xx + x[s.fd], s.fp.yy + y[s.fd] };
        if (!valid(nf))
        {
            s.fd = (s.fd + 1) % 4;
        }
        else {
            s.fp = nf;
        }

        pi nc = { s.cp.xx + x[s.cd], s.cp.yy + y[s.cd] };
        if (!valid(nc))
        {
            s.cd = (s.cd + 1) % 4;
        }
        else {
            s.cp = nc;
        }
        dist++;
    }
    if (s.fp != s.cp)
        fout << "0" << endl;
    else
        fout << dist << endl;


    fin.close();
    fout.close();
}