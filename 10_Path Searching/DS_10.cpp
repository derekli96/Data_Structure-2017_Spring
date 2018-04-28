#include<stdio.h>
#include<stdlib.h>
#include<functional>
#include<queue>  
#include<vector>
#define N 10000000
using namespace std;

struct cell
{
	int x;
	int y;
	int t;
};

struct cmp
{  
    bool operator ()(cell a,cell b)
	{
        return a.t>b.t;
	}
}; 

int main(){
	int n,m,x,y,time;	
	int **map;
	int **dis;
	int **tag;
	char c;
	priority_queue<cell,vector<cell>,cmp> q;
	
	scanf("%d%d",&n,&m);
	
	map=(int**)malloc(n*sizeof(int*));
	dis=(int**)malloc(n*sizeof(int*));
	tag=(int**)malloc(n*sizeof(int*));
	for(int i=0;i<n;i++){
		map[i]=(int*)malloc(m*sizeof(int));
		dis[i]=(int*)malloc(m*sizeof(int));
		tag[i]=(int*)malloc(m*sizeof(int));
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			dis[i][j]=N;
			tag[i][j]=0;
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			c=getchar();
			while(c=='\n'||c==' '){
			    c=getchar();
			}
			if(c=='#'){
				map[i][j]=-1;
			}
			else{
				map[i][j]=c-'0';
			} 
		}
	}
	
	scanf("%d%d",&x,&y);
	x--;
	y--;
	
	cell start;
	start.x=x;
	start.y=y;
	start.t=0;
	dis[x][y]=0;
	
	q.push(start);
	
	while(!q.empty()){
		cell cell0=q.top();
		q.pop();
		x=cell0.x;
		y=cell0.y;
		if(tag[x][y]==0){
		tag[x][y]=1;
		if(x-1>-1&&tag[x-1][y]==0){
			if(map[x-1][y]==-1){
				dis[x-1][y]=-1;
			}
			else
			{
				if(map[x][y]>=map[x-1][y]){
					time=1;
				}
			    else{
					time=map[x-1][y]-map[x][y]+1;
				} 
			    if (dis[x][y]+time<dis[x-1][y])
				{
			    	dis[x-1][y]=dis[x][y]+time;
		    	    cell newCelll;
					newCelll.x=x-1;
					newCelll.y=y;
					newCelll.t=dis[x-1][y];
			        q.push(newCelll);
				}
			}
		}
		
		if(x+1<n&&tag[x+1][y]==0){			
			if(map[x+1][y]==-1){
				dis[x+1][y]=-1;
			}
			else
			{
				if(map[x][y]>=map[x+1][y]){
					time=1;
				}
			    else
				{
					time=map[x+1][y]-map[x][y]+1;
				}
			    if (dis[x][y]+time<dis[x+1][y])
				{
			    	dis[x+1][y]=dis[x][y]+time;
					cell newCellr;
					newCellr.x=x+1;
					newCellr.y=y;
					newCellr.t=dis[x+1][y];
			        q.push(newCellr);
				}
			}
		}
		
		if (y-1>-1&&tag[x][y-1]==0){
			if(map[x][y-1]==-1) dis[x][y-1]=-1;
			else
			{
				if(map[x][y]>=map[x][y-1]){
				    time=1;					
				}
			    else{
					time=map[x][y-1]-map[x][y]+1;
				} 
			    if (dis[x][y]+time<dis[x][y-1])
				{
			    	dis[x][y-1]=dis[x][y]+time;
		        	cell newCellu;
					newCellu.x=x;
					newCellu.y=y-1;
					newCellu.t=dis[x][y-1];
			        q.push(newCellu);
				}
				
			}
		}
				
		if (y+1<m&&tag[x][y+1]==0)
		{
			if(map[x][y+1]==-1) dis[x][y+1]=-1;
			else
			{
				
				if(map[x][y]>=map[x][y+1]){
					time=1;
				}				    
			    else{
				    time=map[x][y+1]-map[x][y]+1;					
				}
			    if (dis[x][y]+time<dis[x][y+1])
				{
			        dis[x][y+1]=dis[x][y]+time;
					cell newCelld;
					newCelld.x=x;
					newCelld.y=y+1;
					newCelld.t=dis[x][y+1];
			        q.push(newCelld);
				}
			}
		}
		}		
	}
	
	for(int i=0;i<n;i++){
		for (int j=0;j<m;j++){
		    if(dis[i][j]==N){
				printf("-1 ");
			} 
			else{
				printf("%d ",dis[i][j]);
			} 
		}
		printf("\n");
	}
     
    return 0;
	
}