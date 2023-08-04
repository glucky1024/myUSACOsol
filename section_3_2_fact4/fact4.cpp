/*
ID: jockeys1
TASK: fact4
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
    ifstream fin("fact4.in");
    ofstream fout("fact4.out");

    if (!fin.is_open()) {
        cout << "cannot find the file fact4." << endl;
        return 0;
    }

    int n;           

    fin >> n;

    int d = 1;
    int two = 0;
    int five = 0;

    for (int i = 2; i <= n; ++i)
    {
        int ii = i;
        while (ii % 2 == 0)
            ii /= 2, two++;
        while (ii % 5 == 0)
            ii /= 5, five++;

        d = (d * ii) % 10;
    }
    two = two - five;
    for (int i = 0; i < two; ++i)
    {
        d = (d * 2) % 10;
    }
    fout << d << endl; 
  
    fin.close();
    fout.close();
}

