/*
ID: jockeys1
TASK: humble
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

#define inf (int)2e9



using namespace std;

int k, n;
long long p[105], h[100005], last[100005];
vector<int> V;


//int Next_Humble_Number(int K) 
//{
//    int Ret = inf; 
//    V.clear();
//    for (int i = 1; i <= K; i++) {
//        if (p[i] * h[last[i]] <= Ret) {
//            if (p[i] * h[last[i]] < Ret) 
//                V.clear();
//            V.push_back(i); 
//            Ret = p[i] * h[last[i]];
//        }
//    }
//
//    for (int i = 0; i < V.size(); i++) 
//        ++last[V[i]];
//
//    return Ret;
//}


int main()
{
    ifstream fin("humble.in");
    ofstream fout("humble.out");

    if (!fin.is_open()) {
        cout << "cannot find the file humble." << endl;
        return 0;
    }

    fin >> k >> n;
    for (int i = 0; i < k; i++)
    {
        fin >> p[i];
    }
    h[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        h[i] = (long long)1e18;
        for (int j = 0; j < k; j++)
        {
            long long h_prev = h[i - 1];
            while (last[j] < i && p[j] * h[last[j]] <= h_prev)
            {
                ++last[j];
            }

            long long val = p[j] * h[last[j]];
            if (val > h_prev)
            {
                h[i] = min(h[i], val);
            }
        }
    }

    fout << h[n] << endl;

    fin.close();
    fout.close();
}




//typedef long long i64;
//typedef unsigned long long ui64;
//
//#define checkbit(n, b) ((n >> b) & 1)
//#define gcd __gcd
//#define bitcount __bultin_popcount
//#define inf (int)2e9
//#define eps 1e-9
//#define pi acos(-1)
//#define mod 1000000007
//#define MAX_K 105
//#define MAX_N 100005
//
//vector<int> V;
//int K, N, i, j, ID[MAX_K], P[MAX_K], H[MAX_N];
//
//void Read(void) {
//    cin >> K >> N;
//    for (i = 1; i <= K; i++) cin >> P[i];
//    memset(ID, 0, sizeof ID); H[0] = 1;
//}



//int main() {
//    freopen("humble.in", "r", stdin);
//    freopen("humble.out", "w", stdout);
//
//    Read();
//    for (j = 1; j <= N; j++) H[j] = Next_Humble_Number();
//    cout << H[N] << endl;
//
//    return 0;
//}

