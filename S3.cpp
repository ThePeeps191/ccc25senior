#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N_MAX = 2e5 + 5;

ll n, m, q, c[N_MAX], p[N_MAX], unused_max = -1, p_sum = 0, used_min = LLONG_MAX;
map<ll, ll> used;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++) used[i] = -1;
    for (int i = 0; i < n; i++) {
        cin >> c[i] >> p[i];
        if (p[i] > used[c[i]]) { // swap the cur color max
            unused_max = max(unused_max, used[c[i]]);
            used[c[i]] = p[i];
        } else unused_max = max(unused_max, p[i]);
    }
    for (int i = 1; i <= m; i++) {
        p_sum += used[i];
        used_min = min(used_min, used[i]);
    }
    if (unused_max > used_min) p_sum += (unused_max - used_min);
    cout << p_sum << endl;
    while (q--) {
        continue;
    }
}
