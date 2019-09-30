#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main(){
	double km;
	string vv;
	cin >> km;
	km /= 1000;
	if(km < 0.1) vv="00";
	else if(km <= 5) vv=to_string((int)(km*10));
	else if(km <= 30) vv=to_string((int)(km+50));
	else if(km <= 70) vv=to_string((int)((km-30)/5 + 80));
	else vv = "89";
	if(vv.size() == 1){
		vv = "0" +vv;
	}
	cout << vv << endl;
}