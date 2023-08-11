#include <bits/stdc++.h>
using namespace std;

int N,M,x,y,x_1,y_1,mn,sm;
int res = 99999999;
vector<pair<int,int>> v; 
vector<pair<int,int>> v_chicken; 
vector<pair<int,int>> v_house;
int arr[55][55];
int chk[20];

void track(int idx,int st){
    if(idx==M){
        sm = 0;
        for(int j=0;j<v_house.size();j++){
            x_1=v_house[j].first; y_1=v_house[j].second;
            mn = 9999999;
            for(int i=0;i<M;i++){
                x=v[i].first; y=v[i].second;         
                int x_len = abs(x_1-x); int y_len = abs(y_1-y);
                mn = min(x_len+y_len,mn);
            }
            sm+=mn;
        }
        res = min(sm,res);
        return ;
    }
    for(int i=st;i<v_chicken.size();i++){
        v.push_back(v_chicken[i]);
        chk[i] = 1;
        track(idx+1,i+1);
        chk[i] = 0;
        v.pop_back();
    }
    return ;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> arr[i][j];
            if (arr[i][j]==2){
                v_chicken.push_back({i,j});
            }
            else if (arr[i][j]==1){
                v_house.push_back({i,j});
            }
        }
    }
    track(0,0);
    cout << res;
}
