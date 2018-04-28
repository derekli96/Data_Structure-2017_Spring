#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

struct stringNode
{
	int stringNum;
	string str;
};

bool compare(stringNode str1,stringNode str2)
{
	return (str1.str<str2.str);
}

int biSearch(string keyStr,stringNode* strSet,int n)  
{
	int l=0,r=n-1,m=0;
	if(keyStr==strSet[l].str){
		return l+1;
	}
	
	while((l+1)!=r)
	{
		m=(l+r)/2;
		if(keyStr==strSet[m].str){
			return m+1;
		}
		else if (keyStr<strSet[m].str){
			r=m;
		}  
		else{
			l=m;
		}
	}
	
	if(keyStr==strSet[l].str){
		return l+1;
	} 
    else if (keyStr==strSet[r].str){
		    return r+1;
		}	
	
	if(keyStr<strSet[l].str){
		return l+1;
	}
	else if (keyStr<strSet[r].str){
		return r+1;
	}
	else{
		return r+2;
	}
}

int main(){
	int n=0,m=0,p=0;
	
	cin>>n;
	stringNode *strSet=new stringNode[n];
	for(int i=0;i<n;i++){
		cin>>strSet[i].str;
		strSet[i].stringNum=i+1;
	}
	sort(strSet,strSet+n,compare);
	for(int i=0;i<n;i++){
		cout<<strSet[i].stringNum<<" ";
	}
	cout<<endl;
	
	cin>>m;
	string *strSubset=new string[m];
	for(int i=0;i<m;i++){
		cin>>strSubset[i];
	}
	for (int i=0;i<m;i++){
		cout<<biSearch(strSubset[i],strSet,n)<<" ";
	}
	cout<<endl;
	
    cin>>p;
	string *preStr=new string [p];
	for(int i=0;i<p;i++){
		cin>>preStr[i];
	}
	for(int i=0;i<p;i++){
		int count1=biSearch(preStr[i],strSet,n);
		int length=preStr[i].length();
		string tmpStr=preStr[i];
		tmpStr[length-1]+=1;
		int count2=biSearch(tmpStr,strSet,n);
		cout<<count2-count1<<" ";
	}
	cout<<endl;

	return 0;	
	
}