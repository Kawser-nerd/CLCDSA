#include <iostream>
#include <string>
using namespace std;

struct Mystruct
{
	int cnt = 0;
	string str;
};

int main() {
	int R, B;
	int num = 0;
	int flg = 0;
	int max = 0;
	Mystruct t[100];
	string tmp;

	cin >> R;
	for (int i = 0;i < R;i++) {
		cin >> tmp;

		//?T??
		flg = 0;
		for (int i = 0; i < num&&flg==0; i++)
		{
			if (tmp == t[i].str) {
				t[i].cnt++;
				flg = 1;
			}
		}
		//t???????
		if (flg == 0) {
			t[num].str = tmp;
			t[num].cnt = 1;
			num++;
		}
	}
	/*
	cout << "?z??" << endl;
	for (int i = 0;i < num;i++) {
		cout << t[i].str << ":" << t[i].cnt << endl;
	}
	cout << "?????" << endl;
	*/

	cin >> B;
	for (int i = 0;i < B;i++) {
		cin >> tmp;
		for (int i = 0;i < num;i++) {
			if (tmp == t[i].str) {
				t[i].cnt--;
			}
		}
	}
	/*
	cout << "?z??" << endl;
	for (int i = 0;i < num;i++) {
		cout << t[i].str << ":" << t[i].cnt << endl;
	}
	cout << "?????" << endl;
	*/

	for (int i = 0;i < num;i++) {
		if (max < t[i].cnt)
			max = t[i].cnt;
	}

	cout << max << endl;
	
	return 0;
}