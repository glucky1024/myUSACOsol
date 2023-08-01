/*
ID: jockeys1
TASK: fracdec
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
#include <iomanip>

using namespace std;

int n, d;
int num = 0;

void print(ofstream& fout, const string& x)
{
    for (char c : x)
    {
        if (num == 76)
        {
            fout << endl;
            num = 0;
        }
        cout << c;
        fout << c;
        num++;
    }
}

void print(ofstream& fout, int x)
{
    print(fout, to_string(x));
}

int main()
{
    ifstream fin("fracdec.in");
    ofstream fout("fracdec.out");

    fin >> n >> d;
    if (n % d == 0)
    {
        print(fout, n / d);
        print(fout, ".0");
        //fout << endl;
    }
    else {
        print(fout, n / d);
        print(fout, ".");
        n = n % d;
        vector<int> val;
        map<int, int> pos;

        while (true)
        {
            int nn = n * 10;
            int dd = nn / d;
            nn = nn % d;
            if (n == 0)
            {
                for (int i = 0; i < val.size(); i++)
                {
                    print(fout, val[i]);
                }
                break;
            }

            if (pos.find(n) != pos.end())
            {
                for (int i = 0; i < pos[n]; i++)
                {
                    print(fout, val[i]);
                }
                print(fout, "(");
                for (int i = pos[n]; i < val.size(); i++)
                {
                    print(fout, val[i]);
                }
                print(fout, ")");
                break;
            }
            else {
                pos[n] = pos.size();
                val.push_back(dd);
                n = nn;
            }
        }

    }
    fout << endl;

    fin.close();
    fout.close();

    return 0;
}