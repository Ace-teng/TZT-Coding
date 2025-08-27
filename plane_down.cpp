#include <iostream>
#include <vector>
using namespace std;

bool canLandALL(vector<vector<int>> & planes,vector<bool> & used,int lastEnd ,int count){
    if(count == planes.size()){
        return true;
    }
    for(int i = 0;i < planes.size();i++){
        if(!used[i]){
            int T = planes[i][0];
            int D = planes[i][1];
            int L = planes[i][2];
            int start = max(T,lastEnd);
            if(start > T + D){
                continue;
            }
            used[i] = true;
            if(canLandALL(planes,used,start + L,count + 1)){
                return true;
            }
            used[i] = false;
        }
    }
    return false;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        vector<vector<int>> planes(N,vector<int>(3));
        for(int i = 0;i < N;i++){
            cin>>planes[i][0]>>planes[i][1]>>planes[i][2];

        }
        vector<bool> used(N,false);
        if(canLandALL(planes,used,0,0)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}