/* 
 * Author: jiaozilang
 * Time: 2021-02-26 16:59:03
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

int n, w;
LL f[N];

int main() {
    STD;
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        int a;
        LL b;
        cin >> a >> b;
        for (int j = w; j >= a; j--) {
            f[j] = max(f[j], f[j-a] + b);
        }
    }
    cout << f[w] << endl;
    return 0;
}
