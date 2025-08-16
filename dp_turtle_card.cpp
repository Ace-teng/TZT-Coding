#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    vector<int> scores(n);
    for(int i =0;i < n;i++){
        cin>>scores[i];
    }

    vector<int> cards(5,0);
    for(int i = 0;i < m;i++){
        int num;
        cin>>num;
        cards[num]++;
    }

    int dp[41][41][41][41];
    memset(dp, 0, sizeof(dp)); 
    dp[0][0][0][0] = scores[0];

    for(int a = 0;a <= cards[1];a++){
        for(int b = 0;b <= cards[2];b++){
            for(int c = 0;c <= cards[3];c++){
                for(int d = 0;d <= cards[4];d++){
                    if(a == 0 && b == 0 && c == 0 && d == 0) continue;

                    int pos = 1 + a*1 + b*2 +c*3 +d*4;
                    if(pos > n) continue;

                    int max_score = 0;

                    if(a>0) max_score = max(max_score,dp[a-1][b][c][d] + scores[pos-1]);
                    if(b>0) max_score = max(max_score,dp[a][b-1][c][d] + scores[pos-1]);
                    if(c>0) max_score = max(max_score,dp[a][b][c-1][d] + scores[pos-1]);
                    if(d>0) max_score = max(max_score,dp[a][b][c][d-1] + scores[pos-1]);

                    dp[a][b][c][d] = max_score;
                }
            }
        }
    }

    cout<<dp[cards[1]][cards[2]][cards[3]][cards[4]]<<endl;
    return 0;

}