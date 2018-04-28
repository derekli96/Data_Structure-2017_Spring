#include <stdio.h>

int find(int u, int *parent) {
	if(parent[u] != u)
		parent[u]=find(parent[u],parent);
	return parent[u];
}

int main(){
	int n=0,m=0;
	scanf("%d%d",&n,&m);
	
    int *parent = new int[n+1];
	int *u = new int[m+1];
	int *v = new int[m+1];
	int *w = new int[m+1];
	int conIs=0;
	bool samePath=false;
	long long int num=1;
	long long int profit=0;
	
	for(int i=1;i<n+1;i++){
		parent[i]=i;
	}
	
	for(int i=1;i<m+1;i++){
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
	}
	
	for(int i=1;i<m+1;i++){		
		if(conIs>=(n-1)){//Free birdges enough
            if(samePath){
				num=(num*2)%1000000007;
				samePath=false;
			}
			profit+=w[i];
			printf("0 %lld %lld\n",profit,num);
		}
        else if(conIs<n-1){//If still need more free bridges
		    if(samePath){
				num=(num*2)%1000000007;
				samePath=false;
			}
		
			if(i<m&&w[i]==w[i+1]&&find(u[i],parent)!=find(v[i],parent)){
				if((parent[u[i]]==find(u[i+1],parent)&&parent[v[i]]==find(v[i+1],parent))||
				   (parent[u[i]]==find(v[i+1],parent)&&parent[v[i]]==parent[u[i+1]])){
					samePath=true;
				}
			} //of there are two same bridges, the number of solutions will be double
			
			if(find(u[i],parent)==find(v[i],parent)){
			    profit+=w[i];	
			}//if the new bridge connect the islands that have been connected
			else{
				parent[parent[u[i]]] = parent[v[i]];
				conIs ++;
			}//if the new bridge connect a new island
			printf("%d %lld %lld\n", n-1-conIs,profit,num);
		}		
	}
	
    return 0;
}