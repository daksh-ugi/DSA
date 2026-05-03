#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        long long c, k;
        cin >> n >> c >> k;
        vector<long long> a(n);
        for (auto& x : a) cin >> x;

        sort(a.begin(), a.end());

        long long tempC = c;
        int lastKillable = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] <= tempC) {
                tempC += a[i];
                lastKillable = i;
            }
        }

        for (int i = 0; i < n; i++) {
            if (a[i] <= c) {
                if (i == lastKillable) c += a[i] + k;
                else                   c += a[i];
            }
        }

        cout << c << "\n";
    }
    return 0;
}