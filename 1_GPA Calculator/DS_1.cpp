#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
using namespace std;

int main(){
	int totalStudent,studentNo,caseNo,caseType,credit,gp,gpaCount;
	float gpa;
	string grade;
	int studentGp[10001][2]={0};
	int gpaNo[41]={0};

	cin >> totalStudent;
	cin >> caseNo;

	for(int i=1;i<=caseNo;i++){
		cin >> caseType;
		switch(caseType){
		case 1:
			cin >> studentNo;
			cin >> credit;
			cin >> grade;
			if(grade=="A+")
				gp=40;
			else if (grade=="A=")
				gp=40;
			else if (grade=="A-")
				gp=37;
			else if (grade=="B+")
				gp=33;
			else if (grade=="B=")
				gp=30;
			else if (grade=="B-")
				gp=27;
			else if (grade=="C+")
				gp=23;
			else if (grade=="C=")
				gp=20;
			else if (grade=="C-")
				gp=17;
			else if (grade=="D+")
				gp=13;
			else if (grade=="D=")
				gp=10;
			else if (grade=="F=")
				gp=0;
	        
			if(studentGp[studentNo][0]!=0){
				gpa=((float)studentGp[studentNo][1])/((float)studentGp[studentNo][0]);
			    gpaCount=ceil(gpa);
				gpaNo[gpaCount]--;
			}
			studentGp[studentNo][0]+=credit;
			studentGp[studentNo][1]+=credit*gp;
			gpa=((float)studentGp[studentNo][1])/((float)studentGp[studentNo][0]);
			gpaCount=ceil(gpa);
			gpaNo[gpaCount]++;
			break;
		
		case 2:
			cin >> studentNo;
			gpa=((float)studentGp[studentNo][1])/((float)studentGp[studentNo][0]);
			gpa=ceil(gpa);
			gpa=gpa/10.0;
			printf("%.1f\n",gpa);
			break;

		case 3:
			cin >> gpa;
			gp=(int)(gpa*10.0+0.5);
			cout << gpaNo[gp] << endl;
			break;
		}
	}
}