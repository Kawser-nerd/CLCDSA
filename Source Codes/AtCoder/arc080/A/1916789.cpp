#include<iostream>
using namespace std;
long a[200050];
int main(){
	int n,i;
	long cnt1=0,cnt2=0,cnt3=0;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
		if(a[i]%4==0) cnt1++;
		else if(a[i]%2==0) cnt2++;
		else cnt3++;
	}
	if(cnt3&&cnt1<cnt3&&cnt2||cnt3&&cnt2==0&&cnt1<cnt3-1) cout<<"No";
	else cout<<"Yes"; 
	return 0;
} ./Main.cpp:14:20: warning: '&&' within '||' [-Wlogical-op-parentheses]
        if(cnt3&&cnt1<cnt3&&cnt2||cnt3&&cnt2==0&&cnt1<cnt3-1) cout<<"No";
           ~~~~~~~~~~~~~~~^~~~~~~~
./Main.cpp:14:20: note: place parentheses around the '&&' expression to silence this warning
        if(cnt3&&cnt1<cnt3&&cnt2||cnt3&&cnt2==0&&cnt1<cnt3-1) cout<<"No";
                          ^
           (                    )
./Main.cpp:14:41: warning: '&&' within '||' [-Wlogical-op-parentheses]
        if(cnt3&&cnt1<cnt3&&cnt2||cnt3&&cnt2==0&&cnt1<cnt3-1) cout<<"No";
                                ~~~~~~~~~~~~~~~^~~~~~~~~~~~~
./Main.cpp:14:41: note: place parentheses around the '&&' expression to silence this warning
        if(cnt3&&cnt1<cnt3&&cnt2||cnt3&&cnt2==0&&cnt1<cnt3-1) cout<<"No";
                                               ^
                                  (                         )
2 warnings generated.