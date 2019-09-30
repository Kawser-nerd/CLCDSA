#include<iostream>
using namespace std;

int main(){
	int H,W,h,w;
	cin>>H>>W>>h>>w;
	cout<<H*W-h*W-H*w+h*w<<endl;
}