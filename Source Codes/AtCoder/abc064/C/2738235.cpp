#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[110];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int b[10]={0};
	int c=0;
	for(int i=0;i<n;i++){
		if(a[i]<400){
			b[0]++;
		}
		else if(400<=a[i]&&a[i]<800){
			b[1]++;
		}
		else if(800<=a[i]&&a[i]<1200){
			b[2]++;
		}
		else if(1200<=a[i]&&a[i]<1600){
			b[3]++;
		}
		else if(1600<=a[i]&&a[i]<2000){
			b[4]++;
		}
		else if(2000<=a[i]&&a[i]<2400){
			b[5]++;
		}
		else if(2400<=a[i]&&a[i]<2800){
			b[6]++;
		}
		else if(2800<=a[i]&&a[i]<3200){
			b[7]++;
		}
		else{
			c++;
		}
	}
	int min=0;
	for(int i=0;i<8;i++){
		if(b[i]!=0){
			min++;
		}		
	}
	int max=min+c;
	if(min==0){
		min=1;
	}
	cout<<min<<' '<<max<<endl;
}