#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        unordered_map<int,int> freq;
        freq.reserve(1 << 14);
        freq.max_load_factor(0.25);

        for (int i = 0; i < n * n; i++) {
            int x;
            cin >> x;
            freq[x]++;
        }
        int maxAllowed = n * (n - 1);

        bool possible = true;
        for (auto& [color, cnt] : freq) {
            if (cnt > maxAllowed) {
                possible = false;
                break;
            }
        }

        cout << (possible ? "YES" : "NO") << "\n";
    }

    return 0;
}