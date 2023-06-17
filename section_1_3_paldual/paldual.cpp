/*
PROG: dualpal
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;

bool ReadIn(const std::string& sFile, int& n, int& min)
{
    fstream in_file;
    in_file.open(sFile, ios::in);
    if (!in_file.is_open())
    {
        cout << "Error: cannot open dualpal.in file." << endl;
        return false;
    }

    in_file >> n >> min;

    return true;
}

const string numbers = "0123456789ABCDEFGHIJKLMN";
string convert(int input, int b) {
    string result = "";
    while (input > 0) {
        int remainder = input % b;
        result += numbers[remainder];
        input -= remainder;
        input /= b;
    }
    string reverse(result.rbegin(), result.rend());
    return reverse;
}


bool Calculate(int n, int min, vector<int>& vecBase10)
{
    vecBase10.clear();

    for (int i = min+1; i < 100000; i++)
    {
        bool bSys = true;
        int count = 0;
        for (int base = 2; base <= 10; base++)
        {
            bSys = true;
            string sConverted = convert(i, base);
            int l = sConverted.size();
            for (int j = 0; j < floor(l / 2); ++j)
            {
                if (sConverted.at(j) != sConverted.at(l - j - 1))
                {
                    bSys = false;
                    break;
                }
            }

            if (bSys)
                count++;

            if (count > 1)
                break;
        }

        if (count > 1) {
            vecBase10.push_back(i);
        }

        if (vecBase10.size() >= n)
            break;
    }

    return true;
}

bool WriteOut(const string& sFile, const vector<int>& vecBase10)
{

    for (int i = 0; i < vecBase10.size(); i++)
    {
        cout << vecBase10[i] << endl;
    }

    ofstream out_file;
    out_file.open(sFile);

    for (int i = 0; i < vecBase10.size(); i++)
    {
        out_file << vecBase10[i] << endl;
    }

    out_file.close();

    return true;
}

int main()
{
    int n, min;
    bool bOk = ReadIn("dualpal.in", n, min);
    if (!bOk) { return 0; }

    vector<int> vecBase10;
    bOk = Calculate(n, min, vecBase10);
    if (!bOk) { return 0; }

    WriteOut("dualpal.out", vecBase10);

    return 0;
}
