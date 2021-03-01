/* 
 * Author: jiaozilang
 * Time: 2021-02-22 17:14:08
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

int n;
int matrix[N][3];
LL f[N][3];

int main() {
    STD;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 2; j++) {
            cin >> matrix[i][j];
        }
    }
    memset(f, 0, sizeof f);
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            f[i][0] = matrix[i][0];
            f[i][1] = matrix[i][1];
            f[i][2] = matrix[i][2];
        } else {
            f[i][0] = max(f[i-1][1], f[i-1][2]) + matrix[i][0];
            f[i][1] = max(f[i-1][0], f[i-1][2]) + matrix[i][1];
            f[i][2] = max(f[i-1][0], f[i-1][1]) + matrix[i][2];
        }
    }
    cout << max(f[n][0], max(f[n][1], f[n][2])) << endl;
    return 0;
}
