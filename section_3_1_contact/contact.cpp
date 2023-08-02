/*
ID: jockeys1
TASK: contact
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

int a, b, n;
string text;

map <string, int> pattern;
map<int, vector<string>> fre;

int main()
{
    ifstream fin("contact.in");
    ofstream fout("contact.out");

    if (!fin.is_open()) {
        cout << "cannot find the file contact." << endl;
        return 0;
    }

    fin >> a >> b >> n;
    string temp;
    while (getline(fin, temp)) text += temp;

    for (int size = a; size <= b; size++)
    {
        if (size > text.size())
            break;
        string base = text.substr(0, size);
        pattern[base]++;
        for (int i = size; i < text.size(); i++)
        {
            base.erase(base.begin());
            base += text[i];
            pattern[base]++;
        }
    }
    for (auto x : pattern)
    {
        fre[x.second].push_back(x.first);
    }
    for (auto x = fre.rbegin(); x != fre.rend(); x++)
    {
        if (!n)
            break;
        fout << x->first << endl;
        int done = 0;
        sort(x->second.begin(), x->second.end(), [](string a, string b) -> bool
            {
                if (a.size() != b.size())
                    return a.size() < b.size();
                else
                    return a < b;
            });


        fout << x->second[0];
        done++;
        for (int i = 1; i < x->second.size(); i++)
        {
            if (done == 6)
            {
                done = 0;
                fout << endl;
            }
            else
                fout << " ";
            fout << x->second[i];
            done++;
        }
        fout << endl;
        n--;


    }

    fin.close();
    fout.close();
}