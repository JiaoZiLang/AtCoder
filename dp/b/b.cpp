/* 
 * Author: jiaozilang
 * Time: 2021-02-22 15:29:42
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

int n, k;
int a[N], f[N];

int main() {
    STD;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    memset(f, 0x3f, sizeof f);
    for (int i = 1; i <= n; i++) {
        if (i == 1) f[i] = 0;
        else {
            for (int j = 1; j <= k && i - j >= 1; j++) {
                f[i] = min(f[i], f[i-j] + abs(a[i] - a[i-j]));
            }
        }
    }
    cout << f[n] << endl;
    return 0;
}
