#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "bigint/BigIntegerLibrary.hh"

using namespace std;

BigInteger precalculated[46228]; 

BigInteger mypow(BigInteger x, BigInteger n){
	BigInteger current = 1;
	for (BigInteger i = 0; i < n; i++){
		current *= x;
	}
	return current;
}

BigInteger getDigits(BigInteger current){
	BigInteger digits = 1;
	while(true){
		current /= 10;
		if (current == 0){
			return digits;
		} 
		digits++;
	}
}

BigInteger getDigit(BigInteger current, BigInteger digit){
	return (current / mypow(10, (digit))) % 10;
}

bool isPalyndrome(BigInteger n){
	BigInteger nDigits = getDigits(n);
	for (BigInteger i = 0; i < nDigits/2; i++){
		if (getDigit(n, i) != getDigit(n, nDigits - i - 1)){
			return false;
		}
	}
	return true;
}

BigInteger solve(BigInteger A, BigInteger B){
	BigInteger count = 0;
	BigInteger current = 1;
	for (int i = 0; i < 46228; i++){
		BigInteger sqr = precalculated[i]*precalculated[i];
		if ((sqr >= A) && (sqr <= B)){
			count++;
		} else if (sqr > B){
			break;
		}
	}
	return count;
}

int main(){
	int T;
	cin >> T;
	ifstream file("allNumbers");
	for (int i = 0; i < 46228; i++){
		string str;
		file >> str;
		precalculated[i] = 0;
		for (int j = 0; j < str.size(); j++){
			precalculated[i] = precalculated[i] * 10 + (str[j] - '0');
		}
	}
	for (int i = 0; i < T; i++){
		BigInteger A, B;
		string Astr, Bstr;
		A = 0;
		B = 0;
		cin >> Astr >> Bstr;
		for (int j = 0; j < Astr.size(); j++){
			A = A * 10 + (Astr[j] - '0');
		}
		for (int j = 0; j < Bstr.size(); j++){
			B = B * 10 + (Bstr[j] - '0');
		}
		cout << "Case #" << (i + 1) << ": " << solve(A, B) << endl; 
	}
}
