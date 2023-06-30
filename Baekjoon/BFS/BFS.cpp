#include <bits/stdc++.h>

using namespace std;

int arr[105][105];
int chk[105][105];
int N , M;
int dx [] = {0,0,1,-1};
int dy [] = {1,-1,0,0};
int sx,sy,ex,ey,x,y; //시작,끝,현재 좌표 받기.

int main() {
    cin >> N >> M;
    cin >> sx >> sy;
    cin >> ex >> ey;

    for (int i = 0 ; i<N ; i++){
        for (int j = 0 ; j<M ; j++)
            cin >> arr[i][j];
    }
    queue<pair<int,int>> q; //2차원 좌표 이므로, pair..
    chk[sx][sy]=1; //일단 원점에 체크하고 시작.
    q.push({sx,sy}); 
    while (q.size()){
    tie(x,y) = q.front(); q.pop(); // 처음좌표 받고, pop.
    for(int i=0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(ny<0||nx<0||ny>=N||nx>=N||arr[nx][ny]==0) continue;
        if(chk[nx][ny])continue;
        chk[nx][ny] = chk[x][y]+1;
        q.push({nx,ny});
    }
    }
    //최단거리
    cout << chk[ex][ey];
    return 0 ;
}