/*
PROG: milk2
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

bool ReadIn(const std::string& sFile, vector <int>& vecStart, vector <int>& vecEnd)
{
    fstream in_file;
    in_file.open(sFile, ios::in);
    if (!in_file.is_open())
    {
        cout << "Error: cannot open milk2.in file." << endl;
        return false;
    }

    vecStart.clear();
    vecEnd.clear();

    int nCows = 0;
    in_file >> nCows;

    for (int i = 0; i < nCows; i++)
    {
        int val1 = 0, val2 =0;
        in_file >> val1 >> val2;
        vecStart.push_back(val1);
        vecEnd.push_back(val2);
    }

    return true;
}


bool Calculate(const vector<int>& vecStart, const vector<int>& vecEnd, int& milking, int& idle)
{
    int nCows = vecStart.size();
    if (nCows != vecEnd.size())
    {
        assert(0);
        return false;
    }

    int min = 10000, max = 1;
#pragma omp parallel for
    for (int i = 0; i < nCows; ++i) {
        min = vecStart[i] < min ? vecStart[i] : min;
        max = vecEnd[i] > max ? vecEnd[i] : max;
    }
    cout << "min/max = " << min << " " << max << endl;

    bool bMilkPrevious = false;
    int count = 0;
    int milkMax = 0, idleMax = 0;
    for (int iTime = min; iTime <= max; iTime++)
    {
        bool bMilk = false;
        for (int j = 0; j < nCows; j++)
        {
            if (iTime >= vecStart[j] && iTime < vecEnd[j]) {
                bMilk = true;
                break;
            }
        }

        if (bMilkPrevious && !bMilk)
        {
            milkMax = count > milkMax ? count : milkMax;
            count = 1;
            bMilkPrevious = !bMilkPrevious;
        }
        else if (!bMilkPrevious && bMilk)
        {
            idleMax = count > idleMax ? count : idleMax;
            count = 1;
            bMilkPrevious = !bMilkPrevious;
        }
        else
        {
            count++;
        }
    }

    milking = milkMax;
    idle = idleMax;

    return true;
}

bool WriteOut(const string& sFile, int milking, int idle)
{
    cout << milking << " " << idle << endl;

    ofstream out_file;
    out_file.open(sFile);
    out_file << milking << " " << idle << endl;

    out_file.close();

    return true;
}

int main()
{
    vector <int> vecStart, vecEnd;
    bool bOk = ReadIn("milk2.in", vecStart, vecEnd);
    if (!bOk) { return 0; }

    int milking, idle = 0;
    bOk = Calculate(vecStart, vecEnd, milking, idle);
    if (!bOk) { return 0; }

    WriteOut("milk2.out", milking, idle);

    return 0;
}
