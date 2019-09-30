#include <stdio.h>

#define DEBUG 0

int main(void){

  int N,counter,B[20];

  // ????i????
  int Money[21];

  // ????????
  int members[40];

  // N???
  scanf("%d", &N);

  // ????????
  int maximum = 0;

  // ???????(0????????)
  for(int i=1;i<N;i++){
    scanf("%d", &B[i]);

    if(maximum < B[i])
      maximum = B[i];
  }

  // Money??(??????????)????
  for(int i=0;i<sizeof(Money)/sizeof(Money[0]);i++){
    Money[i] = 1;
  }

  // ????i?????????B[j]???
  for(int i=maximum;i>0;i--){

    // ????????
    if(DEBUG) printf("\n--- %d ---\n", i);

    // ????????????????
    for(int j=0;j<sizeof(members)/sizeof(members[0]);j++) members[j]=0;

    // ????????
    counter=0;

    // ????????
    for(int j=0;j<N;j++){

      // ????????
      if(i==B[j]){

        // ??????????
        if(DEBUG) printf("%d, ", j+1);

        // ?????????????????
        members[counter] = Money[j+1];
        counter++;
      }

    }

    // ??????
    if(counter == 1) { //???1???
      if(DEBUG) printf("\nbuka: 1, Money[%d], members[0]=%d\n", i, members[0]);
      Money[i] = 2 * members[0] + 1;
    }else if(counter == 2){ // ???2???
      if(DEBUG) printf("\nbuka: 2, Money[%d], members[0]=%d, members[1]=%d\n", i, members[0], members[1]);
      Money[i] = members[0] + members[1] + 1;
    }else{ // ???3???
      if(DEBUG) printf("\nbuka: 3, Money[%d], ", i);

      // ?????????
      int max=members[0], min=members[0];
      for(int k=0;k<counter;k++){

        if(DEBUG) printf("members[%d]=%d\n", k, members[k]);

        if( members[k] >= max )
          max = members[k];

        if( members[k] <= min )
          min = members[k];

      }

      if(DEBUG) printf("max: %d, min: %d\n", max, min);
      Money[i] = max + min + 1;
    }

    if(DEBUG) printf("Money[%d]=%d\n", i, Money[i]);
    else if(i==1) printf("%d\n", Money[i]);

  }

} ./Main.c: In function ‘main’:
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:23:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &B[i]);
     ^