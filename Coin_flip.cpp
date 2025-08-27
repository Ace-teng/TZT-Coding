#include <bits/stdc++.h>
using namespace std;
const int N =1e3 + 5;
int dp[N][2][2],n,m;
int a[N][N];
int getval(int w,int x,int y,int z){
    int res = 0;
    for(int i = 1;i <= m;i++){
        int cnt = 0;
        if(i > 1&&a[w][i] == a[w][i-1]) cnt++;
        if(i < m&&a[w][i] == a[w][i+1]) cnt++;
        if(w > 1){
            if(!(y == x^a[w][i] == a[w-1][i])) cnt++;
        }
        if(w <= n-1){
            if(!(y == z^a[w][i] == a[w+1][i])) cnt++;
        }
        res += cnt*cnt;
    }
    return res;
}

int main(){
    cin>>n>>m;
    for(int i = 1,s1;i <= n;i++){
        string s;
        cin>>s;
        s1 = s.size();
        for(int j = 1;j <= s1;j++){
            a[i][j] = s[j-1] - '0';
        }
    }
    
    dp[2][0][0] = getval(1,0,0,0);
    dp[2][0][1] = getval(1,0,1,0);
    dp[2][1][0] = getval(1,0,0,1);
    dp[2][1][1] = getval(1,0,1,1);
    for(int i = 3;i <= n+1;i++){
        dp[i][0][0] = max(dp[i-1][0][0] + getval(i-1,0,0,0),dp[i-1][0][1] + getval(i-1,1,0,0));
        dp[i][0][1] = max(dp[i-1][1][0] + getval(i-1,0,1,0),dp[i-1][1][1] + getval(i-1,1,1,0));
        dp[i][1][0] = max(dp[i-1][0][0] + getval(i-1,0,0,1),dp[i-1][0][1] + getval(i-1,1,0,1));
        dp[i][1][1] = max(dp[i-1][1][0] + getval(i-1,0,1,1),dp[i-1][1][1] + getval(i-1,1,1,1));
    }
    int ans = 0;
    ans = max(dp[n+1][0][0],max(dp[n+1][0][1],max(dp[n+1][1][0],dp[n+1][1][1])));
    cout<<ans<<endl;
    return 0;

}