#include<iostream>
using namespace std;
int X1,X2,X3,Y1,Y2,Y3,R;
int main(){
	cin>>X3>>Y3>>R>>X1>>Y1>>X2>>Y2;
	X2-=X1;Y2-=Y1;X3-=X1;Y3-=Y1;X1=0;Y1=0;
	int d1=X3*X3+Y3*Y3;
	int d2=X3*X3+(Y2-Y3)*(Y2-Y3);
	int d3=(X2-X3)*(X2-X3)+Y3*Y3;
	int d4=(X2-X3)*(X2-X3)+(Y2-Y3)*(Y2-Y3);
	if(X3>=R && X3<=X2-R && Y3>=R && Y3<=Y2-R)cout<<"NO"<<endl<<"YES"<<endl;
	else if(d1<=R*R && d2<=R*R && d3<=R*R && d4<=R*R)cout<<"YES"<<endl<<"NO"<<endl;
	else{cout<<"YES"<<endl<<"YES"<<endl;}
	return 0;
}