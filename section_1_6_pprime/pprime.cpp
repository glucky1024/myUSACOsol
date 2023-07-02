/*
ID: jockeys1
TASK: pprime
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


int a, b;
vector<int> ans;

#define ODD(a) for(int a=1; a<=9; a+=2)
#define FOR(a, l, r) for (int a=(l) ; a<=(r); a++)


bool check(int num)
{
    if (num <a || num >b)
        return false;

    for (int i = 2; i*i <= num; i++)
    {
        if (num % i == 0)
            return false;
    }

    return true;
}

int main()
{
    ifstream fin("pprime.in");
    ofstream fout("pprime.out");

    fin >> a >> b;
    cout << "reading: " << a << " " << b << endl;

    //one dig
    ODD(i) {
        int num = i;
        if (check(num)) ans.push_back(num);
    }
    //two dig
    ODD(i)
    {
        int num = i * 10 + i;
        if (check(num)) ans.push_back(num);
    }
    //three dig
    ODD(i)  FOR(j, 0, 9)
    {
        int num = i * 100 + j * 10 + i;
        if (check(num)) ans.push_back(num);
    }
    //four dig
    ODD(i)  FOR(j, 0, 9)
    {
        int num = i * 1000 + j * 100 + j * 10 + i;
        if (check(num)) ans.push_back(num);
    }
    //five dig
    ODD(i)  FOR(j, 0, 9) FOR(k, 0, 9)
    {
        int num = i * 10000 + j * 1000 + k * 100 + j * 10 + i;
        if (check(num)) ans.push_back(num);
    }
    //6 dig
    ODD(i)  FOR(j, 0, 9) FOR(k, 0, 9)
    {
        int num = i * 100000 + j * 10000 + k * 1000 + k * 100 + j * 10 + i;
        if (check(num)) ans.push_back(num);
    }
    //7 dig
    ODD(i)  FOR(j, 0, 9) FOR(k, 0, 9) FOR(l, 0, 9)
    {
        int num = i * 1000000 + j * 100000 + k * 10000 + l * 1000 + k * 100 + j * 10 + i;
        if (check(num)) ans.push_back(num);
    }
    //8 dig
    ODD(i)  FOR(j, 0, 9) FOR(k, 0, 9) FOR(l, 0, 9)
    {
        int num = i * 10000000 + j * 1000000 + k * 100000 + l * 10000 + l * 1000 + k * 100 + j * 10 + i;
        if (check(num)) ans.push_back(num);
    }
    //9 dig
    ODD(i)  FOR(j, 0, 9) FOR(k, 0, 9) FOR(l, 0, 9)  FOR(m, 0, 9)
    {
        int num = i * 100000000 + j * 10000000 + k * 1000000 + l * 100000 + m * 10000 + l * 1000 + k * 100 + j * 10 + i;
        if (check(num)) ans.push_back(num);
    }

    sort(ans.begin(), ans.end());
    for (int a : ans)
        cout << a << endl;
    for (int a : ans)
        fout << a << endl;

    if (ans.empty())
        cout << "none" << endl;
}
