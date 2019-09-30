#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

void convert(int A[100][100] , int H , int W , int x , int y) {

	//cout << "(x , y )" << x << "," << y << endl << endl ;
	
	for (int i = y-1 ; i <= y+1; i++) {
		if (i >= H || 0 > i) continue;

		for (int j = x-1 ; j <= x+1 ; j++) {
			
			if (j >= W || 0 > j) continue;
			
			//cout << "(" << j << "," << i << ")" << "\t" << endl;
			A[j][i] = 0;
		}
		//cout << endl;
	}

}

void convert_B(int org_A[100][100], int A[100][100], int H, int W, int x, int y) {

	
	for (int i = y - 1; i <= y + 1; i++) {
		if (i >= H || 0 > i) continue;

		for (int j = x - 1; j <= x + 1; j++) {

			if (j >= W || 0 > j) continue;

			//cout << "(" << j << "," << i << ")" << "\t" << endl;
			if (org_A[j][i] == 1) A[x][y] = 1;
		}
		//cout << endl;
	}

}




int main(int argc, char ** argv) {

	int H = 0;
	int W = 0;
	cin >> H >> W;

	int A[100][100];
	int org_A[100][100];

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {

			A[i][j] = 0;
		}
	}

	
	for (int i = 0; i < H; i++) {
	
		string str;
		cin >> str;
		if (str.size() != W) {
			cout << "S : size ober" << endl;
			return -1;
		}
		
		for (int j = 0; j < W; j ++){
			 A[j][i] = str.substr(j , 1) == "#" ? 1 : 0;
			 // cout << str.substr(j , 1) << "\t";
		}
		// cout << endl;
	}


	// ???
	// cout << "H,W = " << H << "," << W << endl;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {

			// cout << A[j][i] << "\t";
			org_A[j][i] = A[j][i];
		}
		// cout << endl;
	}
	
	// cout << endl;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {

			if (org_A[j][i] == 0) {

				convert(A, H, W, j, i);
				//cout << "*";
			}
			//cout << org_A[j][i] << "\t";
		}
		//cout << endl;
	}

	//cout << "convert" << endl << endl;
	
	
	// ???
	int Ans[100][100];
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			Ans[j][i] = A[j][i];
			//cout << A[j][i] << "\t";
		}
		//cout << endl;
	}

	//cout << endl;


	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {

			if (Ans[j][i] == 0) {

				convert_B(Ans , A, H, W, j, i);
				//cout << "*";
			}
			//cout << Ans[j][i] << "\t";
		}
		//cout << endl;
	}
	

	//cout << endl;


	bool check = true;
	// ???
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			// cout << A[j][i] << "\t";
			if (A[j][i] != org_A[j][i]) check = false;
		}
		// cout << endl;
	}

	if (check) {
		cout << "possible" << endl;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				
				cout << ( (Ans[j][i] == 1) ? "#" : "." );
			}
			cout << endl;
		}
	}
	else {
		cout << "impossible" << endl;
	}

}