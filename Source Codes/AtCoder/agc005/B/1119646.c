#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 int A[200001];
 long long int L[200001];  //first smallest index in left;
 long long int R[200001]; //first smallest index in right; 
 int stack[200001];
 long long int C[200001];
 int sp=0;

 void push(int x) {
 	stack[sp] = x;
 	sp ++;
 }

 void pop() {
 	sp--;
 }
 int empty(){
    if(sp==0)
    	return 1;
    	return 0;
 }
 int top(){
 	return stack[sp-1];
 }


int main() {
     int n,i;
     long long int ans=0;
     scanf("%d",&n);

     for(i=0;i<n;i++)
     	scanf("%d",&A[i]);
     
     for(i=0;i<n;i++) {
     	while(sp>0 && A[top()] > A[i]) {
     		pop();
     	}
     	if(empty())
     		L[i] = -1;
     	else
     		L[i] = top();
     	push(i);
     	
     }
     sp = 0;
     for(i=n-1 ;i>=0; i--){
     	while(sp>0 && A[top()] > A[i]) {
     		pop();
     	}
     	if(!empty())
     		R[i] = top();

     	else
     		R[i] = n;
     	push(i);
     }
     for(i=0;i<n;i++) {
     	C[i] = (i-L[i])*(R[i]-i);
     	ans = ans+C[i]*A[i];
     }
     printf("%lld\n",ans);


	return 0;
} ./Main.c: In function ‘main’:
./Main.c:32:6: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
      scanf("%d",&n);
      ^
./Main.c:35:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d",&A[i]);
       ^