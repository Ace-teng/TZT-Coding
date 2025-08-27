#include <bits/stdc++.h>
using namespace std;
vector <int> p[100100];
int n,m,f,s,ans,pd[100100];

void dfs(int x)
{
    for(int y=0;y<p[x].size();y++)
        if(pd[p[x][y]]==0)
            pd[p[x][y]]=1,dfs(p[x][y]);
}

int main()
{
    cin>>n>>m;
    for(int x=1;x<=m;x++)
        cin>>f>>s,p[f].push_back(s),p[s].push_back(f);

    for(int x=1;x<=n;x++)
        if(pd[x]==0)
            ans++,pd[x]=1,dfs(x);


    cout<<ans;
    return 0;
    
}