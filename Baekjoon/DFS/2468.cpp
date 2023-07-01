#include <bits/stdc++.h>
using namespace std;

int nx,ny,cnt;
int depth=1;
int N,mx,k;
int arr[105][105];
int chk[105][105];
int safe[105];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void DFS(int x,int y){
    for(int i=0;i<4;i++){
        nx = x+dx[i];
        ny = y+dy[i];
        if(nx>=N||ny>=N||nx<0||ny<0||arr[nx][ny]==0)continue;
        if(chk[nx][ny]==1)continue;
        chk[nx][ny]=1;
        DFS(nx,ny);
    }
    return;
}

int main(){    
        cin >> N;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin >> arr[i][j];
                mx=max(arr[i][j],mx);
            }
        }
        int Mx,asdf = 0;
        Mx=mx+1;

        for(int k=0;k<Mx;k++){
            if (k == 0) depth = 0;
            else depth = 1;

            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    if (arr[i][j] != 0) arr[i][j] -= depth ;
                    }
            }

            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    if(chk[i][j]==1)continue;
                    if(arr[i][j]==0)continue;
                    chk[i][j]=1;
                        DFS(i,j);  
                        cnt+=1;
                    }
            }
            asdf = max(asdf,cnt);
            cnt=0;
            memset(chk,0,sizeof(chk));
    }
    cout << asdf;
}