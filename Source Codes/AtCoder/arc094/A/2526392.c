#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define Min(a,b) ((a)<(b)?(a):(b))

#define Max(a,b) ((a)>(b)?(a):(b))

#define ABS(a) ((a)>(0)?(a):-(a))

#define Rep(i,n) for(int (i)=0;(i)<(n);(i)++)

#define Rep2(i,bottom,ceiling) for(int (i)=(bottom);(i)<=(ceiling);(i)++)

int Str_cmpfunc (const void * a, const void * b) {
   return strcmp(*(const char**)a,*(const char**)b );
}

int Int_cmpfunc (const void * a, const void * b) {
   return *(const int*)a-*(const int*)b;
}

int Arrcmp(int *arr1,int *arr2,int len){
	Rep(i,len){
		if(arr1[i]>arr2[i]) return 1;
		if(arr1[i]<arr2[i]) return 0;
	}	
	return 0;
}

void SwapInt(int* v1,int* v2){
	char sw = *v1;
    *v1=*v2;
    *v2=sw;
}

void SwapChar(char* v1,char* v2){
    char sw = *v1;
    *v1=*v2;
    *v2=sw;
}

void SwapStr(char** str1,char** str2){
    char* sw = *str1;
    *str1=*str2;
    *str2=sw;
}

int main(){ 
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int s=a+b+c;
	if(a%2==b%2){
		if((a%2)==(c%2)){
			printf("%d",(3*Max(Max(a,b),c)-s)/2);
		}else{
			printf("%d",1+(3*Max(Max(a+1,b+1),c)-s-2)/2);
		}
	}else
	{
		if((b%2)==(c%2)){
			printf("%d",1+(3*Max(Max(c+1,b+1),a)-s-2)/2);	
		}else
		{
			printf("%d",1+(3*Max(Max(a+1,c+1),b)-s-2)/2);	
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:52:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&a,&b,&c);
  ^