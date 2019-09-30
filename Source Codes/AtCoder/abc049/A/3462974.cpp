#include <cstdio>

int main()
{	
	char C;

	scanf("%c",&C);
	if('a'<=C&&'z'>=C){
		if(C=='a'||C=='i'||C=='u'||C=='e'||C=='o'){
		printf("vowel");}
	else{
		printf("consonant");}}

	return 0;}