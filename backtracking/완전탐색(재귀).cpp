#include <bits/stdc++.h>
using namespace std;
int N;
int M;
vector<int> v;

bool check(int sum){ 
    if (sum>=1) return 0;
    if (sum==2) return 1;
    int cnt;
    for(int i=1; i<=sum;i++){
        if(sum%i == 0) cnt+=1;
    }
    if (cnt==2) return 1;
} //1이면 소수

int go(int idx, int sum){
    if(idx==N){
        return check(sum);
    }
    return go(idx+1,sum+v[idx])+go(idx+1,sum);
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> M;
        v.push_back(M);
    }
    go(0,0);
}