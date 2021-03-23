/*
 * Author: jiaozilang
 * Time: 2021-03-22 17:04:20
**/
// #pragma GCC optimize("Ofast")
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

const int N = 2e3+10;
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

int e[N], w[N], ne[N], h[N], idx, st[N], dist[N][N], g[N][N], dis[N];
int n, m;

struct Edge {
    int u, v, c;
} edge[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dij(int x) {
    memset(dis, 0x3f, sizeof dis);
    memset(st, 0, sizeof st);
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, x});
    dis[x] = 0;
    while(q.size()) {
        auto t = q.top();
        q.pop();

        int d = t.fi, ver = t.se;
        if (st[ver]) continue;
        st[ver] = 1;

        for (auto i = h[ver]; ~i; i = ne[i]) {
            int j = e[i];
            if (dis[j] > d + w[i])  {
                dis[j] = d + w[i];
                q.push({dis[j], j});
            }
        }
    }
}

void spfa(int x) {
    memset(dis, 0x3f, sizeof dis);
    memset(st, 0, sizeof st);
    queue<int> q;
    st[x] = 1;
    q.push(x);
    dis[x] = 0;

    while(q.size()) {
        auto t = q.front();
        q.pop();
        st[t] = 0;

        for (auto i = h[t]; ~i; i = ne[i]) {
            auto j = e[i];
            if (dis[j] > dis[t] + w[i]) {
                dis[j] = dis[t] + w[i];
                if (!st[j]) {
                    q.push(j);
                    st[j] = 1;
                }
            }
        }
    }
}

int main() {
    STD;
    cin >> n >> m;
    memset(h, -1, sizeof h);
    memset(dist, 0x3f, sizeof dist);
    memset(g, 0x3f, sizeof g);
    REP(i, 1, m) {
        cin >> edge[i].u >> edge[i].v >> edge[i].c;
        g[edge[i].u][edge[i].v] = min(g[edge[i].u][edge[i].v], edge[i].c);
    }
    REP(i, 1, m) edge[i].c = g[edge[i].u][edge[i].v];
    REP(i, 1, m) add(edge[i].u, edge[i].v, edge[i].c);

    REP(i, 1, n) {
        spfa(i);
        REP(j, 1, n) dist[i][j] = dis[j];
    }

    REP(i, 1, n) {
        int res = 1e9 + 10;
        REP(j, 1, n) {
            if (i == j) {
                res = min(res, g[i][j]);
            } else {
                res = min(res, dist[i][j] + dist[j][i]);
            }
        }
        if (res == 1e9+10) cout<< "-1\n";
        else cout << res << "\n";
    }

    return 0;
}
