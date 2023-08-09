#include <bits/stdc++.h>
using namespace std;

int N,M;
int nx,ny,x,y;
int arr[105][105];
int chk[105][105];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        string s;
        cin>>s;
        for(int j=0;j<M;j++){
            arr[i][j] = s[j] - '0';
        }
    }   
    
    //BFS
    queue<pair<int,int>>q;
    chk[0][0]=1;
    q.push({0,0});
    while(q.size()){
        tie(x,y)=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=N||ny>=M||nx<0||ny<0||arr[nx][ny]==0)continue;
            if(chk[nx][ny]!=0)continue;
            chk[nx][ny]=chk[x][y]+1;
            q.push({nx,ny});
        }
    }
    cout << chk[N-1][M-1];
    return 0;
}