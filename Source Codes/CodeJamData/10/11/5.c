#include <stdio.h>

int search(int N,int K, char board[50][50], char symbol)
{
    int i,j,k;
    for (i=0;i<N;i++) 
      for (j=0;j<N;j++)
      {
          if (i+K<=N)
          {
            for (k=0;k<K;k++) if (board[i+k][j]!=symbol) break;
            if (k==K) return 1;
          }
          if (j+K<=N)
          {
            for (k=0;k<K;k++) if (board[i][j+k]!=symbol) break;
            if (k==K) return 1;
          }
          if (j+K<=N && i+K<=N)
          {
            for (k=0;k<K;k++) if (board[i+k][j+k]!=symbol) break;
            if (k==K) return 1;
          }
          if (j+K<=N && i-K>=-1)
          {
            for (k=0;k<K;k++) if (board[i-k][j+k]!=symbol) break;
            if (k==K) return 1;
          }
      }
    return 0;
}

int main(int argc, char **argv)
{
    FILE *fin;
    FILE *fout;
    
    char board[50][50];
    int T,Case;
    int N,K;
    int i,j,k;
    int red,blue;
    
    if (argc!=3) 
    {
      printf("Use: rotate input output\n");
      exit(1);            
    }
    
    fin=fopen(argv[1],"r");
    fout=fopen(argv[2],"w");
    
    fscanf(fin,"%d\n",&T);
    for (Case=1;Case<=T;Case++)
    {
      fscanf(fin,"%d %d\n",&N,&K);
      for (i=0;i<N;i++)
      {
        for (j=0;j<N;j++)
        {
          board[j][i]=fgetc(fin);
        }
        fgetc(fin); //\n
      }
      for (i=0;i<N;i++) //Gravity
      {
        j=N-1;
        for (k=N-1;k>=0;k--)
        {
            if (board[k][i]!='.')
            {
              board[j][i]=board[k][i];
              j--;
            }
        }
        for(;j>=0;j--) board[j][i]='.';
      }
/*      for (i=0;i<N;i++)
      {
        for (j=0;j<N;j++)
          fputc(board[i][j],stdout);
        printf("\n");
      }*/
      //check if red has k in a row:
      red=search(N,K,board,'R');
      blue=search(N,K,board,'B');
      if (red && blue)
        fprintf(fout,"Case #%d: Both\n",Case);
      if (!red && blue)
        fprintf(fout,"Case #%d: Blue\n",Case);
      if (red && !blue)
        fprintf(fout,"Case #%d: Red\n",Case);
      if (!red && !blue)
        fprintf(fout,"Case #%d: Neither\n",Case);
    }
    fclose(fin);
    fclose(fout);
    return 0;
    
}
