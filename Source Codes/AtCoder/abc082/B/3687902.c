#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int sl(const void *a,const void*b){
    return *(int*) a - *(int*) b;
}
int ls(const void *a,const void*b){
    return *(int*) b - *(int*) a;
}
int main(){
	char s[101],t[101];
	scanf("%s%s",s,t);
	int u[101],v[101],i;
	for(i=0;i<strlen(s);i++){
	    u[i]=(s[i]-'a');
	}
	qsort(u,strlen(s),sizeof(int),sl);
	
	for(i=0;i<strlen(t);i++){
	    v[i]=(t[i]-'a');
	}
	qsort(v,strlen(t),sizeof(int),ls);
	
	for(i=0;i<strlen(s)&&i<strlen(t);i++){
	    if(u[i]<v[i]){
	        printf("Yes");
	        return 0;
	    }
	}
	if(u[i-1]==v[i-1]&&(i-1)<strlen(t)&&(strlen(t)>strlen(s))){
	    printf("Yes");
	    return 0;
	}
	printf("No");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s%s",s,t);
  ^