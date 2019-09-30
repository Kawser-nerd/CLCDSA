#include <stdio.h>
#include <stdlib.h>





int main()
{
    FILE *fin,*fout;
    fin=fopen("A-large.in","r");
    fout=fopen("output.txt","w");
    int T,i,j,q,S[26],N,max=0,sum,r1,r2,x,k;
    char c,c1,c2;
    fscanf(fin,"%d",&T);
    for(q=1; q<=T; q++){
    sum=0;


        fscanf(fin,"%d",&N);
        for(i=0; i<N; i++){
            fscanf(fin,"%d",&S[i]);
        }
        fprintf(fout,"Case #%d: ",q);

        for(i=0; i<N; i++){
            sum+=S[i];
        }
        x=0;
        for(i=0; i<N; i++){
            if(S[i]) x++;
        }





        while(x>2){
        max=0;
        for(j=0;j<N; j++){
            if(S[j]>=S[max]) max=j;

        }
        c=65+max;
        S[max]--;
        fprintf(fout,"%c ",c);


        x=0;
        for(k=0; k<N; k++){
            if(S[k]>0) x++;
        }
        }


        for(i=0; i<N; i++){
            if(S[i]){ r1=i; break;}
        }

        for(i=r1+1; i<N; i++){
            if(S[i]){ r2=i; break;}
        }
        c1=r1+65;
        c2=r2+65;

        for(i=0; i<S[r2];i++) fprintf(fout,"%c%c ",c1,c2);


        fprintf(fout,"\n");





    }
    fclose(fin);
    fclose(fout);



    return 0;
}
