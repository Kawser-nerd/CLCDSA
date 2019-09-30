#include <iostream>
using namespace std;

int main()
{
	int rows, columns;
	cin >> rows >> columns;
	int **HW;
	HW = new int * [rows];
	for (int i = 0; i < rows; i++) {
		HW[i] = new int[columns];
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			HW[i][j] = 0;
		}
	}
	//?????

	int Num;
	cin >> Num;
	int *a;
	a = new int[Num];
	for (int i = 0; i < Num; i++) {
		cin >> a[i];
	}
	int var = 0; int x = -1, y = 0;
	for (int i = 0; i < Num; i++) {
		for (int j = 0; j < a[i]; j++) {
			if (var == 0) {
				x++;
				if (x < columns && HW[y][x] == 0) {
					HW[y][x] = i + 1;
				}
				else {
					x--; j--; var++;
				}
			}else if (var == 1) {
				y++;
				if (y < rows && HW[y][x] == 0) {
					HW[y][x] = i + 1;
				}
				else {
					y--; j--; var++;
				}
			}else if (var == 2) {
				x--;
				if (x >= 0 && HW[y][x] == 0) {
					HW[y][x] = i + 1;
				}
				else {
					x++; j--; var++;
				}
			}else if(var == 3) {
				y--;
				if (y >= 0 && HW[y][x] == 0) {
					HW[y][x] = i + 1;
				}
				else {
					y++; j--; var = 0;
				}
			}
		}
	}
	//?????
	for (int i = 0; i < rows; i++) {
		cout << HW[i][0];
		for (int j = 1; j < columns; j++) {
			cout << " " << HW[i][j];
		}
		cout << endl;
	}
    return 0;
}