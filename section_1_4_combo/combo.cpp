/*
PROG: combo
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

bool ReadIn(const std::string& sFile, int& n, vector<int>& combo1, vector<int>& combo2)
{
    fstream in_file;
    in_file.open(sFile, ios::in);
    if (!in_file.is_open())
    {
        cout << "Error: cannot open combo.in file." << endl;
        return false;
    }

    in_file >> n;

    for (int i = 0; i < 3; i++)
    {
        int id = 0;
        in_file >> id;
        combo1.push_back(id);
    }

    for (int i = 0; i < 3; i++)
    {
        int id = 0;
        in_file >> id;
        combo2.push_back(id);
    }

    return true;
}


int Calculate(int n, const vector<int>& vec1, const vector<int>& vec2)
{
    if (vec1.size() != 3 || vec2.size() != 3) { assert(0); return -1; }

    vector<int> vecI, vecJ, vecK;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++)
            {
                int diffI0 = abs(vec1[0] - i);
                int diffI1 = abs(n - i + vec1[0]);
                int diffI2 = abs(n + i - vec1[0]);
                int diffJ0 = abs(vec1[1] - j);
                int diffJ1 = abs(n - j + vec1[1]);
                int diffJ2 = abs(n + j - vec1[1]);
                int diffK0 = abs(vec1[2] - k);
                int diffK1 = abs(n - k + vec1[2]);
                int diffK2 = abs(n + k - vec1[2]);
                if ((diffI0 <= 2 || diffI1 <= 2 || diffI2 <= 2) &&
                    (diffJ0 <= 2 || diffJ1 <= 2 || diffJ2 <= 2) &&
                    (diffK0 <= 2 || diffK1 <= 2 || diffK2 <= 2))
                {
                    vecI.push_back(i);
                    vecJ.push_back(j);
                    vecK.push_back(k);
                    continue;
                }

                //
                diffI0 = abs(vec2[0] - i);
                diffI1 = abs(n - i + vec2[0]);
                diffI2 = abs(n + i - vec2[0]);
                diffJ0 = abs(vec2[1] - j);
                diffJ1 = abs(n - j + vec2[1]);
                diffJ2 = abs(n + j - vec2[1]);
                diffK0 = abs(vec2[2] - k);
                diffK1 = abs(n - k + vec2[2]);
                diffK2 = abs(n + k - vec2[2]);
                if ((diffI0 <= 2 || diffI1 <= 2 || diffI2 <= 2) &&
                    (diffJ0 <= 2 || diffJ1 <= 2 || diffJ2 <= 2) &&
                    (diffK0 <= 2 || diffK1 <= 2 || diffK2 <= 2))
                {
                    vecI.push_back(i);
                    vecJ.push_back(j);
                    vecK.push_back(k);
                }
            }
        }
    }

    for (unsigned int i = 0; i < vecI.size(); ++i) {
        cout << vecI[i] << "," << vecJ[i] << "," << vecK[i] << endl;
    }

    return vecI.size();
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
    vector<int> combo1, combo2;
    bool bOk = ReadIn("combo.in", n, combo1, combo2);
    if (!bOk) { return 0; }

    int ans = Calculate(n, combo1, combo2);

    WriteOut("combo.out", ans);

    return 0;
}
