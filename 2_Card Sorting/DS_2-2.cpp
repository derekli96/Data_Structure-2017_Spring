#include <iostream>
#include <malloc.h>
using namespace std;
int main(){
    int cardNo,caseNo,caseType,pileX,pileY,cardNum,cardX;
    int** cardPile;
    int* card;
    int pileSta[100000][2];//0:count;1:maxroom
    cin >> cardNo;
    cin >> caseNo;
    cardPile=(int **)malloc(cardNo*sizeof(int*));
    for(int i=0;i<cardNo;i++){
        card=(int *)malloc(2*sizeof(int));
        *card=i+1;
        *(cardPile+i)=card;
        pileSta[i][0]=1;
        pileSta[i][1]=2;
    }
    for(int j=0;j<caseNo;j++){
        cin >> caseType;
        switch(caseType){
        case 1:
            cin >> pileX;
            cin >> pileY;
            cardNum=*(pileSta[pileX-1][0]-1+*(cardPile+pileX-1));
            *(pileSta[pileX-1][0]-1+*(cardPile+pileX-1))=0;
            pileSta[pileX-1][0]-=1;
            if(pileSta[pileY-1][0]<pileSta[pileY-1][1]){
                pileSta[pileY-1][0]+=1;
                *(pileSta[pileY-1][0]-1+*(cardPile+pileY-1))=cardNum;
            }
            else{
                card=(int *)malloc((pileSta[pileY-1][0]*2)*sizeof(int));
                for(int k=0;k<pileSta[pileY-1][0];k++){
                    *(card+k)=*(k+*(cardPile+pileY-1));
                }
                free(*(cardPile+pileY-1));
                *(cardPile+pileY-1)=card;
                pileSta[pileY-1][0]+=1;
				pileSta[pileY-1][1]*=2;
                *(pileSta[pileY-1][0]-1+*(cardPile+pileY-1))=cardNum;
            }
            cout << cardNum << endl;
            break;
        case 2:
            cin >> pileX;
            cin >> cardX;
            cardNum=*(cardX-1+*(cardPile+pileX-1));
            cout << cardNum <<endl;
            break;
        }
    }
}