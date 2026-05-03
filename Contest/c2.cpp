#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        long long n,m,l;
        cin >> n >> m >> l;

        vector<long long>a(n);
        for(auto &x:a) cin>>x;

        long long lo=0, hi=l, ans=l;

        while(lo<=hi){
            long long x=(lo+hi)/2;

            long long need = (l/(x+1))*m;

            if(need<=n){
                ans=x;
                hi=x-1;
            }else{
                lo=x+1;
            }
        }

        cout<<ans<<"\n";
    }
}