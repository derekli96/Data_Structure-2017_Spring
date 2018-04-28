#include <iostream>
#include <malloc.h>
using namespace std;

int main(){
	int cardNo,caseNo,caseType,pileX,pileY,cardNum,cardX;
	int** cardPile;
	int* card;
	int pileSta[100000][2]={0};//0:count;1:maxroom
	int caseRecord[1000000][3];//0:caseType;1:pileX;2:pileY/cardX;
	
	cin >> cardNo;
	cin >> caseNo;

	for(int a=0;a<caseNo;a++){
	cin >> caseRecord[a][0];
	cin >> caseRecord[a][1];
	cin >> caseRecord[a][2];
	if(caseRecord[a][0]==1){
		pileSta[caseRecord[a][2]-1][1]++;
	}
	}
	
	cardPile=(int **)malloc(cardNo*sizeof(int*));

	for(int i=0;i<cardNo;i++){
	    card=(int *)malloc((pileSta[i][1]+100)*sizeof(int));
		*card=i+1;
		*(cardPile+i)=card;
		pileSta[i][0]=1;
	}

	for(int j=0;j<caseNo;j++){
	    caseType=caseRecord[j][0];
		switch(caseType){
		case 1:
			pileX=caseRecord[j][1];
			pileY=caseRecord[j][2];
			cardNum=*(pileSta[pileX-1][0]-1+*(cardPile+pileX-1));
			*(pileSta[pileX-1][0]-1+*(cardPile+pileX-1))=0;
			pileSta[pileX-1][0]-=1;			
			pileSta[pileY-1][0]+=1;
			*(pileSta[pileY-1][0]-1+*(cardPile+pileY-1))=cardNum;
		 	cout << cardNum << endl;
			break;

		case 2:
			pileX=caseRecord[j][1];
			cardX=caseRecord[j][2];
			cardNum=*(cardX-1+*(cardPile+pileX-1));
			cout << cardNum <<endl;
			break;
		}

	}


}
