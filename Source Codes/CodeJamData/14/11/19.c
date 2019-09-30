#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

#define NAX 10
#define LAX 10

int Com(int *A,int *B,int n)
{
	int i;
	for(i=0;i<n;i++)
		if(A[i]!=B[i]) return(0);
	return(1);
}

void Rout(int *A,int *B,int *C,int n)
{
	int i;
	for(i=0;i<n;i++)
		C[i]=(A[i]!=B[i]);
}

int count(int *C,int n)
{
	int i,k;
	for(i=0,k=0;i<n;i++)
		k+=(C[i]==1);
	return(k);
}

int main()
{
	int i,j,l,k,Nsam,N,L,a,b,c,d,e;
	char ch;
	int **FL,**DV,*Op,*A;
	FILE *fp1,*fp2;
	if ((fp1=fopen("A-large.txt", "r")) ==NULL)                                        
	{
		printf("Error opening file\n");
		exit(1); 
	}
	if ((fp2=fopen("out.txt", "w+")) ==NULL)            
    {
		printf("Error opening file\n");
		exit(1); 
    }
	fscanf(fp1,"%d",&Nsam);
	for(k=0;k<Nsam;k++)
	{
		fscanf(fp1,"%d",&N);
		fscanf(fp1,"%d",&L);
		Op=(int *)malloc(L*sizeof(int));
		A=(int *)malloc(L*sizeof(int));
		FL=(int **)malloc(N*sizeof(int *));
		for(i=0;i<N;i++)
			FL[i]=(int *)malloc(L*sizeof(int));
		DV=(int **)malloc(N*sizeof(int *));
		for(i=0;i<N;i++)
			DV[i]=(int *)malloc(L*sizeof(int));
		for(i=0;i<N;i++)
		{
			ch=fgetc(fp1);
			for(j=0;j<L;j++)
			{
				ch=fgetc(fp1);
				FL[i][j]= (ch=='1');
			}
		}
		for(i=0;i<N;i++)
		{
			ch=fgetc(fp1);
			for(j=0;j<L;j++)
			{
				ch=fgetc(fp1);
				DV[i][j]= (ch=='1');
			}
		}
		d=L;
		for(i=0,c=0;i<N;i++)
		{
			Rout(DV[0],FL[i],Op,L);
			for(j=1,a=0;j<N&&a==0;j++)
			{
				for(l=0,b=0;l<N&&b==0;l++)
				{
					Rout(FL[l],Op,A,L);
					b=Com(A,DV[j],L);
				}
				if(b==0) a=1;
			}
			if(a==0) 
			{
				c=1;
				e=count(Op,L);
				//if(e>L/2) e= L-e;
				if(e<d) d=e;
			}
				
		}
		if(c==0) fprintf(fp2,"Case #%d: NOT POSSIBLE\n",k+1);
		else fprintf(fp2,"Case #%d: %d\n",k+1,d);
		printf("%d:%d,%d\n",k+1,N,L);
		for(i=0;i<N;i++)
		{
			for(j=0;j<L;j++)
				printf("%d",FL[i][j]);
			printf(" ");
		}
		printf("\n");
		for(i=0;i<N;i++)
		{
			for(j=0;j<L;j++)
				printf("%d",DV[i][j]);
			printf(" ");
		}
		printf("\n");
		free(Op);
		free(A);
		for(i=0;i<N;i++)
		{
			free(FL[i]);
			free(DV[i]);
		}
		free(FL);
		free(DV);
	}
	getchar();

		
}
