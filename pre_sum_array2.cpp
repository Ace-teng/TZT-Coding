#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

using namespace std;
const ull N = 1005;

ull T;

ull s[N][N];
ull n,m,q,p;
ull u,v,x,y;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    cin>>T;
    while(T--){
        cin>>n>>m>>q;
        for(ull i=1;i <=n;i++){
            for(ull j = 1;j <= m;j++){
                cin>>p;
                s[i][j]=p+s[i][j-1] + s[i-1][j] -s[i-1][j-1];
            }
        }
        ull ans = 0;
        for(ull i = 1;i <= q;i++){
            cin>>u>>v>>x>>y;
            ans = ans^(s[x][y] + s[u-1][v-1] - s[u-1][y] - s[x][v-1]);

        }
        cout<<ans<<endl;

        
    }
    return 0;
}