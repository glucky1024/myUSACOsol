/*
PROG: palsquare
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

bool ReadIn(const std::string& sFile, int& base)
{
    fstream in_file;
    in_file.open(sFile, ios::in);
    if (!in_file.is_open())
    {
        cout << "Error: cannot open palsquare.in file." << endl;
        return false;
    }

    in_file >> base;

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


bool Calculate(int base, vector<int>& vecBase10, vector<string>& vec1, vector<string>& vec2)
{
    vec1.clear();
    vec2.clear();

    for (int i = 1; i <= 300; i++)
    {
        string sConverted2 = convert(i * i, base);
        int l = sConverted2.size();
        bool bSys = true;
        for (int j = 0; j < floor(l / 2); ++j)
        {
            if (sConverted2.at(j) != sConverted2.at(l - j - 1))
            {
                bSys = false;
                break;
            }
        }
        if (bSys) {
            string sConverted = convert(i, base);
            vecBase10.push_back(i);
            vec1.push_back(sConverted);
            vec2.push_back(sConverted2);
        }
    }

    return true;
}

bool WriteOut(const string& sFile, const vector<int>& vecBase10, const vector<string>& vec1, const vector<string>& vec2)
{
    int n = vec1.size();
    if (n != vec2.size())
    {
        assert(0);
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        cout << vecBase10[i] << " " << vec1[i] << " " << vec2[i] << endl;
    }

    ofstream out_file;
    out_file.open(sFile);

    for (int i = 0; i < n; i++)
    {
        out_file << vec1[i] << " " << vec2[i] << endl;
    }


    out_file.close();

    return true;
}

int main()
{
    int base;
    bool bOk = ReadIn("palsquare.in", base);
    if (!bOk) { return 0; }

    vector<string> vec1, vec2;
    vector<int> vecBase10;
    bOk = Calculate(base, vecBase10, vec1, vec2);
    if (!bOk) { return 0; }

    WriteOut("palsquare.out", vecBase10, vec1, vec2);

    return 0;
}
