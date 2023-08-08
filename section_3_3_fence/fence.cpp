/*
ID: jockeys1
TASK: fence
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
#include <climits>
#include <numeric>
#include <set>
#include <bitset>
#include <utility>

using namespace std;

int main()
{
    ifstream fin("fence.in");
    ofstream fout("fence.out");

    if (!fin.is_open()) {
        cout << "cannot find the file fence." << endl;
        return 0;
    }


    fin.close();
    fout.close();
}
