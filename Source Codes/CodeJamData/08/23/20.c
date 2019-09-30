#include <stdio.h>

void moir(int K);
int table[1000000];

int main(int argc, char *argv[]){
    FILE *fin,*fout;
    int N,n,K,i,d,numask;
    
    if (argc>1)
       fin=fopen(argv[1],"r");
    else
       fin=fopen("mousetrap.in.txt","r");
    if (!fin)
       return 1;
    if (argc>2)
       fout=fopen(argv[2],"w");
    else
       fout=fopen("mousetrap.out0.txt","w");
    if (!fout){
       fclose(fin);
       return 1;
       }
    fscanf(fin,"%d\n",&N);
    for (n=1;n<=N;n++){
       fscanf(fin,"%d",&K);
       fscanf(fin,"%d",&numask);
       moir(K);
       fprintf(fout,"Case #%d:",n);
       for(i=0;i<numask;i++){
          fscanf(fin,"%d",&d);
          fprintf(fout," %d",table[d-1]);
          }
       fprintf(fout,"\n");
       /***************
       printf("numitems: %d\nnumstores: %d\ngas: %d\n",numitems,numstores,gas);
       getchar();
       ***************/
       }
       fclose(fin);
       fclose(fout);
       /*system("pause");*/
    return 0;
}

void moir(int K){
  int i,j,counter;
  for (i=0;i<K;i++)
    table[i]=0;
  for (i=1,j=-1;i<=K;i++){
    for (counter=0;counter<i;counter++){
       do
         j=(j+1)%K;
       while (table[j]);
       }
    table[j]=i;
    }
  return;
  }
