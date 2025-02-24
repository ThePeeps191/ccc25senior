#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const ll N_MAX = 2e5 + 5;

ll n, m;
vector<pll> adj[N_MAX];
queue<pair<ll, pll>> q; // -> {v, {cur_temp, cur_cost}}
bool vis[N_MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fill(vis, vis + N_MAX, false);
    cin >> n >> m;
    for (ll i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    q.push({1LL, {0LL, 0LL}});
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        ll u = cur.first, cur_temp = cur.second.first, cur_cost = cur.second.second;
        if (vis[u]) continue;
        vis[u] = true;
        if (u == n) {
            cout << cur_cost << endl;
            return 0;
        }
        for (auto edge : adj[u]) {
            ll v = edge.first, needed_temp = edge.second;
            if (vis[v]) continue;
            q.push({v, {needed_temp, cur_cost + abs(cur_temp - needed_temp)}});
        }
    }
}
