/*
 * Author: jiaozilang
 * Time: 2021-03-22 11:33:46
**/
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>

#define fi first
#define se second
#define INF 0x3f3f3f3f
#define STD std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define FOR(i,a,b) for (int i(a); i < (b); i++)
#define REP(x, l, u) for(int x = l; x <= u; x++)
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define SORT(a) sort((a).begin(),(a).end())
#define mp(a, b) make_pair(a, b)

const int N = 1e5+10;
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

int n, m;
vector<string> a;

int main() {
    STD;
    cin >> n >> m;
    REP(i, 1, n) {
        string s;
        cin >> s;
        s = ' ' + s;
        a.pb(s);
    }

    int res = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = 1; j < m; j++) {
            int cnt = (a[i][j] == '#') + (a[i+1][j] == '#') + (a[i][j+1] == '#') + (a[i+1][j+1] == '#');
            if (cnt == 1 || cnt == 3) res++;
        }
    }
    cout << res;
    return 0;
}
