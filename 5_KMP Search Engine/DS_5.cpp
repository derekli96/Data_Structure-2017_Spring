#include <stdio.h>
#include <malloc.h>
#include <string.h>
using namespace std;  
  
void getNext(char *key, int *next,int keyLength){  
	int i=0,j=-1;
	next[0]=-1;
	while(i<keyLength)  
	 {  
	   if((j==-1)||(key[i]==key[j]))
	   {  
		  i++;  
		  j++;  
		  next[i]=j;  
	   }  
	   else
	   {  
		  j=next[j];   
	   }  
}  
 
}


bool KMP(char *target,char *pattern,int *next,int targetLength,int patternLength){  
	int i=0;  
	int j=0;  
	getNext(pattern,next,patternLength);		
	if(targetLength<patternLength){
	    return 0;
	}
	while((i<targetLength)&&(j<patternLength)){  
		if(j==-1||target[i]==pattern[j]){  
			i++;  
			j++;  
		}  
		else{
		    j=next[j];  
		}  
	}  
	if(j>=patternLength){
		return true; 
	}  	   
	else{
		return false;
	}
}  

int getIndex(char c){
	if (c<='9'&&c>='0'){
	    return (c-'0');
	}
	if (c<='z'&&c>='a'){
		return (c-'a'+10);
	}  
	if (c='_'){
		return 36;
	} 
}

int main(){
	int w=0,k=0;	
	scanf("%d",&w);
	scanf("%d",&k);
	char **webString=new char *[w];
	char **keyString=new char *[k];
	int *webLength=new int [w];
	int *keyLength=new int [k];
	int **next=new int *[k]; 
	int index[1369][50]={0};
	
	for(int i=0;i<w;i++){
		webString[i]=new char [5001];
		scanf("%s",webString[i]);
		webLength[i]=strlen(webString[i]);
		if (webLength[i]>1){
			for (int j=0;j<(webLength[i]-1);j++)
			{
				int a=getIndex(webString[i][j])*37+getIndex(webString[i][j+1]); 
			    index[a][i]=1; 
			}
		}
	}	
	
	for(int i=0;i<k;i++){
		keyString[i]=new char [5001];		
		scanf("%s",keyString[i]);
		keyLength[i]=strlen(keyString[i]);	
		next[i]=new int [keyLength[i]+1];        
	}	
	
	for(int i=0;i<k;i++){
		if (keyLength[i]==1){
			for (int j=0;j<w;j++){
				if(KMP(webString[j],keyString[i],next[i],webLength[j],keyLength[i])){
					printf("%d ",j+1);
				}			
			}
		    printf("\n");
		}
		else{
			int flag[50]={0};
			for(int a=0;a<w;a++){
				flag[a]=1;
			} 
			for (int b=0;b<keyLength[i]-1;b++){
				int n=getIndex(keyString[i][b])*37+getIndex(keyString[i][b+1]);
				for (int c=0;c<w;c++){
					if (!index[n][c]){
						flag[c]=0;
					}					
				}
			}
			for(int j=0;j<w;j++){
				if(flag[j]==1){
					if(KMP(webString[j],keyString[i],next[i],webLength[j],keyLength[i])){
						 printf("%d ",j+1);
					}
				}
			}
			printf("\n");
	    }
			
	}
	return 0;
} 
