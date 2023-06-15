/*
PROG: friday
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

bool ReadIn(const std::string sFile, int& nYears)
{
    fstream in_file;
    in_file.open(sFile, ios::in);
    if (!in_file.is_open())
    {
        cout << "Error: cannot open friday.in file." << endl;
        return false;
    }

    in_file >> nYears;

    return true;
}


int getFebDays(int y)
{
    if (y == 1900 || y == 2100 || y == 2200 || y == 2300) {
        return 28;
    }
    else if (y % 4 == 0) {
        return 29;
    }

    return 28;
}

bool Calculate(int nYears, vector<int>& vec13th)
{
    vec13th.resize(7);
    int m2dTable[12] = { 31, 28, 31, 30, 31, 30,
                        31, 31, 30, 31, 30, 31 };

    int dateCount = 1; // monday
    for (int i = 0; i < nYears; i++)
    {
        int y = 1900 + i;

        for (int j = 0; j < 12; j++)
        {
            int daysPerMonth = m2dTable[j];
            if (j == 1)
            {
                daysPerMonth = getFebDays(y);
            }

            for (int k = 0; k < daysPerMonth; k++)
            {
                if (k == 12)
                {
                    int day = dateCount % 7;
                    vec13th[day] = vec13th[day] + 1;
                    cout << "13th day in year " << y << " month " << j + 1 << ", dateCount=" << dateCount << endl;
                }
                dateCount++;
            }
        }
    }

    return true;
}

bool WriteOut(const string& sFile, const vector<int>& vec13th) {

    for (int i : vec13th) {
        cout << i << " ";
    }
    cout << endl;

    //
    ofstream out_file;
    out_file.open(sFile);

    out_file << vec13th[6] << " " <<
        vec13th[0] << " " <<
        vec13th[1] << " " <<
        vec13th[2] << " " <<
        vec13th[3] << " " <<
        vec13th[4] << " " <<
        vec13th[5] << endl;

    out_file.close();

    return true;
}





int main()
{
    int nYears = 0;
    bool bOk = ReadIn("friday.in", nYears);
    if (!bOk) { return 0; }

    vector<int> vec13th;
    bOk = Calculate(nYears, vec13th);
    if (!bOk) { return 0; }

    WriteOut("friday.out", vec13th);

    return 0;
}
