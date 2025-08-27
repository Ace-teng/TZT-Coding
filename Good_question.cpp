#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }

    vector<int> dp(32,0);
    int max_len = 0;

    for(int num : a){
        int current_max = 0;
        for(int bit = 0;bit < 32;bit++){
            if(num & (1 << bit)){
                current_max = max(current_max,dp[bit] + 1);
            }
        }

        for(int bit = 0;bit < 32;bit++){
            if(num & (1 << bit)){
                dp[bit] = max(dp[bit],current_max);
            }
        }
        max_len = max(max_len,current_max);
    }
    cout<< max_len <<endl;
    return 0;

}