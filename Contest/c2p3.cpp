#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(10);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> c(n), p(n);
        for(int i = 0; i < n; i++) cin >> c[i] >> p[i];

        double f = 0.0;

        for(int i = n - 1; i >= 0; i--){
            double mult = 1.0 - p[i] / 100.0;
            double complete_val = (double)c[i] + mult * f;
            f = max(f, complete_val);
        }

        cout << f << "\n";
    }

    return 0;
}