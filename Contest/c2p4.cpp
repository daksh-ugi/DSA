#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<string> s(n);
        for(int i = 0; i < n; i++) cin >> s[i];

        bool bad = false;
        for(int i = 0; i < n; i++)
            if(s[i][i] != '1'){ bad = true; break; }

        vector<pair<int,int>> edges;
        vector<vector<int>> adj(n), dadj(n);

        for(int u = 0; u < n && !bad; u++){
            for(int v = 0; v < n && !bad; v++){
                if(u == v || s[u][v] != '1') continue;
                if(s[v][u] == '1'){ bad = true; break; }

                bool direct = true;
                for(int w = 0; w < n; w++){
                    if(w != u && w != v && s[u][w] == '1' && s[w][v] == '1'){
                        direct = false;
                        break;
                    }
                }
                if(direct){
                    edges.push_back({u, v});
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                    dadj[u].push_back(v);
                }
            }
        }

        if(!bad) bad = ((int)edges.size() != n - 1);

        if(!bad){
            vector<bool> visited(n, false);
            queue<int> q;
            q.push(0); visited[0] = true;
            int cnt = 1;
            while(!q.empty()){
                int u = q.front(); q.pop();
                for(int v : adj[u])
                    if(!visited[v]){ visited[v]=true; cnt++; q.push(v); }
            }
            if(cnt != n) bad = true;
        }

        for(int src = 0; src < n && !bad; src++){
            vector<bool> reach(n, false);
            queue<int> q;
            q.push(src); reach[src] = true;
            while(!q.empty()){
                int u = q.front(); q.pop();
                for(int v : dadj[u])
                    if(!reach[v]){ reach[v]=true; q.push(v); }
            }
            for(int j = 0; j < n; j++)
                if(reach[j] != (s[src][j] == '1')){ bad = true; break; }
        }

        if(bad){ cout << "No\n"; continue; }

        cout << "Yes\n";
        for(auto [u,v] : edges) cout << u+1 << " " << v+1 << "\n";
    }

    return 0;
}