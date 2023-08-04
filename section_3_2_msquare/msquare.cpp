/*
ID: jockeys1
TASK: msquare
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

string goal;
set<string> v;
map< string, string> conf;  

string g(char c)
{
    return string(1, c);
}

int main()
{
    ifstream fin("msquare.in");
    ofstream fout("msquare.out");

    if (!fin.is_open()) {
        cout << "cannot find the file msquare." << endl;
        return 0;
    }

    for (int i = 0, x; i < 8; i++)
    {
        fin >> x;
        goal += char('0' + (x - 0));
    }

    queue<string> q;
    q.push("12345678");
    v.insert("12345678");
    conf["12345678"] = "";

    while (!q.empty())
    {
        string x = q.front(); q.pop();
        if (x == goal)
        {
            break;
        }

        //apply A
        string next = x;
        reverse(next.begin(), next.end());
        if (v.find(next) == v.end())
        {
            v.insert(next);
            conf[next] = conf[x] + "A";
            q.push(next);
        }

        //apply B
        next = g(x[3]) + g(x[0]) + g(x[1]) + g(x[2]) + g(x[5]) + g(x[6]) + g(x[7]) + g(x[4]);
        if (v.find(next) == v.end())
        {
            v.insert(next);
            conf[next] = conf[x] + "B";
            q.push(next);
        }

        //apply C
        next = g(x[0]) + g(x[6]) + g(x[1]) + g(x[3]) + g(x[4]) + g(x[2]) + g(x[5]) + g(x[7]);
        if (v.find(next) == v.end())
        {
            v.insert(next);
            conf[next] = conf[x] + "C";
            q.push(next);
        }

    }                                    

    fout << conf[goal].size() << endl;

    if(conf[goal].size())
    {
        int c = 0;
        for (char ch : conf[goal])
        {
            fout << ch;
            c++;
            if (c == 60)
            {
                c = 0;
                fout << endl;
            }
        }

        if (c != 0)
        {
            fout << endl;
        }
    }
    else {
        fout << endl;
    }

    fin.close();
    fout.close();
}