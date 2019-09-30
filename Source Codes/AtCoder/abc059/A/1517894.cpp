#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

int main()
{
	string s1,s2,s3,result;
	cin>>s1>>s2>>s3;

	result+=toupper(s1[0]);
	result+=toupper(s2[0]);
	result+=toupper(s3[0]);

	cout<<result<<endl;
	return 0;
}