#include <stdio.h>
#include <string.h>
#define MAXD 100

int main(int argc, char *argv[]){
    FILE *fin,*fout;
    int tcase,T,y,x,minX,minY,maxX,maxY,R,counter,secs,i,X1,X2,Y1,Y2;
	char world[MAXD+1][MAXD+1];
    
    if (argc>1)
       fin=fopen(argv[1],"r");
    else
       fin=fopen("bact.in","r");
    if (!fin)
       return 1;
    if (argc>2)
       fout=fopen(argv[2],"w");
    else
       fout=fopen("bact.out","w");
    if (!fout){
       fclose(fin);
       return 1;
 	   }
    fscanf(fin,"%d",&T);
    for (tcase=1;tcase<=T;tcase++)
    {
       fscanf(fin,"%d",&R);
	   memset(world,0,sizeof(world));
	   counter = 0;
	   minX = minY = MAXD;
	   maxX = maxY = 1;
	   for(i=0;i<R;i++)
	   {
		   fscanf(fin,"%d",&X1);
		   fscanf(fin,"%d",&Y1);
		   fscanf(fin,"%d",&X2);
		   fscanf(fin,"%d",&Y2);
		   if(X1<minX)
			   minX = X1;
		   if(Y1<minY)
			   minY = Y1;
		   if(X2>maxX)
			   maxX = X2;
		   if(Y2>maxY)
			   maxY = Y2;
		   for(y=Y1;y<=Y2;y++)
			   for(x=X1;x<=X2;x++)
				   if(world[y][x]==0)
				   {
					   world[y][x]=1;
					   counter++;
				   }
	   }
	   secs=0;
	   while(counter)
	   {
		   for(y=maxY;y>=minY;y--)
			   for(x=maxX;x>=minX;x--)
				   if(world[y][x])
				   {
					   if(world[y-1][x]==0 && world[y][x-1]==0)
					   {
						   counter--;
						   world[y][x]=0;
					   }
				   }
				   else if(world[y-1][x] && world[y][x-1])
				   {
					   counter++;
					   world[y][x]=1;
				   }
		   secs++;
	   }
       fprintf(fout,"Case #%d: %d\r\n",tcase,secs);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
