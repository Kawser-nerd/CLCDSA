#include<stdio.h>
int main()
{
    FILE *in,*ou;
    int i,T,N;
    long K,a[31];
    if((in=fopen("A-large.in","r"))==NULL)
    {
        printf("Can not open the file.");
        exit(0);
    }
    if((ou=fopen("SnapperChain.ou","w"))==NULL) 
    {
        printf("Can not open the file");
        exit(0);
    }
    a[0]=1;
    for(i=1;i<=30;i++) a[i]=a[i-1]*2;
    fscanf(in,"%d",&T);
    for(i=0;i<T;i++)
    {
        fscanf(in,"%d%d",&N,&K);
        fprintf(ou,"Case #%d: ",i+1);
        if((K+1)%a[N]==0) fprintf(ou,"ON\n");
        else fprintf(ou,"OFF\n");
    } 
    fclose(in);
    fclose(ou);
    getch();
    return 0;  
}
