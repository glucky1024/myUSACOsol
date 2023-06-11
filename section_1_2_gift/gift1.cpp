/*
PROG: gift1
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

class Person
{
public:
    Person(const std::string& s, int in, vector<string>& vecNames)
        : _name(s)
        , _moneyIn(in)
    {
        _recievers = vecNames;
        _moneyOwn = 0;
    }

    unsigned int getNumberOfRecievers()
    {
        return _recievers.size();
    }
    void addMoney(int usd)
    {
        _moneyOwn+= usd;
    }
    int getMoneyIn()
    {
        return _moneyIn;
    }
    int getMoneyOwned()
    {
        return _moneyOwn;
    }
    const vector<string>& getNames()
    {
        return _recievers;
    }


private:
    string _name;
    int _moneyIn;
    vector<string> _recievers;
    int _moneyOwn;
};

bool ReadIn(const string& sFile, vector<string>& vecPersons, unordered_map<string, Person*>& mapPersons)
{
    vecPersons.clear();

    fstream in_file;
    in_file.open(sFile, ios::in);
    if (!in_file.is_open())
    {
        cout << "Error: cannot open gift1.in file." << endl;
        return false;
    }

    string s1;
    if (!getline(in_file, s1))
    {
        cout << "Error: cannot read the first line from gift1.in file." << endl;
        return false;
    }

    int NP = stoi(s1);
    for (int i = 0; i < NP; i++)
    {
        string sName;
        if (!getline(in_file, sName))
        {
            cout << "Error: cannot read the names from gift1.in file." << endl;
            return false;
        }
        vecPersons.push_back(sName);
    }

    while (true)
    {
        string sName;
        in_file >> sName;

        unsigned int usd =0, n = 0;
        in_file >> usd >> n;

        vector <string> vecNames;
        for (unsigned int i=0; i < n; i++)
        {
            string s2;
            in_file >> s2;
            vecNames.push_back(s2);
        }
        mapPersons[sName] = new Person(sName, usd, vecNames);

        if(in_file.eof() )
            break;
    }

    in_file.close();
    return true;
}


void calcUsd(int moneyIn, unsigned int n, int& moneyAve, int& moneyBack)
{
    moneyAve = 0;
    moneyBack = 0;
    if (n == 0)
    {
        assert(0);
        return;
    }

    moneyAve = floor(moneyIn/n);
    moneyBack  = moneyIn % n - moneyIn;
}

void WriteOut(const string& sFile, const vector<string>& vecPersons, unordered_map<string, Person*>& mapPersons)
{
    ofstream out_file;
    out_file.open (sFile);

    for(string s: vecPersons)
    {
        unordered_map<string, Person*>::iterator it = mapPersons.find(s);
        if(it != mapPersons.end())
        {
            string sName = it->first;
            int usd = it->second->getMoneyOwned();
            out_file << sName << " " << usd << endl;
        }
    }
    //out_file << endl;

    out_file.close();
}


int main()
{
    vector<string> vecPersons;
    unordered_map<string, Person*> mapPersons;

    if (!ReadIn("gift1.in", vecPersons, mapPersons))
        return 1;

    for(const auto & p: mapPersons)
    {
        Person* pP= p.second;
        if (!pP)
            return 1;
        unsigned int n = pP->getNumberOfRecievers();
        if (n==0)
        {
            pP->addMoney(pP->getMoneyIn());
            continue;
        }

        int moneyIn = pP->getMoneyIn();
        int moneyAve, moneyBack;
        calcUsd(moneyIn, n, moneyAve, moneyBack);

        const vector<string>& vecNames = pP->getNames();
        for( string s: vecNames)
        {
            unordered_map<string, Person*>::iterator it = mapPersons.find(s);
            if(it != mapPersons.end())
            {
                it->second->addMoney(moneyAve);
            }
        }
        pP->addMoney(moneyBack);
    }

    WriteOut("gift1.out", vecPersons, mapPersons);


    // output
    for(const auto & p: mapPersons)
    {
        delete p.second;
    }
    mapPersons.clear();

    return 0;
}
