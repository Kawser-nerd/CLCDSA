#include<stdio.h>

void main()
{
  int cases;

  char gridX[4][4];

  char gridO[4][4];

  char line[4];

  char c;

  int dotFound=0;

  int cs=1,l=0,m=0,xWin=0,oWin=0,q=0,idx=0;

  scanf("%d", &cases);

// printf("cases=%d......result = %d\n",cases, result);

  for( cs = cases; cs > 0; cs--) {
    idx++;
    //printf("%d %d %d", cs, cases, (cases - cs));
    xWin=0,oWin=0;

    dotFound = 0;
    xWin = 0;
    oWin = 0;

  for(l=0;l<4;l++) {
       //	printf("cases before = %d",cases);

	scanf("%s\n",&line);
	//printf("cases after = %d",cases);
	  for(m=0;m<4;m++){
		 c = line[m];
		 if(c == 'T') {
			gridX[l][m] = 'X';
			gridO[l][m] = 'O';
		 } else {
			 gridX[l][m]=c;
			 gridO[l][m]=c;
		 }

		 if(c == '.') {
			 dotFound = 1;
		 }
	   }
	}

    /* printf("GRID X \n");

    for(l=0;l<4;l++) {
	  for(m=0;m<4;m++){
	   printf("%c",gridX[l][m]);
	   }
	   printf("\n");
	}
	   printf("GRID O \n");

	   for(l=0;l<4;l++) {
	     for(m=0;m<4;m++){
	   printf("%c",gridO[l][m]);
	   }
	   printf("\n");
	} */

   for(q=0;q<4;q++)
   {
    if((gridX[q][0]=='X')&&(gridX[q][1]=='X')&&(gridX[q][2]=='X')&&(gridX[q][3]=='X'))
	  xWin = 1;
    else if((gridX[0][q]=='X')&&(gridX[1][q]=='X')&&(gridX[2][q]=='X')&&(gridX[3][q]=='X'))
      xWin = 1;
    else if((gridX[q][0]=='O')&&(gridX[q][1]=='O')&&(gridX[q][2]=='O')&&(gridX[q][3]=='O'))
	  oWin = 1;
    else if((gridX[0][q]=='O')&&(gridX[1][q]=='O')&&(gridX[2][q]=='O')&&(gridX[3][q]=='O'))
      oWin = 1;
  }

   if((gridX[0][0]=='X')&&(gridX[1][1]=='X')&&(gridX[2][2]=='X')&&(gridX[3][3]=='X'))
	  xWin = 1;
   else if((gridX[0][3]=='X')&&(gridX[1][2]=='X')&&(gridX[2][1]=='X')&&((gridX[3][0]=='X')))
	  xWin = 1;
   else if((gridO[0][0]=='O')&&(gridO[1][1]=='O')&&(gridO[2][2]=='O')&&(gridO[3][3]=='O'))
      oWin = 1;
   else if((gridO[0][3]=='O')&&(gridO[1][2]=='O')&&(gridO[2][1]=='O')&&((gridO[3][0]=='O')))
      oWin = 1;

   if(xWin == 1){
	   printf("Case #%d: X won\n",idx);
   } else if (oWin == 1)  {
	   printf("Case #%d: O won\n",idx);
   } else {
		if(dotFound == 1) {
			printf("Case #%d: Game has not completed\n",idx);
		} else {
			printf("Case #%d: Draw\n",idx);
		}
   }
   //cs++;
  }
}