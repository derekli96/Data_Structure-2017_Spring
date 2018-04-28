#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <string>
#include <set>

using namespace std;

#define N 100000 

long long int HuffmanWPL(long long int heap[]);                             
void PercolateDown(long long int heap[],int *Size,int parent);  
void BuildMinHeap(long long int heap[],int *Size);               
long long int DeleteMin(long long int heap[], int *Size);                   
void Insert(long long int minHeap[],int * Size,long long int weight);     
int n,q;

int main()
{	
	cin >> n;
    long long int *f,*g;
	int times,i,moodType;
	char caseType;
	string mood;
	multiset<int> data;
	multiset<int>::iterator it;
	multiset<int>::reverse_iterator it1;

	f=(long long int*)malloc((n+1)*sizeof(long long int));
	for(i=1;i<(n+1);i++){
		cin >> times;
		data.insert(times);
	}

	i=1;
	for(it=data.begin();it!=data.end();++it){
	    f[i]=*it;
		i++;
	}

    long long int minWPL = HuffmanWPL(f);             
	cout << minWPL << endl;
	cin >> mood;
	
	if(mood=="BAD"){
	    moodType=0;
	}
	else{
	    moodType=1;
	}

	switch(moodType){
	case(0):		
		break;
	case(1):
		cin >> q;
		for(int j=0;j<q;j++){
			cin >>caseType;
			switch(caseType){
			case('D'):
				it1=data.rbegin();
				data.erase(data.find(*it1));
				break;
			case('E'):
				it=data.begin();
				data.erase(data.find(*it));
				break;
			case('A'):
				cin >> times;
				data.insert(times);
				break;
			}
		}
		n=data.size();
		g=(long long int*)malloc((n+1)*sizeof(long long int));
		i=1;
		for(it=data.begin();it!=data.end();++it){
	    g[i]=*it;
		i++;
	    }
		minWPL = HuffmanWPL(g);
		cout << minWPL << endl;
		break;
	}
	return 0;
}

void PercolateDown(long long int heap[],int *Size,int parent)
{
    long long int temp = heap[parent];
    int i, child;

    for (i = parent; i*2 <= (*Size); i = child){
        child = 2 * i;
        if (child != (*Size) && heap[child+1] < heap[child])    
            child++;
        if (temp > heap[child])     
            heap[i] = heap[child];  
        else
            break;
    }
    heap[i] = temp;
}

void BuildMinHeap(long long int heap[],int *Size)
{
    for (int i = (*Size) / 2; i > 0; i--)   
	{
	    PercolateDown(heap, Size, i); 
	}      
}

long long int DeleteMin(long long int heap[],int *Size)
{
    long long int minElem = heap[1];          
    heap[1] = heap[*Size];          
    (*Size)--;                      
    PercolateDown(heap, Size, 1);   
    return minElem;
}

void Insert(long long int heap[],int *Size,long long int weight)
{
    int i;
    for (i = ++(*Size); i > 0 && heap[i/2] > weight; i /= 2){    
	    heap[i] = heap[i/2];
	}             
    heap[i] = weight;
}

long long int HuffmanWPL(long long int heap[])
{
    int Size = n;   
   
    BuildMinHeap(heap, &Size);

    long long int WPL = 0;
    for (int i = 1; i < n; i++) {
        long long int leftWeight = DeleteMin(heap, &Size);
        long long int rightWeight = DeleteMin(heap, &Size);
        long long int rootWeight = leftWeight + rightWeight;
        WPL += rootWeight;
        Insert(heap,&Size,rootWeight);
    }
    return WPL;
}