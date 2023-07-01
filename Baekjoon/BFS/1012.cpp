#include <bits/stdc++.h>
using namespace std;

int nx,ny,cnt;
int T,N,M,K;
int arr[55][55];
int chk[55][55];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void DFS(int x,int y){
    for(int i=0;i<4;i++){
        nx = x+dx[i];
        ny = y+dy[i];
        if(nx>=N||ny>=M||nx<0||ny<0||arr[nx][ny]==0)continue;
        if(chk[nx][ny]==1)continue;
        chk[nx][ny]=1;
        DFS(nx,ny);
    }
    return;
}

int main(){    
        cin >> T;
    while(T--){ // Testcase있을 때, 편하게 반복.
        cin >> N >> M;
        cin >> K;
        for(int i=0;i<K;i++){
            int X,Y;
            cin >> X >> Y;
            arr[X][Y]=1;
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(chk[i][j]==1)continue;
                if(arr[i][j]==0)continue;
                chk[i][j]=1;
                DFS(i,j);  
                cnt+=1;
            }
        }
        cout << cnt<<"\n"; // 줄 바꾸기
        cnt =0; // 초기화 함.
        memset(arr,0,sizeof(arr)); // Testcase있을 때 ,memset으로 초기화
        memset(chk,0,sizeof(chk));
    }
}