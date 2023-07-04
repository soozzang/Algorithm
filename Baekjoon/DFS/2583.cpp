#include <bits/stdc++.h>
using namespace std;

int arr[105][105];
int chk[105][105];
int sz[105];
int N,M,K;
int g;
int nx,ny,cnt;
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};

void DFS(int x,int y){
    sz[g]+=1;
    for(int dir=0;dir<4;dir++){
        nx= x+dx[dir];
        ny= y+dy[dir];
        if(nx<0||ny<0||nx>=M||ny>=N||arr[nx][ny]==1)continue;
        if(chk[nx][ny]==1)continue;
        chk[nx][ny]=1;
        DFS(nx,ny);
    }    
    return;
}

int main(){
    cin >> M >> N >> K;
    for(int i=0;i<K;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        for(int j=b;j<d;j++){
            for(int k=a;k<c;k++){
                arr[j][k]=1;
            }
        }
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(arr[i][j]==1||chk[i][j]==1)continue;
            chk[i][j]=1;
            DFS(i,j);
            cnt+=1;
            g+=1;
        }
    }
    sort(sz,sz+cnt);
    cout<<cnt<<"\n";
    for(int i=0;i<cnt;i++){
        cout<<sz[i]<<" ";
    }
}
