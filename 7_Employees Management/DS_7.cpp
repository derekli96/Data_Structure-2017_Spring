#include<iostream>

using namespace std;


struct AVLNode{
	int data;
	int lf, rf;
	AVLNode *lChild, *rChild;
};

void RotateL(AVLNode *& ptr);
void RotateR(AVLNode *& ptr);
void insert(int num, AVLNode *& ptr);
void del(int num, AVLNode *& ptr);
int getNum(int rank, AVLNode *& ptr);
int getRank(int num, AVLNode *& ptr);

int main(){
	int N;
	char caseType;
	int input,output;
	AVLNode *ptr = NULL;
	
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> caseType;
		cin >> input;
		switch (caseType){
		case 'I':
		insert(input, ptr);
		break;
		case 'D':
		del(input, ptr);
		break;
		case 'Q':
		output=getNum(input, ptr);
		cout << output << endl;
		break;
		case 'S':
		output=getRank(input, ptr);
		cout << output << endl;
		break;
		}
	}
	return 0;
}

void RotateL(AVLNode *& ptr){
	AVLNode *subL = ptr;
	ptr = subL -> rChild;
	subL -> rChild = ptr -> lChild;
	ptr -> lChild = subL;
	subL -> rf = ptr -> lf;
	ptr -> lf = subL -> lf + subL -> rf;
}

void RotateR(AVLNode *& ptr){
	AVLNode *subR = ptr;
	ptr = subR -> lChild;
	subR -> lChild = ptr -> rChild;
	ptr -> rChild = subR;
	subR -> lf = ptr -> rf;
	ptr -> rf = subR -> lf + subR -> rf;
}

void insert(int num, AVLNode *& ptr){
	if (ptr != NULL){
		if (ptr -> data > num){
			ptr -> lf ++;
			insert(num, ptr -> lChild);
			if ((ptr -> lf - ptr -> rf) >= 2){
				RotateR(ptr);
			}				
		}
		else if (ptr -> data < num){
			ptr -> rf ++;
			insert(num, ptr -> rChild);
			if ((ptr -> rf - ptr -> lf) >= 2){
				RotateL(ptr);
			}
		}
	}
	else{
		ptr = new AVLNode;
	    ptr -> data = num;
		ptr -> lf = 1;
		ptr -> rf = 1;
		ptr -> lChild = NULL;
		ptr -> rChild = NULL;
	}
}


void del(int num, AVLNode *& ptr){
	
	if (ptr != NULL){
		if (ptr -> data > num){
			ptr -> lf --;
			del(num, ptr -> lChild);
			if ((ptr -> rf - ptr -> lf) >= 2){
				RotateL(ptr);			
			}
		}
		else if (ptr -> data < num){
			ptr -> rf --;
			del(num, ptr -> rChild);
			if ((ptr ->lf - ptr -> rf) >= 2){
				RotateR(ptr);
			}
		}
		else if (ptr -> data == num && ptr -> lChild != NULL && ptr -> rChild != NULL){
			AVLNode *temp;
			ptr -> rf --;
			temp = ptr -> rChild;
			while (temp -> lChild != NULL){
				temp = temp -> lChild;
			}				
			ptr -> data =  temp ->data;
			del(ptr -> data, ptr -> rChild);
			if (ptr -> lf - ptr -> rf >= 2)
				RotateR(ptr);
			delete temp;
		}
		else{
			if (ptr -> lChild == NULL){
				ptr = ptr -> rChild;
			}				
			else{
				ptr = ptr -> lChild;
			}				
		}
	}
}

int getNum(int rank, AVLNode *& ptr){
	AVLNode *temp = ptr;
	int r = ptr -> lf;
	
	while (r != rank){
		if (r > rank){
			r = r - temp -> lf;
			temp = temp -> lChild;
			r = r + temp -> lf;
		}
		else{
			temp = temp -> rChild;
			r = r + temp ->lf;
		}
	}
	
	return temp -> data;
}

int getRank(int num, AVLNode *& ptr){
	AVLNode *temp = ptr;
	int r = 0;

	while (num != temp -> data){
		if (num > temp -> data){
			r = r + temp -> lf;
			temp = temp -> rChild;
		}
		else{
			temp = temp -> lChild;
		}
	}

	r = r + temp -> lf;
	return r;
}


