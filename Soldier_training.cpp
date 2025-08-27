#include <bits/stdc++.h>
#define int long long
using namespace std;
vector <int> a(1000010);
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,maxn=0,s=0;
    cin>>n>>m;
    for(int i=1;i <= n;i++){
        int x,y;
        cin>>x>>y;
        a[y]+=x;
        maxn = max(maxn,y);
    }
    for(int i=maxn;i>=1;i--){
        s+=min(m,a[i]+=a[i+1]);
    }
    cout<<s;
    return 0;

}