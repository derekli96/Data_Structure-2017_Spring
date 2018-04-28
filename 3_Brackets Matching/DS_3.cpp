#include <iostream>
#include <deque>

using namespace std;

deque<char> qSort(deque<char> queue){
	char brac1,brac2;
	deque<char> qResult;
	while(!queue.empty()){
		brac1=queue.front();
		queue.pop_front();
		if(!qResult.empty()){
			brac2=qResult.back();
		    if((brac1==')'&&brac2=='(')||(brac1=='>'&&brac2=='<')||(brac1==']'&&brac2=='[')||(brac1=='}'&&brac2=='{')){
					qResult.pop_back();							
				}
				else{
			        qResult.push_back(brac1);
				}
			}
			else{
				qResult.push_back(brac1);
			}
	}
	return qResult;
}

int main(){
	int caseNo,caseType;
	int ifTrue=0;
	char brac1,brac2; //brac1:record bracket from input; brac2:record bracket from the beginning/end of the queue
	deque<char> bracQ1,bracQ2;//bracQ1:record elements not matched; bracQ2:record all elements
	
	cin >> caseNo;
	
	for(int i=0;i<caseNo;i++){
		cin >> caseType;
		switch(caseType){
			case 1:
			cin >> brac1;
			bracQ2.push_back(brac1);
			if(!bracQ1.empty()){
				brac2=bracQ1.back();
			    if((brac1==')'&&brac2=='(')||(brac1=='>'&&brac2=='<')||(brac1==']'&&brac2=='[')||(brac1=='}'&&brac2=='{')){
					bracQ1.pop_back();
					if(bracQ1.empty())
					{
						ifTrue=1;
						cout << ifTrue << endl;
					}
					else{
						ifTrue=0;
						cout << ifTrue << endl;
					}
				}
			    else{
			        bracQ1.push_back(brac1);
				    ifTrue=0;
				    cout << ifTrue << endl;
			    }
			}
			else{
				bracQ1.push_back(brac1);
				ifTrue=0;
				cout << ifTrue << endl;
			}
			break;
			
			case 2:
			cin >> brac1;
			bracQ2.push_front(brac1);
			if(!bracQ1.empty()){
				brac2=bracQ1.front();
				if((brac1=='('&&brac2==')')||(brac1=='<'&&brac2=='>')||(brac1=='['&&brac2==']')||(brac1=='{'&&brac2=='}')){
					bracQ1.pop_front();
					if(bracQ1.empty())
					{
						ifTrue=1;
						cout << ifTrue << endl;
					}
					else{
						ifTrue=0;
						cout << ifTrue << endl;
					}				
				}
				else{
			        bracQ1.push_front(brac1);
				    ifTrue=0;
				    cout << ifTrue << endl;
			    }
			}
			else{
				bracQ1.push_front(brac1);
				ifTrue=0;
				cout << ifTrue << endl;
			}
			break;
			
			case 3:
			bracQ2.pop_back();
			bracQ1=qSort(bracQ2);
			if(bracQ1.empty()){
				ifTrue=1;
				cout << ifTrue << endl;		
			}
			else{
				ifTrue=0;
				cout << ifTrue << endl;
			}
			break;
			
			case 4:
			bracQ2.pop_front();
			bracQ1=qSort(bracQ2);
			if(bracQ1.empty()){
				ifTrue=1;
				cout << ifTrue << endl;	
			}
			else{
				ifTrue=0;
				cout << ifTrue << endl;
			}
			break;
			
		}
		
	}
	
}

