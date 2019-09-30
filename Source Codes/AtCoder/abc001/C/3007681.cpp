#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans1, ans2;
int main(void){
	double deg, dis;
	string s1[] = {
		"N","NNE","NE","ENE","E","ESE","SE","SSE",
		"S","SSW","SW","WSW","W","WNW","NW","NNW","N"
	};
	double a[] = {0.2,1.5,3.3,5.4,7.9,10.7,13.8,17.1,20.7,24.4,28.4,32.6,10000};
	cin >> deg >> dis;
	dis = dis / 60;
	int temp = dis * 10;
	if(dis * 10 - (double)temp >= 0.5){
		dis = (double)(temp+1) / 10;
	}else{
		dis = (double)temp / 10;
	}
	for(int i = 0; i < 13; ++i){
		if(dis<=a[i]){
			ans2 = i;
			break;
		}
	}
	if(ans2 == 0){
		cout << "C 0" << endl;
		return 0;
	}
	/*
	for(int i = 0; i < n; ++i){
		if(i * 2255<= deg * 10 && deg * 10<=)
	}
	*/
	cout << s1[(int)(deg*10+1125)/2250] << " " << ans2 << endl;;

	return 0;
}