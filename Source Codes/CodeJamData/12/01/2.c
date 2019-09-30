#include <stdio.h>
#include <stdlib.h>

int main() {
   int decode[26] = { 24, 7, 4, 18, 14, 2, 21, 23, 3, 20, 8, 6, 11, 1,
10, 17, 25, 19, 13, 22, 9, 15, 5, 12, 0, 16, };
   int num, i, j;
   char str[256];

   scanf("%d\n", &num);

   for(i=0; i<num; i++) {
      gets(str);
      for(j=0; str[j]; j++)
         if (str[j] >= 'a' && str[j] <= 'z') 
            str[j] = decode[str[j]-'a']+'a';

      printf("Case #%d: %s\n", i+1, str);
   }


   return 0;
}


