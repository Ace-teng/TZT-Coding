#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-8;
const int N = 10;

string str;
int p,pos[N];
bool flag = 0;

bool prime(string s){
    int a = atoi(s.c_str());
    if(a <= 1) return 0;
    for(int i = 2;i * i <= a;i++){
        if(a % i == 0) return 0;
    }
    return 1;
}

void dfs(int t,string s){
    if(flag) return;

    if(t > p){
        if(prime(s)){
            cout<<s<<endl;
            flag = 1;
        }
        return;
    }
    int c = pos[t];
    if(c == 0){
        for(int i = 1;i <= 9;i++){
            s[c] = i + '0';
            dfs(t+1,s);
            s[c] = '*';
        }
    }else{
        for(int i = 0;i <= 9;i++){
            s[c] = i + '0';
            dfs(t+1,s);
            s[c] = '*';
        }
    }

}


int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>str;
        p = 0;
        for(int i = 0;i < str.size();i++){
            if(str[i] == '*'){
                pos[++p] = i;
            }
        }
        flag = 0;
        if(p == 0){
            if(prime(str)) cout<<str<<endl;
            else cout<<-1<<endl;
        }else{
            dfs(1,str);
            if(!flag) cout<<-1<<endl;
        }
    }
    return 0;
}