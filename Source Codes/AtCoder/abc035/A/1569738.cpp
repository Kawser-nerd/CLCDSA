#include<iostream>
using namespace std;
int main()
{
	int W, H;
	cin >> W >> H;
	if (W % 16 != 0) cout << "4:3\n";
	else if(H % 4 == 0){
		for (int i = 0; i < 20; i++)
		{
			W = W / 4;
			H = H / 4;
			if (H % 4 != 0) break;
		}
		if (W % 16 == 0)cout << "16:9\n";
		else cout << "4:3\n";
	}
	else   cout << "16:9\n";

	return 0;
}