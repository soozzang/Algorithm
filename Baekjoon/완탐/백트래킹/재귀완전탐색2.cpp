#include <bits/stdc++.h>
using namespace std;
int N;
int M;
int x;
int mx;
vector<int> v;



int go(int idx, int sum){
    x=(sum+v[idx])%11;
    mx = max(x,mx);
    if (mx == 10) return 0; //없어도 됨
    if(idx==N){
        return 0;
    }
    go(idx+1,sum);
    go(idx+1,sum+v[idx]);
    return mx;
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> M;
        v.push_back(M);
    }
    go(0,0);
    cout << mx;
}