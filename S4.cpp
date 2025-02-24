#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, pii> state;
const ll INF = LLONG_MAX;
const int N_MAX = 2e5 + 5;

int n, m;
ll ans = INF;
vector<pii> adj[N_MAX];
priority_queue<state, vector<state>, greater<state>> pq;
map<pii, ll> dist;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    pq.push({0, {1, 0}});
    dist[{1, 0}] = 0;
    while (!pq.empty()) {
        state cur = pq.top();
        ll cost = cur.first;
        pii u_state = pq.top().second;
        int u = u_state.first, c = u_state.second;
        pq.pop();
        if (u == n) {
            ans = min(ans, cost);
            continue;
        }
        if (cost > dist[{u, c}]) continue;
        for (auto xx : adj[u]) {
            auto v = xx.first;
            auto t = xx.second;
            ll new_cost = cost + abs(t - c);
            if (!dist.count({v, t}) || new_cost < dist[{v, t}]) {
                dist[{v, t}] = new_cost;
                pq.push({new_cost, {v, t}});
            }
        }
    }
    cout << ans << endl;
}
