/*
PROG: skidesign
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

#define SQ(x) (x)*(x)

using namespace std;

bool ReadIn(const std::string& sFile, vector<int>& heights)
{
    fstream in_file;
    in_file.open(sFile, ios::in);
    if (!in_file.is_open())
    {
        cout << "Error: cannot open skidesign.in file." << endl;
        return false;
    }

    int n = 0;
    in_file >> n;

    for (int i = 0; i < n; i++)
    {
        int id = 0;
        in_file >> id;
        heights.push_back(id);
    }

    return true;
}


int Calculate(const vector<int>& heights)
{
    int ans = INT_MAX;
    for (int st = 0; st <= 83; st++) {
        int end = st + 17; 
        int sum = 0;
        for (int i = 0; i < heights.size(); i++) {
            int iVal = heights[i];
            if (iVal < st)
            {
                sum += SQ(st - iVal);
            }
            if (iVal > end)
            {
                sum += SQ(end - iVal);
            }
        }

        ans = sum < ans ? sum : ans;
    }

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
    int n = 0;
    vector<int> heights;
    bool bOk = ReadIn("skidesign.in", heights);
    if (!bOk) { return 0; }

    int ans = Calculate(heights);

    WriteOut("skidesign.out", ans);

    return 0;
}
