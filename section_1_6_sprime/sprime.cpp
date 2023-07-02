/*
ID: jockeys1
TASK: sprime
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

using namespace std;


int NN;
vector<int> cur, nex;

bool prime(int x)
{
    for (int y = 2; y * y <= x; y++)
    {
        if (x % y == 0) 
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ifstream fin("sprime.in");
    ofstream fout("sprime.out");

    fin >> NN;
    //n=1
    cur = { 2,3,5,7 };
    //n=(2-N)
    for (int n = 2; n <= NN; n++)
    {
        nex.clear();
        for (int x : cur)
        {
            x *= 10;
            for (int d = 1; d <= 9; d++)
            {
                if (prime(x + d)) 
                {
                    nex.push_back(x + d);
                }
            }
        }
        swap(nex, cur);
    }

    for(int x : cur) 
    {
        fout << x << endl;
        cout << x << endl;
    }
}