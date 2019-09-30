#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}


solve () {
    int i,j,k;
    int a,n;
    int* motes;
    scanf("%d %d\n", &a, &n);
    int opti = n;
    int op = 0;
    motes = malloc(n*sizeof(int));
    for(i = 0; i < n; i++){
      scanf("%d", &motes[i]);
    }


    if(a==1){
      printf("%d\n",n);
      return;
    }

    qsort(motes, n, sizeof(int), cmpfunc);
    
    j=0;
    while(j < n) {
      // we can eat the next mote
      if(a > motes[j]){
	a = a+motes[j];
      }
      else {
	// if we can eat the next mote by inserting a new mote that is a-1
	if (a + a - 1 > motes[j]){
	  a = a + a - 1 + motes[j];
	  op++;
	}

	// if we cannot eat the next mote
	else{
	  if(opti > op + n - j){
	    opti = op + n - j;
	  }
	  // we try to eat the next mote
	  while(a <= motes[j] ){
	    a = a + a - 1;
	    op++;
	  }
	  a = a + motes[j];  
	}
      }
      j++;
    }

    if(opti < op){
      printf("%d\n",opti);
    }
    else{
      printf("%d\n",op);
    }   
    
}


int main () {
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
    int t,i,j;
    scanf ("%d ", &t);
    for (i = 0; i < t; i++) {
      printf("Case #%d: ",i+1);
      solve ();
    }
    return 0;
}
