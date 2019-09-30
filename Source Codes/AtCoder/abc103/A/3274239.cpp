#include <stdio.h>
#include <iostream>
using namespace std;
 
 int main()
 {
	 int a[3], i, c;
	 for(i=0; i<3; i++){
		 cin >> a[i];
	 }
	 if(a[2]<a[1])
	 swap(a[2], a[1]);
	 if(a[1]<a[0])
	 swap(a[1],a[0]);
	 if(a[2]<a[1])
	 swap(a[1],a[2]);
	 c=a[2]-a[0];
	 cout << c;
 }