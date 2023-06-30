#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int N,M,x,y,nx,ny,cnt;
int arr[105][105];
bool chk[105][105];

void dfs(int x, int y){
    chk[x][y] = 1;
    for(int i=0;i<4;i++){
        nx = x + dx[i];
        ny = y + dy[i];
        if(nx<0||ny<0||nx>=N||ny>=N)continue;
        if(arr[nx][ny]==1&& !chk[nx][ny]){
            dfs(nx,ny);
        }
    }
    return;
};

int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j]==1 && !chk[i][j]){
                dfs(i,j); 
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}
            