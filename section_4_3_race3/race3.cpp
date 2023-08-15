/*
ID: jockeys1
TASK: race3
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

#define nn 50

int marked[nn];
vector<int> ej[nn];

void dfs(int i)
{
    marked[i] = 1;
    for (int j : ej[i])
        if (!marked[j])
            dfs(j);
}

int main()
{
    ifstream fin("race3.in");
    ofstream fout("race3.out");

    if (!fin.is_open()) {
        cout << "cannot find the file race3." << endl;
        return 0;
    }

    int n, i;
    vector <int> unavoid, split;

    n = 0;
    while (fin >> i)
    {
        if (i == -2)
        {
            n++;
        }
        else if (i == -1)
        {
            break;
        }
        else
        {
            // edge from n to i
            ej[n].push_back(i);
        }
    }

    for (i = 1; i < n; i++)
    {
        static int marked0[nn];

        marked[i] = 1;
        dfs(0);
        for (int j = 0; j < n; j++)
        {
            marked0[j] = marked[j];
            marked[j] = 0;
        }
        if (!marked0[n - 1])
        {
            // i is unavoidable
            unavoid.push_back(i);
            //i can reach i
            //0 can reach i
            dfs(i);
            bool splitting = 1;

            for (int j = 0; j < n; j++)
            {
                if (i != j && marked[j] && marked0[j])
                    splitting = 0;

                marked[j] = 0;
            }
            if (splitting)
                split.push_back(i);
        }
    }

    fout << unavoid.size();
    for (int i : unavoid)
        fout << " " << i;
    fout << endl;

    fout << split.size();
    for (int i : split)
        fout << " " << i;
    fout << endl;

    fin.close();
    fout.close();
}