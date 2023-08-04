/*
ID: jockeys1
TASK: spin
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

using namespace std;

int main()
{
    ifstream fin("spin.in");
    ofstream fout("spin.out");

    if (!fin.is_open()) {
        cout << "cannot find the file spin." << endl;
        return 0;
    }

    int speed[5], num[5], st[5][5], ex[5][5], ones [360];

    for (int i = 0; i < 5; i++)
    {
        fin >> speed[i] >> num[i];
        for (int j = 0; j < num[i]; j++)
        {
            fin >> st[i][j] >> ex[i][j];
        }
    }

    for (int time = 0; time < 360; time++)
    {
        memset(ones, 0, sizeof(ones));
        for (int i = 0; i < 5; i++)
        {
            int dir = (time * speed[i]);
            for (int j = 0; j < num[i]; j++)
            {
                int start = (dir + st[i][j]);
                int end = start + ex[i][j];
                for (int k = start; k <= end; k++)
                {
                    ones[k % 360]++;
                }
            }
        }
        for (int j = 0; j < 360; j++)
        {
            if (ones[j] == 5)
            {
                fout << time << endl;
                return 0;
            }
        }
    }
    fout << "none" << endl;

    fin.close();
    fout.close();
}

