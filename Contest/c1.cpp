#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        
        // Find all blocks of consecutive 1's
        vector<pair<int,int>> blocks; // [start, end] 0-indexed
        int i = 0;
        while (i < n) {
            if (s[i] == '1') {
                int j = i;
                while (j < n && s[j] == '1') j++;
                blocks.push_back({i, j-1});
                i = j;
            } else {
                i++;
            }
        }
        
        if (blocks.empty()) {
            cout << "0 0\n";
            continue;
        }
        
        
        
        int mn = 0, mx = 0;
        int comp_start = blocks[0].first;
        int comp_end = blocks[0].second;
        
        for (int k = 1; k < (int)blocks.size(); k++) {
            int gap = blocks[k].first - blocks[k-1].second - 1;
            if (gap == 1) {
                comp_end = blocks[k].second;
            } else {
                int span = comp_end - comp_start + 1;
                mn += span / 2 + 1;
                mx += span;
                comp_start = blocks[k].first;
                comp_end = blocks[k].second;
            }
        }
        int span = comp_end - comp_start + 1;
        mn += span / 2 + 1;
        mx += span;
        
        cout << mn << " " << mx << "\n";
    }
    
    return 0;
}