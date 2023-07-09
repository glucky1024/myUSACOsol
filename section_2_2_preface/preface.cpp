/*
ID: jockeys1
TASK: preface
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

int n;

map<char, int> occ;

char    ord[] = {'I', 'V', 'X',  'L',  'C',  'D',  'M'};
string v[] = { "M",  "CM", "D","CD", "C",  "XC", "L", "XL", "X", "IX", "V","IV", "I" };
int vv [] = {1000,  900, 500,    400, 100,  90,   50,  40,   10,   9,   5,   4,   1};

void add(string k)
{
    for(char c : k) occ[c]++;

}
void calc(int x)
{
    for (int i = 0; i < 13; i++)
    {
        while (x >= vv[i]) {
            x -= vv[i];
            add(v[i]);
        }
    }
}

int main()
{
    ifstream fin("preface.in");
    ofstream fout("preface.out");

    fin >> n;
    for (int i = 1; i <= n; i++)
    {
        calc(i);
    }
    for (int i = 0; i < 7; i++)
    {
        if (occ[ord[i]])
        {
            fout << ord[i] << " " << occ[ord[i]] << endl;
            cout << ord[i] << " " << occ[ord[i]] << endl;
        }
    }
}