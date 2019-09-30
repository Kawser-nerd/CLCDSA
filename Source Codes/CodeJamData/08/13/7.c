/* Uses linux command line "bc" (binary calculator) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF 262144


int main() {
  int ncases, i, j, k, n;
  char res[MAX_BUF], buf[MAX_BUF], final[4];  
  FILE *f;
  
  scanf("%d", &ncases);
  for (i=1; i<=ncases; i++) {
    scanf("%d",&n);

    f = fopen("bc.in","w");
    fprintf(f,"scale=1000\n");
    fprintf(f,"(3+sqrt(5))^%d\n",n);
    fprintf(f,"quit\n");
    fclose(f);

    system("bc -l -q < bc.in > bc.out");

    res[0]=0;
    f = fopen("bc.out","r");
    while (1) {
      fgets(buf, MAX_BUF, f);      
      if (buf[strlen(buf)-2]!='\\') break;
      buf[strlen(buf)-2]=0;
      strcat(res,buf);
    }
    buf[strlen(buf)-1]=0;
    strcat(res,buf);

    final[4]=0;
    for (j=0;res[j] && res[j]!='.'; j++);
    for (j--, k=2; j>=0 && k>=0; j--, k--) final[k]=res[j];
    for (;k>=0;k--) final[k]='0';    
    printf("Case #%d: %s\n",i, final);
  }


  return 0;
}
