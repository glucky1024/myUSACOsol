/*
PROG: transform
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

bool ReadIn(const std::string& sFile, vector<vector<bool>>& mtxOne, vector<vector<bool>>& mtxTwo)
{
    fstream in_file;
    in_file.open(sFile, ios::in);
    if (!in_file.is_open())
    {
        cout << "Error: cannot open transform.in file." << endl;
        return false;
    }

    mtxOne.clear();
    mtxTwo.clear();

    int n = 0;
    in_file >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        in_file >> s;
        vector<bool> vec;
        for (int j = 0; j < n; j++) {
            if (s.at(j) == '@')
                vec.push_back(true);
            else 
                vec.push_back(false);
        }
        mtxOne.push_back(vec);
    }

    for (int i = 0; i < n; i++)
    {
        string s;
        in_file >> s;
        vector<bool> vec;
        for (int j = 0; j < n; j++) {
            if (s.at(j) == '@')
                vec.push_back(true);
            else
                vec.push_back(false);
        }
        mtxTwo.push_back(vec);
    }

    return true;
}


bool IsSame(const vector<vector<bool>>& mtxOne, const vector<vector<bool>>& mtxTwo)
{
    bool bDiff = false;
    int row = mtxOne.size();
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < row; j++)
        {
            if (mtxOne[i][j] != mtxTwo[i][j])
            {
                bDiff = true;
                break;
            }
        }

        if (bDiff)
        {
            break;
        }
    }

    return !bDiff;
}

bool rotate90(const vector<vector<bool>>& mtxOne, vector<vector<bool>>& mtxRotate)
{
    mtxRotate = mtxOne;
    int row_col_size = mtxOne.size();

    for (int i = 0; i < row_col_size / 2; i++)
    {
        for (int j = i; j < row_col_size - i - 1; j++)
        {
            int ptr = mtxRotate[i][j];
            mtxRotate[i][j] = mtxRotate[row_col_size - 1 - j][i];
            mtxRotate[row_col_size - 1 - j][i] = mtxRotate[row_col_size - 1 - i][row_col_size - 1 - j];
            mtxRotate[row_col_size - 1 - i][row_col_size - 1 - j] = mtxRotate[j][row_col_size - 1 - i];
            mtxRotate[j][row_col_size - 1 - i] = ptr;
        }
    }

    return true;
}

bool rotate180(const vector<vector<bool>>& mtxOne, vector<vector<bool>>& mtxRotate)
{
    vector<vector<bool>> mtxTemp1;
    rotate90(mtxOne, mtxTemp1);
    rotate90(mtxTemp1, mtxRotate);

    return true;
}

bool rotate270(const vector<vector<bool>>& mtxOne, vector<vector<bool>>& mtxRotate)
{
    vector<vector<bool>> mtxTemp1;
    rotate180(mtxOne, mtxTemp1);
    rotate90(mtxTemp1, mtxRotate);

    return true;
}

void reflect(const vector<vector<bool>>& mtxOne, vector<vector<bool>>& mtxRotate)
{
    mtxRotate = mtxOne;
    int row = mtxOne.size();
    int col = row;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            //int ii = row - 1 - i;
            int jj = col - 1 - j;
            mtxRotate[i][j] = mtxOne[i][jj];
        }
    }

}

int Calculate(const vector<vector<bool>>& mtxOne, const vector<vector<bool>>& mtxTwo)
{
    int row = mtxOne.size();
    if (row != mtxTwo.size())
    {
        assert(0);
        return 7;
    }

    // No.1
    vector<vector<bool>> mtx90;
    rotate90(mtxOne, mtx90);
    if (IsSame(mtxTwo, mtx90))
        return 1;

    vector<vector<bool>> mtx180;
    rotate180(mtxOne, mtx180);
    if (IsSame(mtxTwo, mtx180))
        return 2;

    vector<vector<bool>> mtx270;
    rotate270(mtxOne, mtx270);
    if (IsSame(mtxTwo, mtx270))
        return 3;

    vector<vector<bool>> mtxReflect;
    reflect(mtxOne, mtxReflect);
    if (IsSame(mtxTwo, mtxReflect))
        return 4;

    //
    rotate90(mtxReflect, mtx90);
    if (IsSame(mtxTwo, mtx90))
        return 5;
    rotate90(mtx90, mtx180);
    if (IsSame(mtxTwo, mtx180))
        return 5;
    rotate90(mtx90, mtx270);
    if (IsSame(mtxTwo, mtx270))
        return 5;

    // No.6
    if (IsSame(mtxOne, mtxTwo)) {
        return 6;
    }

    return 7;
}

bool WriteOut(const string& sFile, int iType)
{
    cout << "Type number: " << iType << endl;

    ofstream out_file;
    out_file.open(sFile);
    out_file << iType << endl;

    out_file.close();

    return true;
}

int main()
{
    vector<vector<bool>> mtxOne, mtxTwo;
    bool bOk = ReadIn("transform.in", mtxOne, mtxTwo);
    if (!bOk) { return 0; }

    int iType = Calculate(mtxOne, mtxTwo);

    WriteOut("transform.out", iType);

    return 0;
}
