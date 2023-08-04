/*
ID: jockeys1
TASK: butter
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
#include <utility>
#include <queue>

using namespace std;
using pi = pair<int, int>;
template<class t> using pqg = priority_queue<t, vector<t>, greater<t>>;

const int nn = 805;
int n, p, c;
int cc[nn];   // # cows in cc[i]
int dist[nn];
vector<pi> adj[nn];   //edges

int rand(int src)
{
    memset(dist, 69, sizeof(dist));
    pqg<pi> q;
    q.push({ 0,src });
    dist[src] = 0;
    while (q.size())
    {
        pi x = q.top(); q.pop();
        if (x.first > dist[x.second])
            continue;
        for (pi y : adj[x.second])
        {
            int nw = x.first + y.second;
            if (nw < dist[y.first])
            {
                dist[y.first] = nw;
                q.push({ nw, y.first });
            }
        }
    }
    int total =0;
    for (int i = 1; i <= p; i++)
    {
        total += dist[i] * cc[i];
    }
    return total;
}

int main()
{
    ifstream fin("butter.in");
    ofstream fout("butter.out");

    if (!fin.is_open()) {
        cout << "cannot find the file butter." << endl;
        return 0;
    }

    fin >> n >> p >> c;
    for (int i = 0, j; i < n; i++)
    {
        fin >> j;
        cc[j]++;
    }
    for (int i = 0, a, b, d; i < c; i++)
    {
        fin >> a >> b >> d;
        adj[a].push_back({ b,d });
        adj[b].push_back({ a,d });
    }

    int ans = 1e9;
    for (int i = 1; i <= p; i++)
    {
        ans = min(ans, rand(i));
    }

    fout << ans << endl;


    fin.close();
    fout.close();
}

