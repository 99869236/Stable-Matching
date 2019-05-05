//short path problem
#include<fstream>
#include<iostream>
using namespace std;

const int inf=99999;
//cannot reach directly
void shortpath(int e[10][10],int dis[10],int b[10],int n){
	int i,j,v,min,u;
	for(i=1;i<=n-1;i++){
		for(i=1;i<=n-1;i++){//Find the closest point to vertex one
			min=inf;
			for(j=1;j<=n;j++){
				if(b[j]==0&&dis[j]<min){
					min=dis[j];
					u=j;
				}
			}
			b[u]=1;//the vertex is currently closest to the first vertex
			for(v=1;v<=n;v++){
				if(e[u][v]<inf){
					if(dis[v]>dis[u]+e[u][v])
						dis[v]=dis[u]+e[u][v];
				}
			} 
		}
	}
		for(i=1;i<=n;i++){
			cout<<dis[i]<<" "; //output the result
	   }
}	

int main(){
	int e[10][10],dis[10],book[10],i,j,m,n,t1,t2,t3;
	ifstream file("shortpath.txt");//get inout form file
	file>>n>>m;//in put the number of vertices and edge
	for(i=1;i<=n;i++){//initialization 
		for(j=1;j<=n;j++){
			if(i==j) {
				e[i][j]=0;//0 if the start node and the end node is the same
			}				
			else{ e[i][j]=inf;//infinite if there are not the same
			}
		}
	}
	//t1 is the start node
	//t2 is the end node
	//t3 is the value between them
	for(i=1;i<=m;i++){
		file>>t1>>t2>>t3;
		e[t1][t2]=t3;
	}

	for(i=1;i<=n;i++){
		dis[i]=e[1][i];//initialize the distance
	}
	for(i=1;i<=n;i++){
		book[i]=0;
	}
	book[i]=1;// the shortest path of the first node
	shortpath(e,dis,book,n); 
}
