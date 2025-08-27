#include <bits/stdc++.h>
using namespace std;

vector<vector<uint64_t>> build(const vector<vector<int>>& ma){
    if(ma.empty()) return{};

    int m = ma.size();
    int n = ma[0].size();

    vector<vector<uint64_t>> prefix(m+1,vector<uint64_t>(n+1,0));

    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= n;j++){
            prefix[i][j]=prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] +ma[i-1][j-1];

        }
    }
    return prefix;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int t;
    cin>>t;
    
    while(t--){
        int m,n,q;
        cin>>m>>n>>q;
        vector<vector<int>> ma(m,vector<int>(n));
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                cin>>ma[i][j];
            }
        }

        auto prefix = build(ma);
        
        uint64_t xor_sum = 0;
        

        while(q--){
            int u,v,x,y;
            cin>>u>>v>>x>>y;

            uint64_t sum = prefix[x][y] - prefix[u-1][y] - prefix[x][v-1] + prefix[u-1][v-1];

            xor_sum ^= sum;


        }

        cout<<xor_sum<<endl;




    }
    return 0;
}