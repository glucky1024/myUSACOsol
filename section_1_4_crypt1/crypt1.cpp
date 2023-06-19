/*
PROG: crypt1
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

bool ReadIn(const std::string& sFile, vector<int>& vecNums)
{
    fstream in_file;
    in_file.open(sFile, ios::in);
    if (!in_file.is_open())
    {
        cout << "Error: cannot open crypt1.in file." << endl;
        return false;
    }

    int n = 0;
    in_file >> n;

    for (int i = 0; i < n; i++)
    {
        int id = 0;
        in_file >> id;
        vecNums.push_back(id);
    }

    return true;
}

bool match(int val, const vector<int>& vecNums)
{
    while (val > 0)
    {
        int a = val % 10;
        bool bFound = false;
        for (int i : vecNums) {
            if (i == a) {
                bFound = true;
                break;
            }
        }

        if (!bFound)
            return false;

        val = floor(val / 10);
    }

    return true;
}

int Calculate(const vector<int>& vecNums)
{
    unsigned int n = vecNums.size();

    std::vector<int> vecFound;
    for (unsigned int i = 0; i < n; i++) {
        for (unsigned int j = 0; j < n; j++) {
            for (unsigned int k = 0; k < n; k++) {
                for (unsigned int l = 0; l < n; l++) {
                    for (unsigned int m = 0; m < n; m++) 
                    {
                        int a = vecNums[i];
                        int b = vecNums[j];
                        int c = vecNums[k];
                        int d = vecNums[l];
                        int e = vecNums[m];

                        int abc = a * 100 + b * 10 + c;
                        int de = d * 10 + e;

                        int p1 = abc * e;
                        if (p1 > 999 || !match(p1, vecNums))
                            continue;

                        int p2 = abc * d;
                        if (p2 > 999 || !match(p2, vecNums))
                            continue;

                        int sol = p1 + p2 * 10;
                        if (sol > 9999 || !match(sol, vecNums))
                            continue;

                        vecFound.push_back(sol);
                    }
                }
            }
        }
    }

    return vecFound.size();
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
    vector<int> vecNums;
    bool bOk = ReadIn("crypt1.in", vecNums);
    if (!bOk) { return 0; }

    int ans = Calculate(vecNums);

    WriteOut("crypt1.out", ans);

    return 0;
}
