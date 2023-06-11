#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int m = (n * n + 1) / 2;
    vector<int> v;
    int g = (m + 1) / 2;

    for (int i = 1; i <= g; i++) {
        v.push_back(2 * i - 1);
    }

    for (int i = 1; i <= g; i++) {
        v.push_back(2 * i);
    }

    for (int i = 0; i < n*n; i++) {
        cout<<v[i]<<" ";
    }
}

signed main()
{
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
