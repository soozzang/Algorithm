#include <bits/stdc++.h>
using namespace std;

int arr2[305][305];
int arr[305][305];
int chk[305][305];
int N,M,K;
int nx,ny,cnt,cnt2,T,flag;
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};

void DFS(int x,int y){
    chk[x][y]=1;
    for(int dir=0;dir<4;dir++){
        nx=x+dx[dir];
        ny=y+dy[dir];
        if(nx<0||ny<0||nx>=N||ny>=M)continue;
        if(chk[nx][ny]==1||arr[nx][ny]==0)continue;
        DFS(nx,ny);
    }
    return;
}

int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>> arr[i][j];
        }
    }
    while(true){
        cnt2=0;
        flag=0;
        memset(chk,0,sizeof(chk));
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cnt=0;
                if(arr[i][j]==0||chk[i][j]==1)continue;
                for(int dir=0;dir<4;dir++){
                    cnt += (arr[i+dx[dir]][j+dy[dir]] == 0);
                }
                arr2[i][j] =cnt;
            }
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                arr[i][j]-=arr2[i][j];
                if(arr[i][j]<0)arr[i][j]=0;
                flag += (arr[i][j]==0);
            }
        }
        if(flag==N*M){
            cout << 0;
            break;
        }
        T+=1;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(arr[i][j]==0||chk[i][j]==1)continue;
                DFS(i,j);
                cnt2+=1;
            }
        }
        if(cnt2>=2){
            cout << T;
            break;
        }
    }
}