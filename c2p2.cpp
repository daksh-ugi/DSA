#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n, k, p, m;
        cin >> n >> k >> p >> m;

        vector<int> a(n+1);
        for(int i = 1; i <= n; i++) cin >> a[i];

        int wp = a[p]; 
        vector<int> others;
        others.reserve(n-1);
        for(int i = 1; i <= n; i++)
            if(i != p) others.push_back(a[i]);

        sort(others.begin(), others.end());


        long long ans = 0;
        long long energy = m;

        int need = max(0, p - k); 

        
        vector<int> ahead;
        ahead.reserve(p - 1);
        for(int i = 1; i < p; i++) ahead.push_back(a[i]);
        sort(ahead.begin(), ahead.end());

        
        long long setup = 0;
        
        for(int i = 0; i < need; i++) setup += ahead[i];

        if(energy < setup + wp){
            
            cout << 0 << "\n";
            continue;
        }

        
        energy -= setup + wp;
        ans = 1;

        
        int bridge = n - k; 

        if(bridge == 0){
            
            ans += energy / wp;
            cout << ans << "\n";
            continue;
        }

        
        long long cycle_cost = wp;
        for(int i = 0; i < bridge; i++) cycle_cost += others[i];

        
        ans += energy / cycle_cost;

        cout << ans << "\n";
    }

    return 0;
}