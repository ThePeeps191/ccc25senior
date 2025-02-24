#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<char, ll> pcl;

string s;
ll idx, total_len;
vector<pcl> ops;

int main() {
    string s;
    ll idx;
    cin >> s >> idx;
    for (int i = 0; i < s.length();) {
        char c = s[i++];
        ll cnt = 0;
        while (i < s.length() && isdigit(s[i])) {
            cnt = cnt * 10 + (s[i] - '0');
            i++;
        }
        ops.push_back({c, cnt});
    }
    ll total_len = 0;
    for (auto op : ops) total_len += op.second;
    ll pos = idx % total_len;
    for (auto op : ops) {
        if (pos < op.second) {
            cout << op.first << endl;
            return 0;
        }
        pos -= op.second;
    }
}
