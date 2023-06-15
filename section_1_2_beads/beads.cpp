/*
PROG: beads
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

bool ReadIn(const std::string& sFile, int& nBeads, string& sNecklace)
{
    fstream in_file;
    in_file.open(sFile, ios::in);
    if (!in_file.is_open())
    {
        cout << "Error: cannot open friday.in file." << endl;
        return false;
    }

    in_file >> nBeads;
    in_file >> sNecklace;

    return true;
}


int CalNumberOfCount(int nBeads, const string& sNecklace, int iStart)
{
    if (sNecklace.size() != nBeads) {
        cout << "Error: beads number does not match." << endl;
        return -1;
    }

    if (iStart >= nBeads) {
        cout << "Error: start index is larger than the number of beads." << endl;
        return -1;
    }

    string s1 = sNecklace.substr(iStart, 1);

    int count = 1;
    bool bSwitched = false;
    bool bLooped = false;
    int index = iStart;
    while (true)
    {
        index++;
        if (index == nBeads) {
            index = 0;
        }

        if (index == iStart)
            break;

        string s2 = sNecklace.substr(index, 1);
        if (s1 == "w") {
            s1 = s2;
        }
        if (s2 == "w" || s2 == s1) {

        }       
        else if (bSwitched)
        {
            break;
        }
        else
        {
            s1 = s2;
            bSwitched = true;
        }
        count++;
    }

    return count;
}

int Calculate(int nBeads, const string& sNecklace)
{
    int maxN = 0;
    for (int i = 0; i < nBeads; i++)
    {
        int sum = CalNumberOfCount(nBeads, sNecklace, i);
        cout << "Start at bead " << i << ", get " << sum << endl;
        maxN = sum > maxN ? sum : maxN;
    }

    return maxN;
}

bool WriteOut(const string& sFile, int maxN) 
{
    cout << maxN << endl;

    //
    ofstream out_file;
    out_file.open(sFile);
    out_file << maxN << endl;


    out_file.close();

    return true;
}

int main()
{
    int nBeads = 0;
    string sNecklace;
    bool bOk = ReadIn("beads.in", nBeads, sNecklace);
    if (!bOk) { return 0; }

    int maxN = Calculate(nBeads, sNecklace);
    if (maxN < 0) { return 0; }

    WriteOut("beads.out", maxN);

    return 0;
}
