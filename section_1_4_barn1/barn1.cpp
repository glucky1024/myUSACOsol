/*
PROG: barn1
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

using namespace std;

bool ReadIn(const std::string& sFile, int& M, int& S, int& C, vector<int>& s)
{
    fstream in_file;
    in_file.open(sFile, ios::in);
    if (!in_file.is_open())
    {
        cout << "Error: cannot open barn1.in file." << endl;
        return false;
    }

    in_file >> M >> S >> C;

    for (int i = 0; i < C; i++)
    {
        int id = 0;
        in_file >> id;
        s.push_back(id);
    }

    return true;
}


int Calculate(int M, int S, int C, vector<int>& s)
{

    sort(s.begin(), s.end());
    int ans = S;
    ans -= s[0] - 1;
    ans -= S - s.back();
    for (int i = 0; i < C - 1; i++) {
        s[i] = s[i + 1] - s[i] - 1;
    }
    s.pop_back();
    sort(s.rbegin(), s.rend());

    for (int i = 0; i<min(M-1, C-1); i++) ans -= s[i];
    return ans;
}

bool WriteOut(const string& sFile, int ans)
{
    cout << ans << endl;

    ofstream out_file;
    out_file.open(sFile);
    out_file << ans << endl;

    out_file.close();

    return true;
}

int main()
{
    int M, S, C = 0;
    vector<int> s;
    bool bOk = ReadIn("barn1.in", M, S, C, s);
    if (!bOk) { return 0; }

    int ans = Calculate(M, S, C, s);

    WriteOut("barn1.out", ans);

    return 0;
}
