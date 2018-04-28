#include <iostream>
#include <malloc.h>
#include <math.h>
using namespace std;

int gaussElimination(double** matrix,int matrixN){
	int r=matrixN;
	int c=matrixN+1;
	int k=0;
	int rowNo=0;
	bool flag=false;
	double max=matrix[k][k];
	
	while(k<r){
		rowNo=k;
		max=matrix[k][k];
		for(int i=k;i<r;i++){
			if(matrix[i][k]>max)
			{
				flag=true;
				max=matrix[i][k];
				rowNo=i;
			}
		}
		if(fabs(max-0.0)<0.0001){
			cout << "0" << endl;
			return 0;
		}
		if(k!=rowNo){
			double temp=0;
			for(int i=0;i<c;i++){
				temp=matrix[k][i];
				matrix[k][i]=matrix[rowNo][i];
				matrix[rowNo][i]=temp;
			}
		}
		for(int i=k;i<r-1;i++){
			double temp=matrix[i+1][k];
			for(int j=k;j<c;j++){
				matrix[i+1][j]-=((temp/matrix[k][k])*matrix[k][j]);
			}
		}
		k++;
		flag=false;
	}
	
	for(int i=0; i<r; i++){
        double temp1=matrix[i][i];
        for(int j=i; j<c; j++){
           matrix[i][j]/=temp1;
        }
    }

    for(int i=1; i<r; i++){
        for(int j=i-1; j>=0; j--)
        {
            double temp2=matrix[j][i];
            for(int h=i; h<c; h++)
            {
                matrix[j][h]-=(temp2*matrix[i][h]);
            }
        }
    }
	
	for(int i=0; i<r; i++){
            cout << matrix[i][c-1] << " ";
        }
	
	cout << endl;
	return 0;
}

int GS(int *matrixRow,int *matrixCol,double *matrixValue,double *matrixb,int matrixN,int matrixK,double *solution){
    double eps=0.01;
	double *a,*temp;
	bool flag=true;
	
	a=(double*)malloc(matrixN*sizeof(double));
	temp=(double*)malloc(matrixN*sizeof(double));
	
	for(int i=0;i<matrixK;i++){
		if(matrixRow[i]==matrixCol[i]){
			a[matrixRow[i]-1]=matrixValue[i];
		}
	}
	
	for(int i=0;i<matrixN;i++){
		temp[i]=solution[i];
	}
	
	do{
		flag=true;
		for(int n=0;n<matrixK;n++){
			if(!(matrixRow[n]==matrixCol[n])){
				temp[matrixRow[n]-1]-=solution[matrixCol[n]-1]*matrixValue[n];
			}			
		}
		for(int i=0;i<matrixN;i++){
		    temp[i]+=matrixb[i];
			temp[i]/=a[i];
	    }
		for(int i=0;i<matrixN;i++){
		    if(fabs(temp[i]-solution[i])>=eps){
				flag=false;
			}
			solution[i]=temp[i];
	    }
	}while(flag==false);
	
	if(flag){
		for(int i=0;i<matrixN;i++){
			cout << solution[i] << " ";
		}
		cout << endl;
	}
	return 0;
}

int main(){
	int T,matrixN,lineNo,x,y,matrixK,temp;
	int *matrixRow, *matrixCol;
	double *solution,*matrixValue,*matrixb;
	double **matrix;
	char matrixType;
	
	cin >> T;
	
	for(int i=0;i<T;i++){
		cin >> matrixType;
		switch(matrixType){
			case 'R':
			cin >> matrixN;
			matrix=(double**)malloc(matrixN*sizeof(double*));

			for(int j=0;j<matrixN;j++){
				*(matrix+j)=(double*)malloc((matrixN+1)*sizeof(double));
			}
			for(int r=0;r<matrixN;r++){
				for(int c=0;c<matrixN;c++){
					cin >> matrix[r][c];
				}
			}
			for(int r=0;r<matrixN;r++){
				int c=matrixN;
				cin >> matrix[r][c];
			}
			gaussElimination(matrix,matrixN);
			break;
			
			case 'S':
			cin >> matrixN;
			cin >> matrixK;
			matrixRow=(int*)malloc(matrixK*sizeof(int));
			matrixCol=(int*)malloc(matrixK*sizeof(int));
			matrixValue=(double*)malloc(matrixK*sizeof(double));
			matrixb=(double*)malloc(matrixN*sizeof(double));
            solution=(double*)malloc(matrixN*sizeof(double));
						
			for(int i=0;i<matrixK;i++){
				cin >> matrixRow[i];
				cin >> matrixCol[i];
				cin >> matrixValue[i];				
			}
			
			for(int i=0;i<matrixN;i++){
				cin >> matrixb[i];
				solution[i]=1;
			}
			
			GS(matrixRow,matrixCol,matrixValue,matrixb,matrixN,matrixK,solution);

			break;
		}
	}
}