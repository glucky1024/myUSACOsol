/*
PROG: ride
LANG: C++
*/

#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>
#include <fstream>


using namespace std;


int getNumberbyLetter(const string& str)
{
    string s = str;
    if (s == "A")
        return 1;
    else if (s == "B")
        return 2;
    else if (s == "C")
        return 3;
    else if (s == "D")
        return 4;
    else if (s == "E")
        return 5;
    else if (s == "F")
        return 6;
    else if (s == "G")
        return 7;
    else if (s == "H")
        return 8;
    else if (s == "I")
        return 9;
    else if (s == "J")
        return 10;
    else if (s == "K")
        return 11;
    else if (s == "L")
        return 12;
    else if (s == "M")
        return 13;
    else if (s == "N")
        return 14;
    else if (s == "O")
        return 15;
    else if (s == "P")
        return 16;
    else if (s == "Q")
        return 17;
    else if (s == "R")
        return 18;
    else if (s == "S")
        return 19;
    else if (s == "T")
        return 20;
    else if (s == "U")
        return 21;
    else if (s == "V")
        return 22;
    else if (s == "W")
        return 23;
    else if (s == "X")
        return 24;
    else if (s == "Y")
        return 25;
    else if (s == "Z")
        return 26;

    assert(0);
    return 0;
}

int calMod(const string& s)
{
    int m = 1;
    for (unsigned int i=0; i <s.size(); i++)
    {
        string s_i = s.substr(i, 1);
        int iVal = getNumberbyLetter(s_i);
        m *= iVal;
    }

    return m%47;
}

int main()
{
    //string s1= "COMETQ";
    //string s2= "HVNGAT";
    fstream in_file;
    in_file.open("ride.in", ios::in);
    if (!in_file.is_open()) {
        cout << "Error: cannot open ride.in file." << endl;
    }
    string s1, s2;
    if (!getline(in_file, s1)) {
        cout << "Error: cannot read the first line from ride.in file." << endl;
    }
    if (!getline(in_file, s2)) {
        cout << "Error: cannot read the second line from ride.in file." << endl;
    }
    cout << "Line 1: " << s1 << "\n";
    cout << "Line 2: " << s2 << "\n";
    in_file.close();

    int N1= calMod(s1);
    int N2= calMod(s2);

    std::string sOut = "STAY";
    if (N1 == N2)
        sOut = "GO";
    cout << sOut << endl;

    ofstream out_file;
    out_file.open ("ride.out");
    out_file << sOut;
    out_file << endl;
    out_file.close();

    return 0;
}
