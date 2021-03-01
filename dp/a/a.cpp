/* 
 * Author: jiaozilang
 * Time: 2021-02-22 09:01:47
**/
#include<bits/stdc++.h>

#define fi first
#define se second
#define INF 0x3f3f3f3f
#define STD std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define SORT(a) sort((a).begin(),(a).end())

const int N = 1e5+10;
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

int a[N];
int f[N];

int main() {
    STD;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    memset(f, 0x3f, sizeof f);

    for (int i = 1; i <= n; i++) {
        if (i == 1) f[i] = 0;
        else {
            f[i] = min(f[i], f[i-1] + abs(a[i] - a[i-1]));
            if (i-2 > 0) f[i] = min(f[i], f[i-2] + abs(a[i] - a[i-2]));
        }
    }
    cout << f[n] << endl;
    return 0;
}
