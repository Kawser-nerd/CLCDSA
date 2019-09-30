#include<iostream>
#include<vector>
#include<string>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
int h, w;
char a[9][9];

bool judge() 
{
	int fx = 0;
	int fy = 0;
	a[fy][fx] = '.';
	while (!(fx == w - 1 && fy == h - 1)) {//goal ????????
		if (fx < w - 1 && fy < h - 1 && a[fy][fx + 1] == '#' && a[fy + 1][fx] == '.') {//?????????
			fx++;
			a[fy][fx] = '.';
		}
		else if (fx < w - 1 && fy < h - 1 && a[fy][fx + 1] == '.' && a[fy + 1][fx] == '#') {//?????????
			fy++;
			a[fy][fx] = '.';
		}
		else if (fx == w - 1 && a[fy + 1][fx] == '#') {
			fy++;
			a[fy][fx] = '.';
		}
		else if (fy == h - 1 && a[fy][fx + 1] == '#') {
			fx++;
			a[fy][fx] = '.';
		}
		else {
			//for (int i = 0; i < h; i++) {
				//for (int j = 0; j < w; j++) {
					//cout << a[i][j] << " ";
				//}
				//cout << endl;
			//}
			return false;
		}
	}//?????????
	a[h - 1][w - 1] = '.';
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (a[i][j] == '#')return  false;
		}
	}

	//for (int i = 0; i < h; i++) {
		//for (int j = 0; j < w; j++) {
			//cout << a[i][j] << " ";
		//}
		//cout << endl;
	//}



	return true;

}




int main()
{
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> a[i][j];
		}
	}
	cout << (judge() ? "Possible" : "Impossible" )<< endl;

    return 0;
}