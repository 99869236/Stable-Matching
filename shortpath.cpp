
#include<fstream>
#include<iostream>
using namespace std;

const int inf=99999;

void shortpath(int e[10][10],int dis[10],int b[10],int n){
	int i,j,v,min,u;
	for(i=1;i<=n-1;i++){
		for(i=1;i<=n-1;i++){
			min=inf;
			for(j=1;j<=n;j++){
				if(b[j]==0&&dis[j]<min){
					min=dis[j];
					u=j;
				}
			}
			b[u]=1;
			for(v=1;v<=n;v++){
				if(e[u][v]<inf){
					if(dis[v]>dis[u]+e[u][v])
						dis[v]=dis[u]+e[u][v];
				}
			} 
		}
	}
		for(i=1;i<=n;i++){
			cout<<dis[i]<<" "; 
	   }
}	

int main(){
	int e[10][10],dis[10],book[10],i,j,m,n,t1,t2,t3;
	ifstream file("shortpath.txt");
	file>>n>>m;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i==j) {
				e[i][j]=0;
			}				
			else{ e[i][j]=inf;
			}
		}
	}
	for(i=1;i<=m;i++){
		file>>t1>>t2>>t3;
		e[t1][t2]=t3;
	}

	for(i=1;i<=n;i++){
		dis[i]=e[1][i];
	}
	for(i=1;i<=n;i++){
		book[i]=0;
	}
	book[i]=1;
	shortpath(e,dis,book,n); 
}
