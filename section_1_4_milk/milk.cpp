/*
PROG: milk
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

bool ReadIn(const std::string& sFile, int& milkWant, map<int, int>& mapPrice2Stock)
{
    fstream in_file;
    in_file.open(sFile, ios::in);
    if (!in_file.is_open())
    {
        cout << "Error: cannot open milk.in file." << endl;
        return false;
    }

    int nFarmers = 0;
    in_file >> milkWant >> nFarmers;

    for (int i = 0; i < nFarmers; i++)
    {
        int price = 0, stock = 0;
        in_file >> price >> stock;
        map <int, int>::iterator it = mapPrice2Stock.find(price);
        if (it != mapPrice2Stock.end()) {
            it->second = it->second + stock;
        }
        else {
            mapPrice2Stock[price] = stock;
        }
    }

    return true;
}

int Calculate(int milkWant, const map<int, int>& mapPrice2Stock)
{
    int minTotal = 0;

    int milkGot = 0;
    for (const auto& p2s : mapPrice2Stock) {
        int price = p2s.first;
        int stock = p2s.second;

        int milkRemain = milkWant - milkGot;
        if (milkRemain <= 0)
            break;

        if (stock > milkRemain) {
            int cost = milkRemain* price;
            minTotal += cost;
            break;
        }

        milkGot += stock;
        minTotal += price * stock;
    }

    return minTotal;
}

bool WriteOut(const string& sFile, int minTotal)
{
    cout << minTotal << endl;

    ofstream out_file;
    out_file.open(sFile);
    out_file << minTotal << endl;

    out_file.close();

    return true;
}

int main()
{
    int milkWant = 0;
    map<int, int> mapPrice2Stock;
    bool bOk = ReadIn("milk.in", milkWant, mapPrice2Stock);
    if (!bOk) { return 0; }

    int minTotal = Calculate(milkWant, mapPrice2Stock);

    WriteOut("milk.out", minTotal);

    return 0;
}
