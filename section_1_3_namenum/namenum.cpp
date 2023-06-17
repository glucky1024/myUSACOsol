/*
PROG: namenum
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

bool ReadIn(const std::string& sFile, string& s)
{
    fstream in_file;
    in_file.open(sFile, ios::in);
    if (!in_file.is_open())
    {
        cout << "Error: cannot open namenum.in file." << endl;
        return false;
    }

    in_file >> s;

    return true;
}

bool ReadDict(const std::string& sFile, vector<string>& dict)
{
    fstream in_file;
    in_file.open(sFile, ios::in);
    if (!in_file.is_open())
    {
        cout << "Error: cannot open dict.txt file." << endl;
        return false;
    }

    dict.clear();
    while (true)
    {
        string sName;
        in_file >> sName;
        dict.push_back(sName);

        if (in_file.eof())
            break;
    }

    return true;
}

void getLetterByNumber(int iVal, vector<string>& tmp)
{
    switch (iVal)
    {
    case 2:
    {
        tmp.push_back("A");
        tmp.push_back("B");
        tmp.push_back("C");
    }
    break;
    case 3:
    {
        tmp.push_back("D");
        tmp.push_back("E");
        tmp.push_back("F");
    }
    break;
    case 4:
    {
        tmp.push_back("G");
        tmp.push_back("H");
        tmp.push_back("I");
    }
    break;
    case 5:
    {
        tmp.push_back("J");
        tmp.push_back("K");
        tmp.push_back("L");
    }
    break;
    case 6:
    {
        tmp.push_back("M");
        tmp.push_back("N");
        tmp.push_back("O");
    }
    break;
    case 7:
    {
        tmp.push_back("P");
        tmp.push_back("R");
        tmp.push_back("S");
    }
    break;
    case 8:
    {
        tmp.push_back("T");
        tmp.push_back("U");
        tmp.push_back("V");
    }
    break;
    case 9:
    {
        tmp.push_back("W");
        tmp.push_back("X");
        tmp.push_back("Y");
    }
    break;
    default:
        break;
    }
}

bool Calculate(const string& s, vector<string>& vecNames)
{
    vecNames.clear();
    for (int i = 0; i < s.size(); ++i)
    {
        string sub = s.substr(i, 1);
        int iVal = atoi(sub.c_str());
        vector<string> vecTmp;
        getLetterByNumber(iVal, vecTmp);

        vector<string> vecNew;
        for (string sTmp : vecTmp)
        {
            if (vecNames.empty()) 
            {
                vecNew.push_back(sTmp);
            }
            else {
                for (int j = 0; j < vecNames.size(); j++)
                {
                    vecNew.push_back(vecNames[j] + sTmp);
                }
            }
        }
        vecNames = vecNew;
    }

    //// print candidates
    //for (unsigned int i = 0; i < vecNames.size(); ++i) {
    //    cout << vecNames[i] << " ";
    //    if (i % 12 == 11)
    //        cout << endl;
    //}
    //cout << endl;

    return true;
}

void ascend(vector<string>& vec)
{
    if (vec.size() < 2)
        return;

    sort(vec.begin(), vec.end());
}


bool WriteOut(const string& sFile, const vector<string>& vec)
{
    for (unsigned int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
        if (i % 12 == 11)
            cout << endl;
    }
    cout << endl;

    ofstream out_file;
    out_file.open(sFile);
    for (unsigned int i = 0; i < vec.size(); ++i) {
        out_file << vec[i] <<endl;
    }

    out_file.close();

    return true;
}

int main()
{
    string sIn;
    bool bOk = ReadIn("namenum.in", sIn);
    if (!bOk) { return 0; }

    vector<string> vecNames;
    bOk = Calculate(sIn, vecNames);
    if (!bOk) { return 0; }

    vector<string> dict;
    ReadDict("dict.txt", dict);

    vector<string> vecFound;
    for (string s : vecNames)
    {
        for (string s2 : dict)
        {
            if (s == s2)
            {
                vecFound.push_back(s);
                break;
            }
        }
    }

    ascend(vecFound);


    if (vecFound.empty())
    {
        vecFound.push_back("NONE");
    }

    WriteOut("namenum.out", vecFound);

    return 0;
}
