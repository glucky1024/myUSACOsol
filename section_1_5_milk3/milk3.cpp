/*
ID: jockeys1
TASK: milk3
LANG: C++11 
*/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <tuple>
#include <utility>
using namespace std;
typedef pair<int, int> pii;

#define SIZE 25

bool solutions[SIZE];
bool mark[SIZE][SIZE][SIZE]; // mark visited

// length for each buckets
int al, bl, cl;

// temp vars
int at, bt, ct;

pii move_around(int src, int dst, int dstl) {
    while (src > 0 && dst < dstl) { src--, dst++; }
    return make_pair(src, dst);
}

void solve(int a, int b, int c) {

    // don't visit again
    if (mark[a][b][c] == true)
        return;

    mark[a][b][c] = true; // mark as visited

    // found solution, mark it
    if (a == 0)
        solutions[c] = true;

    // 6 possible choices for depth-first search
    tie(ct, at) = move_around(c, a, al); solve(at, b, ct); // c -> a
    tie(ct, bt) = move_around(c, b, bl); solve(a, bt, ct); // c -> b
    tie(at, bt) = move_around(a, b, bl); solve(at, bt, c); // a -> b
    tie(at, ct) = move_around(a, c, cl); solve(at, b, ct); // a -> c
    tie(bt, at) = move_around(b, a, al); solve(at, bt, c); // b -> a
    tie(bt, ct) = move_around(b, c, cl); solve(a, bt, ct); // b -> c
}

int main() {

#ifndef STDIN
    ofstream cout("milk3.out");
    ifstream cin("milk3.in");
#endif

    cin >> al >> bl >> cl;
    solve(0, 0, cl);

    // print out solutions
    for (int i = 0, c = 1; i < SIZE; i++)
        if (solutions[i] == 1) {
            if (c > 1) cout << ' ';
            cout << i;
            c++;
        }

    cout << endl;
}

///*
//PROG: milk3
//LANG: C++11
//*/
//
//#include <iostream>
//#include <fstream>
//#include <cassert>
//#include <map>
//#include <vector>
//#include <string>
//#include <algorithm>
//#include <cmath>
//#include <unordered_map>
//#include <climits>
//
//using namespace std;
//
//int x, A,B,C = 0;
//int vis[21][21][21];
//vector<int> vecAns;
//bool ReadIn(const std::string& sFile, int& A, int& B, int& C)
//{
//    fstream in_file;
//    in_file.open(sFile, ios::in);
//    if (!in_file.is_open())
//    {
//        cout << "Error: cannot open milk3.in file." << endl;
//        return false;
//    }
//
//    in_file >> A >> B >> C;
//    memset(vis, 0, sizeof(vis));
//
//
//    return true;
//}
//
//void dfs(int a, int b, int c) {
//    if (vis[a][b][c]) return;
//    vis[a][b][c] = 1;
//    if (a == 0)
//    {
//        vecAns.push_back(c);
//        cout << "INSERTED" << endl;
//    }
//
//    //a->b
//    x = min(a, B-b);
//    dfs(a - x, b + x, c);
//    //a->c
//    x = min(a, C-c);
//    dfs(a - x, b, c + x);
//    //b->a
//    x = min(b, A-a);
//    dfs(a + x, b - x, c);
//    //b->c
//    x = min(b, C-c);
//    dfs(a, b - x, c + x);
//    //c->a
//    x = min(c,A- a);
//    dfs(a + x, b, c - x);
//    //c->b
//    x = min(c, B-b);
//    dfs(a, b + x, c - x);
//}
//
//
//
//bool WriteOut(const string& sFile, vector <int>& vecAns)
//{       
//    cout << vecAns[0];
//    for (int i = 0; i < vecAns.size(); i++)
//    {
//        cout << " " << vecAns[i] << endl;
//    }
//    ofstream out_file;
//    out_file.open(sFile);
//    for (int i = 0; i < vecAns.size(); i++)
//    {
//        out_file << vecAns[0];
//        out_file << " " << vecAns[i] << endl;
//
//
//        out_file.close();
//
//        return true;
//    }
//}
//
//
//
//
//int main()
//{
//    int A = 0;
//    int B = 0;
//    int C = 0;
//    bool bOk = ReadIn("milk3.in", A, B, C);
//    if (!bOk) { return 0; }
//
//    dfs(0, 0, C);
//
//    sort(begin(vecAns), end(vecAns));
//
//    WriteOut("milk3.out", vecAns);
//
//    return 0;
//}
