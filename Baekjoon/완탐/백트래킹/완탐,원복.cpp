#include <bits/stdc++.h>
using namespace std;

const int n = 3;
int arr[3][3] = {
    {10,20,21},
    {70.90,12},
    {80,110,120},
};
int visited[3][3];
vector<int> v;
int dx[4] = {0, 1 , -1 ,0};
int dy[4] = {-1, 0 , 0 ,1};

void go(int x,int y){
    if(x ==n-1 && y == n-1){
        return;
    }
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<0 || ny<0 || ny>=n || nx>=n)continue;
        if(visited[nx][ny]) continue;
        visited[nx][ny] = 1;
        v.push_back(arr[nx][ny]);
        go(nx,ny);
        visited[nx][ny] = 0;
        v.pop_back();
    }
}

int main(){
    visited[0][0] = 1;
    v.push_back(arr[0][0]);
    go(0,0);
}